#ifndef CodeCallBack_H
#define CodeCallBack_H

namespace Legend {
	namespace CodeCallBack {


		void DoCallBack(uintptr_t a1, uintptr_t a2, int a3, int a4, uintptr_t a5, uintptr_t a6, uintptr_t a7) {
			using fn = void(*)(uintptr_t, uintptr_t, int, int, uintptr_t, uintptr_t, uintptr_t);
			auto call = *reinterpret_cast<fn*>(Utils::process + Offsets::Functions::CodeCallBackFunc);
			call(a1, a2, a3, a4, a5, a6, a7);
		}
	}
}


#endif