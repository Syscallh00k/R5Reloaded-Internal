#ifndef Offsets_H
#define Offsets_H

namespace Legend {
	namespace Offsets {
		namespace Functions {
			uintptr_t CodeCallBackFunc = 0xC40FC0;
			uintptr_t ClientCodeCallback_UseConsumable = 0x17226E8;
			uintptr_t CodeCallback_OnWeaponReload = 0x1729848;
			uintptr_t GetSpread = 0xA664D0;
			uintptr_t ApplySpread = 0xC42A60;
			uintptr_t FireBullet = 0x1014A00;
			uintptr_t FireProjectile = 0x100B230;
			uintptr_t StartDrawing = 0x53EFC0;
			uintptr_t EndDrawing = 0x53F1B0;
			uintptr_t surface = 0x241EE770;
			uintptr_t paint = 0x546900;
			uintptr_t glidefunc = 0x864C40;
			uintptr_t glidefun2c = 0x0061F810;
		}
		//0x2240

		namespace Global {
			constexpr auto dwEntityList = 0x021b3fa8;
			constexpr auto dwLocalPlayer = 0x22E93F8;
			constexpr auto ViewRender = 0xD4138F0;
			constexpr auto ViewMatrix = 0x1A93D0;
			constexpr auto TimeScale = 0x1843340;

			constexpr auto m_fFlags = 0x98;
			constexpr auto m_pBoneMatrix = 0xEE0;
			constexpr auto m_vecAbsVelocity = 0x140;
			constexpr auto m_localOrigin = 0x14C;
			constexpr auto m_shieldHealth = 0x170;
			constexpr auto m_shieldHealthMax = 0x174;
			constexpr auto m_iHealth = 0x3E0;
			constexpr auto m_iTeamNum = 0x3F0;
			constexpr auto m_Collision = 0x458;
			constexpr auto m_iMaxHealth = 0x510;
			constexpr auto m_iSignifierName = 0x518;
			constexpr auto m_lifeState = 0x730;
			constexpr auto camera_origin = 0x1b68;
			constexpr auto m_lastvisibletime = 0x1754;
			constexpr auto m_vecPunchBase_Angle = 0x20a4;
			constexpr auto m_vecPunchWeapon_Angle = 0x20bc;
			constexpr auto m_vecPunchAngle = 0x20bc;
			constexpr auto m_vecSwayAngle = 0x2178;
			constexpr auto m_vecViewAngle = 0x2188;
			constexpr auto m_iObserverMode = 0x2fcc;
			constexpr auto m_hObserverTarget = 0x2fd0;
			constexpr auto m_szName = 0x3BF8;

