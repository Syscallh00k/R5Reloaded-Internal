#ifndef CallBack_H
#define CallBack_H

namespace Legend {
	namespace Hook {
        using CallBack_T = __int64(__fastcall*)(uintptr_t a1, uintptr_t a2, uintptr_t a3);
        CallBack_T CallBack_original = nullptr;

        __int64 __fastcall CallBackHook(uintptr_t a1, uintptr_t a2, uintptr_t a3) {
           // printf("a1=%p a2=%p a3=%p ret %p\n", a1, a2, a3);
           
           
            return CallBack_original(a1, a2, a3);
            

        }

	}
}

#endif