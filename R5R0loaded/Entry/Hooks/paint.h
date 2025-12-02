#ifndef Paint_H
#define Paint_H

#include <cmath>

namespace Legend {
    namespace Hook {

        using Paint_t = __int64(__fastcall*)(uintptr_t a1);
        Paint_t Paint_original = nullptr;

        struct BaseMatrix
        {
            float at[16]{};

        };


		struct Vector2 {
		public:
			float x, y;
            Vector2(float _x, float _y) {
                this->x = _x;
                this->y = _y;
            }
		};


        bool world_to_screen(
            const Vector3& in,
            Vector2& out,
            const Vector2& screenSize)
        {
            const auto view_renderer = *reinterpret_cast<uintptr_t*>(Utils::process + 0xd4138f0);
            if (!view_renderer)
                return false;

            const auto view_matrix_temp = *reinterpret_cast<uintptr_t*>(view_renderer + 0x1a93d0);
            if (!view_matrix_temp)
                return false;

            const auto view_matrix = *reinterpret_cast<BaseMatrix*>(view_matrix_temp);
            const auto matrix = view_matrix.at;

            const float w = matrix[12] * in.x + matrix[13] * in.y + matrix[14] * in.z + matrix[15];
            if (w < 0.001f)
                return false;

            out.x = matrix[0] * in.x + matrix[1] * in.y + matrix[2] * in.z + matrix[3];
            out.y = matrix[4] * in.x + matrix[5] * in.y + matrix[6] * in.z + matrix[7];

            out.x /= w;
            out.y /= w;

            out.x = (screenSize.x / 2.0f) + (out.x * screenSize.x) / 2.0f;
            out.y = (screenSize.y / 2.0f) - (out.y * screenSize.y) / 2.0f;

            out.x = std::trunc(out.x);
            out.y = std::trunc(out.y);

           
            return true;
        }


        __int64 __fastcall PaintHook(uintptr_t a1) {
            uintptr_t _surface = (Utils::process + Offsets::Functions::surface);
            auto start_drawing = *reinterpret_cast<void(*)(uintptr_t)>(Utils::process + Offsets::Functions::StartDrawing);
            auto end_drawing = *reinterpret_cast<void(*)(uintptr_t)>(Utils::process + Offsets::Functions::EndDrawing);
            start_drawing((uintptr_t)_surface);

            Surface* rend = (Surface*)_surface;

            //fov
            *(float*)(SDK::local_player + 16464) = 1.3f;
            *(float*)(SDK::local_player + 16472) = 1.3f;
            *(float*)(SDK::local_player + 16472) = 1.3f;

            auto font = rend->GetFont();
            rend->DrawColoredText(font, 20.0f, 25, 25, 255, 0, 155, 255, "L3g3n9 :)");
            rend->DrawColoredText(font, 20.0f, 25, 45, 255, 0, 155, 255, "list size %d", SDK::player_list.size());

            int screen_x;
            int screen_y;

            rend->GetScreenSize(screen_x, screen_y);

            if (GetAsyncKeyState(VK_UP)) {
                using GetScriptEntity_t = uintptr_t(__fastcall*)(__int64* a1, unsigned int* a2, char a3, int a4);
                auto InvokeCallback =
                    reinterpret_cast<GetScriptEntity_t>(Utils::process + 0x771DF0);
            }
			std::vector<uintptr_t> player_list;
			std::lock_guard<std::mutex> lock(SDK::listMTX);
			player_list = SDK::player_list;

			for (const auto& ent : player_list) {
                Offsets::Global::C_Player* player = (Offsets::Global::C_Player*)ent;
				Vector3 position = *(Vector3*)(ent + 0x14C);
                Vector2 screen(0,0);
                if (world_to_screen(position, screen, Vector2((float)screen_x, (float)screen_y))) {
                    rend->DrawColoredText(font, 20.0f, screen.x, screen.y, 0, 155, 255, 255, "jew");
                }
			}

            end_drawing((uintptr_t)_surface);
            return Paint_original((uintptr_t)a1);
        }
    }
}

#endif