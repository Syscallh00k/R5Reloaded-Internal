#ifndef FreeFall_H
#define FreeFall_H
namespace Legend {
    namespace Hook {
        using FreeFall_t = void(__fastcall*)(uintptr_t player);
        FreeFall_t FreeFall_original = nullptr;

        void __fastcall FreeFallHook(uintptr_t player) {

            if (!player) {
                return FreeFall_original(player);
            }
            
            return FreeFall_original(player);
        }
    }
}
#endif

