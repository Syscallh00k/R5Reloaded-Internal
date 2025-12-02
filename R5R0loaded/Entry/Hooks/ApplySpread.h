#ifndef ApplySpread_H
#define ApplySpread_H

namespace Legend {
    namespace Hook {
        using ApplySpread_T = float* (__fastcall*)(float* a1, float* a2, float a3);
        ApplySpread_T ApplySpread_original = nullptr;

        float* __fastcall ApplySpreadHook(float* a1, float* a2, float a3) {

         
            return ApplySpread_original(a1, a2, 0);
        }
    }
}

#endif