            struct C_Player // sizeof=0x41C0
            {
                char base_class[0x1880];                                    // 0x0000 - C_BaseCombatCharacter base
                bool unk;                                                    // 0x1880
                bool m_bZooming;                                            // 0x1881
                char pad_1882[2];                                           // 0x1882
                float m_zoomToggleOnStartTime;                              // 0x1884
                float m_zoomBaseFrac;                                       // 0x1888
                float m_zoomBaseTime;                                       // 0x188C
                float m_zoomFullStartTime;                                  // 0x1890
                char pad_1894[124];                                         // 0x1894
                int m_lastUCmdSimulationTicks;                              // 0x1910
                float m_lastUCmdSimulationRemainderTime;                    // 0x1914
                char pad_1918[280];                                         // 0x1918
                char m_Local[712];                                          // 0x1A30 - C_PlayerLocalData
                char pad_1CF8[32];                                          // 0x1CF8
                float m_currentFramePlayer__timeBase;                       // 0x1D18
                char pad_1D1C[4];                                           // 0x1D1C
                char m_currentFramePlayer__statusEffectsTimedPlayerCUR[224]; // 0x1D20
                char m_currentFramePlayer__statusEffectsEndlessPlayerCUR[160]; // 0x1E10
                float m_currentFramePlayer__m_flHullHeight;                 // 0x1EB0
                float m_currentFramePlayer__m_traversalAnimProgress;        // 0x1EB4
                float m_currentFramePlayer__m_sprintTiltFrac;               // 0x1EB8
                char pad_1EBC[12];                                          // 0x1EBC
                int m_currentFramePlayer__m_ammoPoolCount[8];               // 0x1EC8
                char pad_1EE8[432];                                         // 0x1EE8
                float m_currentFrameLocalPlayer__m_stepSmoothingOffset[3];  // 0x2098
                float m_currentFrameLocalPlayer__m_vecPunchBase_Angle[3];   // 0x20A4
                float m_currentFrameLocalPlayer__m_vecPunchBase_AngleVel[3]; // 0x20B0
                float m_currentFrameLocalPlayer__m_vecPunchWeapon_Angle[3]; // 0x20BC
                float m_currentFrameLocalPlayer__m_vecPunchWeapon_AngleVel[3]; // 0x20C8
                char pad_20D4[48];                                          // 0x20D4
                float m_currentFrameLocalPlayer__m_localGravityRotation[4]; // 0x2104 - Quaternion
                char pad_2114[4];                                           // 0x2114
                char pl[144];                                               // 0x2118 - CPlayerState
                char pad_21A8[132];                                         // 0x21A8
                int m_ammoPoolCapacity;                                     // 0x222C
                char pad_2230[714];                                         // 0x2230
                int m_gestureSequences[8];                                  // 0x24FC
                float m_gestureStartTimes[8];                               // 0x251C
                float m_gestureBlendInDuration[8];                          // 0x253C
                float m_gestureBlendOutDuration[8];                         // 0x255C
                float m_gestureFadeOutStartTime[8];                         // 0x257C
                float m_gestureFadeOutDuration[8];                          // 0x259C
                int m_gestureAutoKillBitfield;                              // 0x25BC
                char pad_25C0[24];                                          // 0x25C0
                int m_afButtonLast;                                         // 0x25D8
                int m_afButtonPressed;                                      // 0x25DC
                int m_afButtonReleased;                                     // 0x25E0
                int m_nButtons;                                             // 0x25E4
                int m_nImpulse;                                             // 0x25E8
                int m_flPhysics;                                            // 0x25EC
                float m_flStepSoundTime;                                    // 0x25F0
                float m_flTimeAllSuitDevicesOff;                            // 0x25F4
                float m_fStickySprintMinTime;                               // 0x25F8
                bool m_bPlayedSprintStartEffects;                           // 0x25FC
                char pad_25FD[7];                                           // 0x25FD
                bool m_fIsSprinting;                                        // 0x2604
                bool m_fIsWalking;                                          // 0x2605
                char pad_2606[2];                                           // 0x2606
                float m_sprintStartedTime;                                  // 0x2608
                float m_sprintStartedFrac;                                  // 0x260C
                float m_sprintEndedTime;                                    // 0x2610
                float m_sprintEndedFrac;                                    // 0x2614
                float m_stickySprintStartTime;                              // 0x2618
                float m_damageImpulseNoDecelEndTime;                        // 0x261C
                char pad_2620[12];                                          // 0x2620
                int m_duckState;                                            // 0x262C
                int m_leanState;                                            // 0x2630
                bool m_doingHalfDuck;                                       // 0x2634
                bool m_canStand;                                            // 0x2635
                char pad_2636[2];                                           // 0x2636
                float m_StandHullMin[3];                                    // 0x2638
                float m_StandHullMax[3];                                    // 0x2644
                float m_DuckHullMin[3];                                     // 0x2650
                float m_DuckHullMax[3];                                     // 0x265C
                char pad_2668[4];                                           // 0x2668
                float m_upDir[3];                                           // 0x266C
                float m_upDirPredicted[3];                                  // 0x2678
                float m_lastWallRunStartPos[3];                             // 0x2684
                int m_wallRunCount;                                         // 0x2690
                bool m_wallRunWeak;                                         // 0x2694
                bool m_shouldBeOneHanded;                                   // 0x2695
                char pad_2696[2];                                           // 0x2696
                float m_oneHandFraction;                                    // 0x2698
                float m_animAimPitch;                                       // 0x269C
                float m_animAimYaw;                                         // 0x26A0
                float m_wallRunPushAwayTime;                                // 0x26A4
                char pad_26A8[8];                                           // 0x26A8
                float m_wallrunRetryTime;                                   // 0x26B0
                float m_wallrunRetryPos[3];                                 // 0x26B4
                float m_wallrunRetryNormal[3];                              // 0x26C0
                char pad_26CC[24];                                          // 0x26CC
                float m_wallHangTime;                                       // 0x26E4
                int m_traversalState;                                       // 0x26E8
                int m_traversalType;                                        // 0x26EC
                float m_traversalBegin[3];                                  // 0x26F0
                float m_traversalMid[3];                                    // 0x26FC
                float m_traversalEnd[3];                                    // 0x2708
                float m_traversalMidFrac;                                   // 0x2714
                float m_traversalForwardDir[3];                             // 0x2718
                float m_traversalRefPos[3];                                 // 0x2724
                float m_traversalProgress;                                  // 0x2730
                float m_traversalStartTime;                                 // 0x2734
                float m_traversalHandAppearTime;                            // 0x2738
                float m_traversalReleaseTime;                               // 0x273C
                float m_traversalBlendOutStartTime;                         // 0x2740
                float m_traversalBlendOutStartOffset[3];                    // 0x2744
                float m_traversalYawDelta;                                  // 0x2750
                char pad_2754[8];                                           // 0x2754
                float m_wallDangleJumpOffTime;                              // 0x275C
                bool m_wallDangleMayHangHere;                               // 0x2760
                bool m_wallDangleForceFallOff;                              // 0x2761
                bool m_wallDangleLastPushedForward;                         // 0x2762
                char pad_2763[1];                                           // 0x2763
                int m_wallDangleDisableWeapon;                              // 0x2764
                float m_wallDangleClimbProgressFloor;                       // 0x2768
                bool m_wallClimbSetUp;                                      // 0x276C
                bool m_wallHanging;                                         // 0x276D
                char pad_276E[2];                                           // 0x276E
                char m_grapple[128];                                        // 0x2770 - GrappleData
                char pad_27F0[16];                                          // 0x27F0
                bool m_grappleActive;                                       // 0x2800
                bool m_grappleNeedWindowCheck;                              // 0x2801
                char pad_2802[2];                                           // 0x2802
                int m_grappleNextWindowHint;                                // 0x2804
                char pad_2808[12];                                          // 0x2808
                bool m_slowMoEnabled;                                       // 0x2814
                bool m_sliding;                                             // 0x2815
                bool m_slideLongJumpAllowed;                                // 0x2816
                char pad_2817[1];                                           // 0x2817
                float m_lastSlideTime;                                      // 0x2818
                float m_lastSlideBoost;                                     // 0x281C
                int m_gravityGrenadeStatusEffect;                           // 0x2820
                bool m_bIsStickySprinting;                                  // 0x2824
                char pad_2825[3];                                           // 0x2825
                float m_prevMoveYaw;                                        // 0x2828
                float m_sprintTiltVel;                                      // 0x282C
                char pad_2830[24];                                          // 0x2830
                int m_hViewModels[3];                                       // 0x2848
                char pad_2854[4];                                           // 0x2854
                char m_viewOffsetEntity[24];                                // 0x2858 - Player_ViewOffsetEntityData
                char pad_2870[294];                                         // 0x2870
                int m_activeZipline;                                        // 0x2998
                int m_lastZipline;                                          // 0x299C
                float m_lastZiplineDetachTime;                              // 0x29A0
                bool m_ziplineValid3pWeaponLayerAnim;                       // 0x29A4
                char pad_29A5[3];                                           // 0x29A5
                int m_ziplineState;                                         // 0x29A8
                char pad_29AC[4];                                           // 0x29AC
                char m_zipline[112];                                        // 0x29B0 - PlayerZiplineData_Client
                float m_ziplineViewOffsetPosition[3];                       // 0x2A20
                float m_ziplineViewOffsetVelocity[3];                       // 0x2A2C
                int m_ziplineGrenadeEntity;                                 // 0x2A38
                int m_ziplineGrenadeBeginStationEntity;                     // 0x2A3C
                int m_ziplineGrenadeBeginStationAttachmentIndex;            // 0x2A40
                char pad_2A44[8];                                           // 0x2A44
                int m_playAnimationType;                                    // 0x2A4C
                bool m_detachGrappleOnPlayAnimationEnd;                     // 0x2A50
                char pad_2A51[3];                                           // 0x2A51
                int m_playAnimationNext[2];                                 // 0x2A54
                char pad_2A5C[12];                                          // 0x2A5C
                bool m_boosting;                                            // 0x2A68
                bool m_activateBoost;                                       // 0x2A69
                bool m_repeatedBoost;                                       // 0x2A6A
                char pad_2A6B[1];                                           // 0x2A6B
                float m_boostMeter;                                         // 0x2A6C
                bool m_jetpack;                                             // 0x2A70
                bool m_activateJetpack;                                     // 0x2A71
                bool m_jetpackAfterburner;                                  // 0x2A72
                bool m_gliding;                                             // 0x2A73
                float m_glideMeter;                                         // 0x2A74 <<< HERE
                float m_glideRechargeDelayAccumulator;                      // 0x2A78
                bool m_hovering;                                            // 0x2A7C
                bool m_isPerformingBoostAction;                             // 0x2A7D
                char pad_2A7E[2];                                           // 0x2A7E
                float m_lastJumpHeight;                                     // 0x2A80
                char pad_2A84[76];                                          // 0x2A84
                float m_slipAirRestrictDirection[3];                        // 0x2AD0
                float m_slipAirRestrictTime;                                // 0x2ADC
                char pad_2AE0[400];                                         // 0x2AE0
                char m_melee[56];                                           // 0x2C70 - PlayerMelee_PlayerData
                bool m_useCredit;                                           // 0x2CA8
                char pad_2CA9[979];                                         // 0x2CA9
                float m_wallRunStartTime;                                   // 0x307C
                float m_wallRunClearTime;                                   // 0x3080
                float m_onSlopeTime;                                        // 0x3084
                float m_lastWallNormal[3];                                  // 0x3088
                bool m_dodging;                                             // 0x3094
                char pad_3095[3];                                           // 0x3095
                float m_lastDodgeTime;                                      // 0x3098
                float m_vecPreviouslyPredictedOrigin[3];                    // 0x309C
                char pad_30A8[12];                                          // 0x30A8
                float m_flTimeLastTouchedWall;                              // 0x30B4
                float m_timeJetpackHeightActivateCheckPassed;              // 0x30B8
                float m_flTimeLastTouchedGround;                            // 0x30BC
                float m_flTimeLastJumped;                                   // 0x30C0
                float m_flTimeLastLanded;                                   // 0x30C4
                float m_flLastLandFromHeight;                               // 0x30C8
                float m_usePressedTime;                                     // 0x30CC
                float m_lastUseTime;                                        // 0x30D0
                char pad_30D4[12];                                          // 0x30D4
                float m_lastFakeFloorPos[3];                                // 0x30E0
                bool m_bHasJumpedSinceTouchedGround;                        // 0x30EC
                bool m_bDoMultiJumpPenalty;                                 // 0x30ED
                bool m_dodgingInAir;                                        // 0x30EE
                char pad_30EF[185];                                         // 0x30EF
                bool m_thirdPerson;                                         // 0x31A8
                char pad_31A9[263];                                         // 0x31A9
                bool m_activeViewmodelModifiers[35];                        // 0x32B0
                char pad_32D3[701];                                         // 0x32D3
                float m_lastMoveInputTime;                                  // 0x3590
                int m_ignoreEntityForMovementUntilNotTouching;              // 0x3594
                char pad_3598[1224];                                        // 0x3598
                float m_gameMovementUtil__m_surfaceFriction;                // 0x3A60
                char pad_3A64[120];                                         // 0x3A64
                int m_lungeTargetEntity;                                    // 0x3ADC
                bool m_isLungingToPosition;                                 // 0x3AE0
                char pad_3AE1[3];                                           // 0x3AE1
                float m_lungeTargetPosition[3];                             // 0x3AE4
                float m_lungeStartPositionOffset[3];                        // 0x3AF0
                float m_lungeEndPositionOffset[3];                          // 0x3AFC
                float m_lungeStartTime;                                     // 0x3B08
                float m_lungeEndTime;                                       // 0x3B0C
                bool m_lungeCanFly;                                         // 0x3B10
                bool m_lungeLockPitch;                                      // 0x3B11
                char pad_3B12[2];                                           // 0x3B12
                float m_lungeStartPitch;                                    // 0x3B14
                float m_lungeSmoothTime;                                    // 0x3B18
                float m_lungeMaxTime;                                       // 0x3B1C
                float m_lungeMaxEndSpeed;                                   // 0x3B20
                char pad_3B24[828];                                         // 0x3B24
                float m_vPrevGroundNormal[3];                               // 0x3E60
                char pad_3E6C[440];                                         // 0x3E6C
                float m_pushAwayFromTopAcceleration[3];                     // 0x4024
                char pad_4030[28];                                          // 0x4030
                bool m_controllerModeActive;                                // 0x404C
                char pad_404D[23];                                          // 0x404D
                float m_skydiveForwardPoseValueVelocity;                    // 0x4064
                float m_skydiveForwardPoseValueTarget;                      // 0x4068
                float m_skydiveForwardPoseValueCurrent;                     // 0x406C
                float m_skydiveSidePoseValueVelocity;                       // 0x4070
                float m_skydiveSidePoseValueTarget;                         // 0x4074
                float m_skydiveSidePoseValueCurrent;                        // 0x4078
                float m_skydiveYawVelocity;                                 // 0x407C
                char pad_4080[24];                                          // 0x4080
                int m_freefallState;                                        // 0x4098
                float m_freefallStartTime;                                  // 0x409C
                float m_freefallEndTime;                                    // 0x40A0
                float m_freefallAnticipateStartTime;                        // 0x40A4
                float m_freefallAnticipateEndTime;                          // 0x40A8
                float m_freefallDistanceToLand;                             // 0x40AC
                float m_skydiveDiveAngle;                                   // 0x40B0
                bool m_skydiveIsDiving;                                     // 0x40B4
                char pad_40B5[3];                                           // 0x40B5
                float m_skydiveSpeed;                                       // 0x40B8
                float m_skydiveStrafeAngle;                                 // 0x40BC
                bool m_skydiveFreelookEnabled;                              // 0x40C0
                char pad_40C1[3];                                           // 0x40C1
                float m_skydiveFreelookLockedAngle[3];                      // 0x40C4
                float m_skydivePlayerPitch;                                 // 0x40D0
                float m_skydivePlayerYaw;                                   // 0x40D4
                bool m_skydiveFollowing;                                    // 0x40D8
                char pad_40D9[3];                                           // 0x40D9
                float m_skydiveUnfollowVelocity[3];                         // 0x40DC
                char pad_40E8[1];                                           // 0x40E8
                bool m_skydiveIsNearLeviathan;                              // 0x40E9
                char pad_40EA[2];                                           // 0x40EA
                float m_skydiveLeviathanHitPosition[3];                     // 0x40EC
                float m_skydiveLeviathanHitNormal[3];                       // 0x40F8
                float m_skydiveSlipVelocity[3];                             // 0x4104
                char pad_4110[16];                                          // 0x4110
                char m_playerKnockBacks[128];                               // 0x4120 - C_KnockBack[4]
                char pad_41A0[32];                                          // 0x41A0
            };

		}
		//0x7FF6B6C80000
		//0x7FF6770C3C58 
	}
}

#endif