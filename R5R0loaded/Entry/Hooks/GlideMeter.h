#ifndef FreeFall_H
#define FreeFall_H
namespace Legend {
    namespace Hook {
        using FreeFall_t = void(__fastcall*)(uintptr_t player);
        FreeFall_t FreeFall_original = nullptr;

        void __fastcall FreeFallHook(uintptr_t player) {
            // Check if player is valid
            if (!player) {
                return FreeFall_original(player);
            }

            // Get local player for comparison

            // Only force freefall animation for other players (server-side effect)
                // Force freefall state to active
                *reinterpret_cast<int*>(player + 10392) = 2;  // Freefall active state

                // Set freefall start time to current time
                float currentTime = *reinterpret_cast<float*>(Utils::process + 0x171F448 + 16);
                *reinterpret_cast<float*>(player + 10408) = currentTime;

                // Keep freefall end time in the future
                *reinterpret_cast<float*>(player + 10400) = currentTime + 9999.0f;
            

            // Call original to handle callbacks
            return FreeFall_original(player);
        }
    }
}
#endif

