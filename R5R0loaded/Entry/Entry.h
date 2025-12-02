#ifndef Entry_H
#define Entry_H

#include "../sdk/sdk.h"

#include "Hooks/CallBack.h"
#include "Hooks/ApplySpread.h"
#include "Hooks/FireBullet.h"
#include "Hooks/paint.h"
#include "Hooks/FireProjectile.h"
#include "Hooks/GlideMeter.h"

namespace Legend {
	namespace Entry {
		auto CreateHooks() -> void {
			MH_Initialize();

			MH_CreateHook((LPVOID)(Utils::process + Offsets::Functions::CodeCallBackFunc), &Hook::CallBackHook, reinterpret_cast<void**>(&Hook::CallBack_original));
			MH_CreateHook((LPVOID)(Utils::process + Offsets::Functions::ApplySpread), &Hook::ApplySpreadHook, reinterpret_cast<void**>(&Hook::ApplySpread_original));
			MH_CreateHook((LPVOID)(Utils::process + Offsets::Functions::FireBullet), &Hook::hkFireWeaponBolt, reinterpret_cast<void**>(&Hook::oFireWeaponBolt));
			MH_CreateHook((LPVOID)(Utils::process + Offsets::Functions::paint), &Hook::PaintHook, reinterpret_cast<void**>(&Hook::Paint_original));
			MH_CreateHook((LPVOID)(Utils::process + Offsets::Functions::FireProjectile), &Hook::FireProjectileHook, reinterpret_cast<void**>(&Hook::FireProjectile_original));
			MH_CreateHook(
				reinterpret_cast<LPVOID>(Utils::process + 0x870D70),
				&Legend::Hook::FreeFallHook,
				reinterpret_cast<LPVOID*>(&Legend::Hook::FreeFall_original)
			);
			MH_EnableHook(MH_ALL_HOOKS);
			printf("placed hook\n");
		}

		auto MainThread() -> void {
			while (true) {
				SDK::local_player = *(uintptr_t*)(Utils::process + Offsets::Global::dwLocalPlayer);
				uintptr_t EntityList = (Utils::process + Offsets::Global::dwEntityList);

				std::vector<uintptr_t> temp_list;
				for (int i = 0; i <= 30000; i++) {
					uintptr_t* vtable = *(uintptr_t**)EntityList;

					uintptr_t functionAddress = vtable[4];

					using GetClientEntityFn = uintptr_t(__thiscall*)(uintptr_t, int);
					auto GetClientEntity = reinterpret_cast<GetClientEntityFn>(functionAddress);

					uintptr_t pEntity = GetClientEntity(EntityList, i);
					if (!pEntity || pEntity == SDK::local_player)continue;

					const char* type_name = *(const char**)(pEntity + 0x0518);
					if (!type_name)continue;

					if (strcmp(type_name, "player") != 0 && strcmp(type_name, "npc_dummie") != 0)
						continue;

					temp_list.push_back(pEntity);
				}

				std::lock_guard<std::mutex> lock(SDK::listMTX);
				SDK::player_list.swap(temp_list);
			}
		}
	}
}


#endif