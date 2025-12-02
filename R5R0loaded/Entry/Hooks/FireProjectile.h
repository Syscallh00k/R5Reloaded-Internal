#ifndef FireProjectile_H
#define FireProjectile_H
namespace Legend {
    namespace Hook {
        using FireProjectile_t = __int64(__fastcall*)(uintptr_t a1, uintptr_t a2);
        FireProjectile_t FireProjectile_original = nullptr;

        struct ProjectileInfo {
            char pad_0[8];
            int fire_mode;
            float origin[3];
            float direction[3];
            char pad_36[4];
            int damage_scale;
            char pad_44[4];
            unsigned char flags;
        };

        __int64 __fastcall FireProjectileHook(uintptr_t weapon, uintptr_t a2) {
            ProjectileInfo* projInfo = reinterpret_cast<ProjectileInfo*>(a2);

            std::vector<uintptr_t> player_list;
            {
                std::lock_guard<std::mutex> lock(SDK::listMTX);
                player_list = SDK::player_list;
            }

            for (const auto& ent : player_list) {
                Vector3 position = *(Vector3*)(ent + 0x14C);
                position.z += 50.0f;

                float targetDir[3];
                targetDir[0] = position.x - projInfo->origin[0];
                targetDir[1] = position.y - projInfo->origin[1];
                targetDir[2] = position.z - projInfo->origin[2];

                float length = sqrtf(
                    targetDir[0] * targetDir[0] +
                    targetDir[1] * targetDir[1] +
                    targetDir[2] * targetDir[2]
                );

                if (length > 0.0f) {
                    targetDir[0] /= length;
                    targetDir[1] /= length;
                    targetDir[2] /= length;

                    ProjectileInfo modifiedProj = *projInfo;
                    modifiedProj.origin[0] = position.x;
                    modifiedProj.origin[1] = position.y;
                    modifiedProj.origin[2] = position.z;
                    modifiedProj.direction[0] = targetDir[0];
                    modifiedProj.direction[1] = targetDir[1];
                    modifiedProj.direction[2] = targetDir[2];

                    for (int i = 0; i < 5; i++) {
                        FireProjectile_original(weapon, reinterpret_cast<uintptr_t>(&modifiedProj));
                    }
                }
            }

            return FireProjectile_original(weapon, a2);
        }
    }
}
#endif