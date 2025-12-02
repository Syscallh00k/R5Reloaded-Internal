#include "Entry\Entry.h"

DWORD WINAPI MainThread(LPVOID lpReserved) {

    Legend::Utils::process = (uintptr_t)GetModuleHandle(NULL);
    Legend::Utils::gamesdk = (uintptr_t)GetModuleHandle("gamesdk.dll");
    printf("process image %p\n", Legend::Utils::process);
    Legend::Entry::CreateHooks();
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Legend::Entry::MainThread, 0, 0, 0);
  
    return 1;
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        AllocConsole();
        freopen_s(reinterpret_cast<FILE**>(stdin), ("CONIN$"), ("r"), stdin);
        freopen_s(reinterpret_cast<FILE**>(stdout), ("CONOUT$"), ("w"), stdout);
        printf("dll loaded\n");
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainThread, lpReserved, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

