#ifndef MEMORY_H
#define MEMORY_H

typedef struct _IMAGE_DOS_HEADERS {      // DOS .EXE header
	WORD   e_magic;                     // Magic number
	WORD   e_cblp;                      // Bytes on last page of file
	WORD   e_cp;                        // Pages in file
	WORD   e_crlc;                      // Relocations
	WORD   e_cparhdr;                   // Size of header in paragraphs
	WORD   e_minalloc;                  // Minimum extra paragraphs needed
	WORD   e_maxalloc;                  // Maximum extra paragraphs needed
	WORD   e_ss;                        // Initial (relative) SS value
	WORD   e_sp;                        // Initial SP value
	WORD   e_csum;                      // Checksum
	WORD   e_ip;                        // Initial IP value
	WORD   e_cs;                        // Initial (relative) CS value
	WORD   e_lfarlc;                    // File address of relocation table
	WORD   e_ovno;                      // Overlay number
	WORD   e_res[4];                    // Reserved words
	WORD   e_oemid;                     // OEM identifier (for e_oeminfo)
	WORD   e_oeminfo;                   // OEM information; e_oemid specific
	WORD   e_res2[10];                  // Reserved words
	LONG   e_lfanew;                    // File address of new exe header
} IMAGE_DOS_HEADERS, * PIMAGE_DOS_HEADERS;

namespace Legend {
	namespace Memory {

		bool IsValid(uintptr_t address) {
			if (IsBadReadPtr((void*)address, sizeof(uintptr_t)) || address <= 0xFFFFF || address >= 0xFFFFFFFFFFFFFF)
				return false;

			return true;
		}

		template <typename T>
		inline T Read(std::uintptr_t address) {
			if (!IsValid(address))
				return T();

			return *(T*)(address);
		}

		void DumpVTable(void* obj, size_t count = 32) {
			printf(("DumpVTable for obj=%p\n"), obj);
			uintptr_t* vtab = nullptr;
			__try { vtab = *reinterpret_cast<uintptr_t**>(obj); }
			__except (EXCEPTION_EXECUTE_HANDLER) {
				printf(("Failed to read vptr\n"));
				return;
			}
			printf("vtable = %p\n", (void*)vtab);
			for (size_t i = 0; i < count; i++) {
				uintptr_t entry = 0;
				__try { entry = vtab[i]; }
				__except (EXCEPTION_EXECUTE_HANDLER) {
					printf(("vtable[%zu] read exception\n"), i);
					break;
				}
				MEMORY_BASIC_INFORMATION mbi;
				VirtualQuery((void*)entry, &mbi, sizeof(mbi));
				printf(("[%02zu] %p  module=%p  prot=0x%x\n"), i, (void*)entry, mbi.AllocationBase, mbi.Protect);
			}
		}
		template<typename T>
		static bool SafeRead(uintptr_t addr, T& out)
		{
			SIZE_T bytesRead = 0;
			return ReadProcessMemory(GetCurrentProcess(), (LPCVOID)addr, &out, sizeof(T), &bytesRead) && bytesRead == sizeof(T);
		}

		uintptr_t sig_scan(uintptr_t module, const char* pattern)
		{
			static auto patternToByte = [](const char* pattern)
				{
					auto       bytes = std::vector<int>{};
					const auto start = const_cast<char*>(pattern);
					const auto end = const_cast<char*>(pattern) + strlen(pattern);

					for (auto current = start; current < end; ++current)
					{
						if (*current == '?')
						{
							++current;
							if (*current == '?')
								++current;
							bytes.push_back(-1);
						}
						else { bytes.push_back(strtoul(current, &current, 16)); }
					}
					return bytes;
				};

			const auto dosHeader = (PIMAGE_DOS_HEADERS)module;
			const auto ntHeaders = (PIMAGE_NT_HEADERS)((std::uint8_t*)module + dosHeader->e_lfanew);

			const auto sizeOfImage = ntHeaders->OptionalHeader.SizeOfImage;
			auto       patternBytes = patternToByte(pattern);
			const auto scanBytes = reinterpret_cast<std::uint8_t*>(module);

			const auto s = patternBytes.size();
			const auto d = patternBytes.data();

			for (auto i = 0ul; i < sizeOfImage - s; ++i)
			{
				bool found = true;
				for (auto j = 0ul; j < s; ++j)
				{
					if (scanBytes[i + j] != d[j] && d[j] != -1)
					{
						found = false;
						break;
					}
				}
				if (found) { return reinterpret_cast<uintptr_t>(&scanBytes[i]); }
			}
			return NULL;
		}
		static bool ReadStringSafe(uintptr_t addr, std::string& out, size_t maxLen = 512) {
			out.clear();
			if (!addr) return false;
			for (size_t i = 0; i < maxLen; ++i) {
				uint8_t c = 0;
				if (!Memory::SafeRead<uint8_t>(addr + i, c)) {
					return false;
				}
				if (c == 0) {
					return true;
				}
				out.push_back(static_cast<char>(c));
			}
			return false;
		}
		template<typename Fn, typename... Args>
		auto CallVFunc(size_t index, uintptr_t thiz, Args... args) {
			if (!thiz) {
				using Ret = std::invoke_result_t<Fn, uintptr_t, Args...>;
				if constexpr (!std::is_void_v<Ret>)
					return Ret{};
				else
					return;
			}

			auto vtable = *reinterpret_cast<uintptr_t**>(thiz);
			if (!vtable) {
				using Ret = std::invoke_result_t<Fn, uintptr_t, Args...>;
				if constexpr (!std::is_void_v<Ret>)
					return Ret{};
				else
					return;
			}
			auto func = reinterpret_cast<Fn>(vtable[index]);
			if (!func) {
				using Ret = std::invoke_result_t<Fn, uintptr_t, Args...>;
				if constexpr (!std::is_void_v<Ret>)
					return Ret{};
				else
					return;
			}

			return func((uintptr_t)thiz, args...);
		}
		size_t ComputeHash(const char* data, size_t size)
		{
			size_t hash = 0;
			for (size_t i = 0; i < size; ++i)
			{
				hash = hash * 31 + static_cast<unsigned char>(data[i]);
			}
			return hash;
		}
	}

}

#endif