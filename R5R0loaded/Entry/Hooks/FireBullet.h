#ifndef FireBullet_H
#define FireBullet_H

namespace Legend {
    namespace Hook {

        uintptr_t(*oFireWeaponBolt)(
            uintptr_t weapon,           // a1 - Weapon entity
            float* startPos,            // a2 - Start position (x, y, z)
            float* direction,           // a3 - Direction vector (x, y, z)
            float speed,                // a4 - Projectile speed
            char applyGravity,          // a5 - Apply gravity flag
            int damageValue,            // a6 - Damage value
            int damageType,             // a7 - Damage type
            unsigned char unknown1,     // a8 - Unknown flag
            int seed,                   // a9 - Random seed
            char applySpread,           // a10 - Apply spread flag (1 = yes)
            int unknown2                // a11 - Unknown
            ) = nullptr;

        struct Vector3 {
            float x, y, z;
        };

        uintptr_t hkFireWeaponBolt(
            uintptr_t weapon,
            float* startPos,
            float* direction,
            float speed,
            char applyGravity,
            int damageValue,
            int damageType,
            unsigned char unknown1,
            int seed,
            char applySpread,
            int unknown2)
        {
            applyGravity = 0;


            std::vector<uintptr_t> player_list;
            {
                std::lock_guard<std::mutex> lock(SDK::listMTX);
                player_list = SDK::player_list;
            }

            for (const auto& ent : player_list) {

                Vector3 position = *(Vector3*)(ent + 0x14C);

                position.z += 50.0f; 

                float targetDir[3];
                targetDir[0] = position.x - startPos[0];
                targetDir[1] = position.y - startPos[1];
                targetDir[2] = position.z - startPos[2];

                float length = sqrtf(
                    targetDir[0] * targetDir[0] +
                    targetDir[1] * targetDir[1] +
                    targetDir[2] * targetDir[2]
                );

                if (length > 0.0f) {
                    targetDir[0] /= length;
                    targetDir[1] /= length;
                    targetDir[2] /= length;

                    float targetSpawn[3] = { position.x, position.y, position.z };

                    for (int i = 0; i <= 5; i++) {
                        oFireWeaponBolt(
                            weapon,
                            targetSpawn,
                            targetDir,
                            speed,
                            applyGravity,
                            damageValue,
                            damageType,
                            unknown1,
                            seed,
                            0,
                            unknown2
                        );
                   }

                
                }
            }

            return oFireWeaponBolt(
                weapon,
                startPos,
                direction,
                speed,
                applyGravity,
                damageValue,
                damageType,
                unknown1,
                seed,
                applySpread,
                unknown2
            );
        }
    }
}

#endif