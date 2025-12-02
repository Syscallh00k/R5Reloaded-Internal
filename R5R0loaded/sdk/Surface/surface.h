#ifndef Surface_H
#define Surface_H

namespace Legend {
	class Surface {
	public:
		void SetColor(int r, int g, int b, int a) {
			using Fn = void(__fastcall*)(uintptr_t, int, int, int, int);
			Memory::CallVFunc<Fn>(14, (uintptr_t)this, r, g, b, a);
		}

		void DrawFilledRect(int x0, int y0, int x1, int y1) {
			using Fn = void(__fastcall*)(uintptr_t, int, int, int, int);
			Memory::CallVFunc<Fn>(16, (uintptr_t)this, x0, y0, x1, y1);
		}

		void DrawOutlinedRect(int x0, int y0, int x1, int y1) {
			using Fn = void(__fastcall*)(uintptr_t, int, int, int, int);
			Memory::CallVFunc<Fn>(19, (uintptr_t)this, x0, y0, x1, y1);
		}

		void DrawLine(int x0, int y0, int x1, int y1) {
			using Fn = void(__fastcall*)(uintptr_t, int, int, int, int);
			Memory::CallVFunc<Fn>(20, (uintptr_t)this, x0, y0, x1, y1);
		}

		void GetScreenSize(int& wide, int& tall) {
			using Fn = void(__fastcall*)(uintptr_t, int*, int*);
			Memory::CallVFunc<Fn>(53, (uintptr_t)this, &wide, &tall);
		}

		unsigned long GetFont() {
			using Fn = unsigned long(__fastcall*)(uintptr_t);
			return Memory::CallVFunc<Fn>(163, (uintptr_t)this);
		}

		template <typename... Args>
		void DrawColoredText(unsigned long font, int fontHeight, int x, int y,
			int r, int g, int b, int a, const char* fmt, Args... args)
		{
			using Fn = void(__fastcall*)(uintptr_t, unsigned long, int, int, int, int, int, int, int, const char*, Args...);
			Memory::CallVFunc<Fn>(200, (uintptr_t)this, font, fontHeight, x, y, r, g, b, a, fmt, args...);
		}

		void DrawBox(int x, int y, int w, int h, int r, int g, int b, int a, bool filled = true) {
			SetColor(r, g, b, a);
			if (filled) {
				DrawFilledRect(x, y, x + w, y + h);
			}
			else {
				DrawOutlinedRect(x, y, x + w, y + h);
			}
		}

		void DrawT3xt(int x, int y, int r, int g, int b, int a, const char* text) {
			unsigned long font = GetFont();
			DrawColoredText(font, 14, x, y, r, g, b, a, text);
		}

		void DrawCrosshair(int centerX, int centerY, int size, int r, int g, int b, int a) {
			SetColor(r, g, b, a);
			DrawLine(centerX - size, centerY, centerX + size, centerY);
			DrawLine(centerX, centerY - size, centerX, centerY + size);
		}

		void DrawCircle(int centerX, int centerY, int radius, int segments, int r, int g, int b, int a) {
			SetColor(r, g, b, a);
			float angleStep = 6.28318f / segments;

			for (int i = 0; i < segments; i++) {
				float angle1 = i * angleStep;
				float angle2 = (i + 1) * angleStep;

				int x1 = centerX + (int)(radius * cosf(angle1));
				int y1 = centerY + (int)(radius * sinf(angle1));
				int x2 = centerX + (int)(radius * cosf(angle2));
				int y2 = centerY + (int)(radius * sinf(angle2));

				DrawLine(x1, y1, x2, y2);
			}
		}
	};
}

#endif // Surface_H