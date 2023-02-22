#ifndef __SCRIPTING_H
#define __SCRIPTING_H

// This is the fastest way to use Game Logic ¯\_(ツ)_/¯

#include <stdint.h>
#define VA_ARGS(...) , ##__VA_ARGS__

#define DEFVAR(__opcode, __name, __args) const SCRIPT_COMMAND scm_##__name = { 0x##__opcode, #__args }
#define CALLSCM(__name, ...)             ScriptCommand(&scm_##__name VA_ARGS(__VA_ARGS__))

#define MAX_SCRIPT_VARS 16
#define MAX_SCRIPT_SIZE	255

struct GAME_SCRIPT_THREAD
{
    uint8_t   pad1[20];
    uintptr_t dwScriptIP;
    uint8_t   pad2[36];
    uint32_t  dwLocalVar[32];
    uint32_t  dwTimers[2];
    uint8_t   pad3[33];
    uint8_t   condResult;
    uint8_t   pad4[10];
    uint16_t  logicalOp;
    uint8_t   notFlag;
    uint8_t   pad5[13];
};

struct SCRIPT_COMMAND
{
    uint16_t  opCode;
    char      params[MAX_SCRIPT_VARS];
};

void          InitializeScripting();
int           ScriptCommand(const SCRIPT_COMMAND* pScriptCommand, ...);
extern        GAME_SCRIPT_THREAD* gst;

// https://library.sannybuilder.com/#/sa_mobile
DEFVAR(0003, SHAKE_CAM, i);
DEFVAR(0053, CREATE_PLAYER, ifffv);
DEFVAR(009A, CREATE_CHAR, iifffv);
DEFVAR(009B, DELETE_CHAR, i);
DEFVAR(00A0, GET_CHAR_COORDINATES, ivvv);
DEFVAR(00A1, SET_CHAR_COORDINATES, ifff);
DEFVAR(00A3, IS_CHAR_IN_AREA_2D, iffffb);
DEFVAR(00A4, IS_CHAR_IN_AREA_3D, iffffffb);
DEFVAR(00A5, CREATE_CAR, ifffv);
DEFVAR(00A6, DELETE_CAR, i);
DEFVAR(00A7, CAR_GOTO_COORDINATES, ifff);
DEFVAR(00A8, CAR_WANDER_RANDOMLY, i);
DEFVAR(00A9, CAR_SET_IDLE, i);
DEFVAR(00AA, GET_CAR_COORDINATES, ivvv);
DEFVAR(00AB, SET_CAR_COORDINATES, ifff);
DEFVAR(00AD, SET_CAR_CRUISE_SPEED, if);
DEFVAR(00AE, SET_CAR_DRIVING_STYLE, ii);
DEFVAR(00AF, SET_CAR_MISSION, ii);
DEFVAR(00B0, IS_CAR_IN_AREA_2D, iffffb);
DEFVAR(00B1, IS_CAR_IN_AREA_3D, iffffffb);
DEFVAR(00BA, PRINT_BIG, sii);
DEFVAR(00BB, PRINT, sii);
DEFVAR(00BC, PRINT_NOW, sii);
DEFVAR(00BE, CLEAR_PRINTS, );
DEFVAR(00BF, GET_TIME_OF_DAY, vv);
DEFVAR(00C0, SET_TIME_OF_DAY, ii);
DEFVAR(00C1, GET_MINUTES_TO_TIME_OF_DAY, iiv);
DEFVAR(00C2, IS_POINT_ON_SCREEN, ffff);
DEFVAR(00DB, IS_CHAR_IN_CAR, ii);
DEFVAR(00DD, IS_CHAR_IN_MODEL, ii);
DEFVAR(00DF, IS_CHAR_IN_ANY_CAR, i);
DEFVAR(00E1, IS_BUTTON_PRESSED, ii);
DEFVAR(00E2, GET_PAD_STATE, iiv);
DEFVAR(00EC, LOCATE_CHAR_ANY_MEANS_2D, iffffb);
DEFVAR(00ED, LOCATE_CHAR_ON_FOOT_2D, iffffb);
DEFVAR(00EE, LOCATE_CHAR_IN_CAR_2D, iffffb);
DEFVAR(00EF, LOCATE_STOPPED_CHAR_ANY_MEANS_2D, iffffb);
DEFVAR(00F0, LOCATE_STOPPED_CHAR_ON_FOOT_2D, iffffb);
DEFVAR(00F1, LOCATE_STOPPED_CHAR_IN_CAR_2D, iffffb);
DEFVAR(00F2, LOCATE_CHAR_ANY_MEANS_CHAR_2D, iiffb);
DEFVAR(00F3, LOCATE_CHAR_ON_FOOT_CHAR_2D, iiffb);
DEFVAR(00F4, LOCATE_CHAR_IN_CAR_CHAR_2D, iiffb);
DEFVAR(00FE, LOCATE_CHAR_ANY_MEANS_3D, iffffffb);
DEFVAR(00FF, LOCATE_CHAR_ON_FOOT_3D, iffffffb);
DEFVAR(0100, LOCATE_CHAR_IN_CAR_3D, iffffffb);
DEFVAR(0101, LOCATE_STOPPED_CHAR_ANY_MEANS_3D, iffffffb);
DEFVAR(0102, LOCATE_STOPPED_CHAR_ON_FOOT_3D, iffffffb);
DEFVAR(0103, LOCATE_STOPPED_CHAR_IN_CAR_3D, iffffffb);
DEFVAR(0104, LOCATE_CHAR_ANY_MEANS_CHAR_3D, iifffb);
DEFVAR(0105, LOCATE_CHAR_ON_FOOT_CHAR_3D, iifffb);
DEFVAR(0106, LOCATE_CHAR_IN_CAR_CHAR_3D, iifffb);
DEFVAR(0107, CREATE_OBJECT, ifffv);
DEFVAR(0108, DELETE_OBJECT, i);
DEFVAR(0109, ADD_SCORE, ii);
DEFVAR(010A, IS_SCORE_GREATER, ii);
DEFVAR(010B, STORE_SCORE, iv);
DEFVAR(010D, ALTER_WANTED_LEVEL, ii);
DEFVAR(010E, ALTER_WANTED_LEVEL_NO_DROP, ii);
DEFVAR(010F, IS_WANTED_LEVEL_GREATER, ii);
DEFVAR(0110, CLEAR_WANTED_LEVEL, i);
DEFVAR(0111, SET_DEATHARREST_STATE, b);
DEFVAR(0112, HAS_DEATHARREST_BEEN_EXECUTED, );
DEFVAR(0114, ADD_AMMO_TO_CHAR, iii);
DEFVAR(0117, IS_PLAYER_DEAD, i);
DEFVAR(0118, IS_CHAR_DEAD, i);
DEFVAR(0119, IS_CAR_DEAD, i);
DEFVAR(0122, IS_PLAYER_PRESSING_HORN, i);
DEFVAR(0129, CREATE_CHAR_INSIDE_CAR, iiiv);
DEFVAR(0137, IS_CAR_MODEL, ii);
DEFVAR(014B, CREATE_CAR_GENERATOR, ffffiiibiiiiv);
DEFVAR(014C, SWITCH_CAR_GENERATOR, ii);
DEFVAR(0154, IS_CHAR_IN_ZONE, ii);
DEFVAR(0158, POINT_CAMERA_AT_CAR, iii);
DEFVAR(0159, POINT_CAMERA_AT_CHAR, iii);
DEFVAR(015A, RESTORE_CAMERA, );
DEFVAR(015B, SHAKE_PAD, iii);
DEFVAR(015D, SET_TIME_SCALE, f);
DEFVAR(015F, SET_FIXED_CAMERA_POSITION, ffffff);
DEFVAR(0160, POINT_CAMERA_AT_POINT, fffi);
DEFVAR(0161, ADD_BLIP_FOR_CAR_OLD, iiiv);
DEFVAR(0164, REMOVE_BLIP, i);
DEFVAR(0165, CHANGE_BLIP_COLOUR, ii);
DEFVAR(0167, ADD_BLIP_FOR_COORD_OLD, fffiiv);
DEFVAR(0168, CHANGE_BLIP_SCALE, ii);
DEFVAR(0169, SET_FADING_COLOUR, iii);
DEFVAR(016A, DO_FADE, ii);
DEFVAR(016B, GET_FADING_STATUS, );
DEFVAR(016C, ADD_HOSPITAL_RESTART, ffffi);
DEFVAR(016D, ADD_POLICE_RESTART, ffffi);
DEFVAR(016E, OVERRIDE_NEXT_RESTART, ffff);
DEFVAR(016F, DRAW_SHADOW, ifffffiiii);
DEFVAR(0172, GET_CHAR_HEADING, iv);
DEFVAR(0173, SET_CHAR_HEADING, if);
DEFVAR(0174, GET_CAR_HEADING, iv);
DEFVAR(0175, SET_CAR_HEADING, if);
DEFVAR(0176, GET_OBJECT_HEADING, iv);
DEFVAR(0177, SET_OBJECT_HEADING, if);
DEFVAR(0179, IS_CHAR_TOUCHING_OBJECT, ii);
DEFVAR(017B, SET_CHAR_AMMO, iii);
DEFVAR(0184, IS_CHAR_HEALTH_GREATER, ii);
DEFVAR(0185, IS_CAR_HEALTH_GREATER, ii);
DEFVAR(0186, ADD_BLIP_FOR_CAR, iv);
DEFVAR(0187, ADD_BLIP_FOR_CHAR, iv);
DEFVAR(0188, ADD_BLIP_FOR_OBJECT, iv);
DEFVAR(018A, ADD_BLIP_FOR_COORD, fffv);
DEFVAR(018B, CHANGE_BLIP_DISPLAY, ii);
DEFVAR(018C, ADD_ONE_OFF_SOUND, fffi);
DEFVAR(018F, IS_CAR_STUCK_ON_ROOF, i);
DEFVAR(0190, ADD_UPSIDEDOWN_CAR_CHECK, i);
DEFVAR(0191, REMOVE_UPSIDEDOWN_CAR_CHECK, i);
DEFVAR(01A1, IS_CHAR_IN_AREA_ON_FOOT_2D, iffffb);
DEFVAR(01A2, IS_CHAR_IN_AREA_IN_CAR_2D, iffffb);
DEFVAR(01A3, IS_CHAR_STOPPED_IN_AREA_2D, iffffb);
DEFVAR(01A4, IS_CHAR_STOPPED_IN_AREA_ON_FOOT_2D, iffffb);
DEFVAR(01A5, IS_CHAR_STOPPED_IN_AREA_IN_CAR_2D, iffffb);
DEFVAR(01A6, IS_CHAR_IN_AREA_ON_FOOT_3D, iffffffb);
DEFVAR(01A7, IS_CHAR_IN_AREA_IN_CAR_3D, iffffffb);
DEFVAR(01A8, IS_CHAR_STOPPED_IN_AREA_3D, iffffffb);
DEFVAR(01A9, IS_CHAR_STOPPED_IN_AREA_ON_FOOT_3D, iffffffb);
DEFVAR(01AA, IS_CHAR_STOPPED_IN_AREA_IN_CAR_3D, iffffffb);
DEFVAR(01AB, IS_CAR_STOPPED_IN_AREA_2D, iffffb);
DEFVAR(01AC, IS_CAR_STOPPED_IN_AREA_3D, iffffffb);
DEFVAR(01AD, LOCATE_CAR_2D, iffffb);
DEFVAR(01AE, LOCATE_STOPPED_CAR_2D, iffffb);
DEFVAR(01AF, LOCATE_CAR_3D, iffffffb);
DEFVAR(01B0, LOCATE_STOPPED_CAR_3D, iffffffb);
DEFVAR(01B2, GIVE_WEAPON_TO_CHAR, iii);
DEFVAR(01B4, SET_PLAYER_CONTROL, ib);
DEFVAR(01B5, FORCE_WEATHER, i);
DEFVAR(01B6, FORCE_WEATHER_NOW, i);
DEFVAR(01B7, RELEASE_WEATHER, );
DEFVAR(01B9, SET_CURRENT_CHAR_WEAPON, ii);
DEFVAR(01BB, GET_OBJECT_COORDINATES, ivvv);
DEFVAR(01BC, SET_OBJECT_COORDINATES, ifff);
DEFVAR(01BD, GET_GAME_TIMER, v);
DEFVAR(01C0, STORE_WANTED_LEVEL, iv);
DEFVAR(01C1, IS_CAR_STOPPED, i);
DEFVAR(01C2, MARK_CHAR_AS_NO_LONGER_NEEDED, i);
DEFVAR(01C3, MARK_CAR_AS_NO_LONGER_NEEDED, i);
DEFVAR(01C4, MARK_OBJECT_AS_NO_LONGER_NEEDED, i);
DEFVAR(01C5, DONT_REMOVE_CHAR, i);
DEFVAR(01C7, DONT_REMOVE_OBJECT, i);
DEFVAR(01C8, CREATE_CHAR_AS_PASSENGER, iiiiv);
DEFVAR(01E3, PRINT_WITH_NUMBER_BIG, siii);
DEFVAR(01E4, PRINT_WITH_NUMBER, siii);
DEFVAR(01E5, PRINT_WITH_NUMBER_NOW, siii);
DEFVAR(01E7, SWITCH_ROADS_ON, ffffff);
DEFVAR(01E8, SWITCH_ROADS_OFF, ffffff);
DEFVAR(01E9, GET_NUMBER_OF_PASSENGERS, iv);
DEFVAR(01EA, GET_MAXIMUM_NUMBER_OF_PASSENGERS, iv);
DEFVAR(01EB, SET_CAR_DENSITY_MULTIPLIER, f);
DEFVAR(01EC, SET_CAR_HEAVY, ib);
DEFVAR(01F0, SET_MAX_WANTED_LEVEL, i);
DEFVAR(01F3, IS_CAR_IN_AIR_PROPER, i);
DEFVAR(01F4, IS_CAR_UPSIDEDOWN, i);
DEFVAR(01F5, GET_PLAYER_CHAR, iv);
DEFVAR(01F6, CANCEL_OVERRIDE_RESTART, );
DEFVAR(01F7, SET_POLICE_IGNORE_PLAYER, ib);
DEFVAR(0202, LOCATE_CHAR_ANY_MEANS_CAR_2D, iiffb);
DEFVAR(0203, LOCATE_CHAR_ON_FOOT_CAR_2D, iiffb);
DEFVAR(0204, LOCATE_CHAR_IN_CAR_CAR_2D, iiffb);
DEFVAR(0205, LOCATE_CHAR_ANY_MEANS_CAR_3D, iifffb);
DEFVAR(0206, LOCATE_CHAR_ON_FOOT_CAR_3D, iifffb);
DEFVAR(0207, LOCATE_CHAR_IN_CAR_CAR_3D, iifffb);
DEFVAR(020A, LOCK_CAR_DOORS, ii);
DEFVAR(020B, EXPLODE_CAR, i);
DEFVAR(020C, ADD_EXPLOSION, fffi);
DEFVAR(020D, IS_CAR_UPRIGHT, i);
DEFVAR(0213, CREATE_PICKUP, iifffv);
DEFVAR(0214, HAS_PICKUP_BEEN_COLLECTED, i);
DEFVAR(0215, REMOVE_PICKUP, i);
DEFVAR(0216, SET_TAXI_LIGHTS, ib);
DEFVAR(0217, PRINT_BIG_Q, sii);
DEFVAR(021B, SET_TARGET_CAR_FOR_MISSION_GARAGE, si);
DEFVAR(0221, APPLY_BRAKES_TO_PLAYERS_CAR, ib);
DEFVAR(0223, SET_CHAR_HEALTH, ii);
DEFVAR(0224, SET_CAR_HEALTH, ii);
DEFVAR(0226, GET_CHAR_HEALTH, iv);
DEFVAR(0227, GET_CAR_HEALTH, iv);
DEFVAR(0229, CHANGE_CAR_COLOUR, iii);
DEFVAR(022A, SWITCH_PED_ROADS_ON, ffffff);
DEFVAR(022B, SWITCH_PED_ROADS_OFF, ffffff);
DEFVAR(023C, LOAD_SPECIAL_CHARACTER, is);
DEFVAR(023D, HAS_SPECIAL_CHARACTER_LOADED, i);
DEFVAR(0241, IS_PLAYER_IN_REMOTE_MODE, i);
DEFVAR(0242, ARM_CAR_WITH_BOMB, ii);
DEFVAR(0244, SET_CUTSCENE_OFFSET, fff);
DEFVAR(0245, SET_ANIM_GROUP_FOR_CHAR, ii);
DEFVAR(0247, REQUEST_MODEL, i);
DEFVAR(0248, HAS_MODEL_LOADED, i);
DEFVAR(0249, MARK_MODEL_AS_NO_LONGER_NEEDED, i);
DEFVAR(024F, DRAW_CORONA, ffffiiiii);
DEFVAR(0253, STORE_CLOCK, );
DEFVAR(0254, RESTORE_CLOCK, );
DEFVAR(0256, IS_PLAYER_PLAYING, i);
DEFVAR(0293, GET_CONTROLLER_MODE, v);
DEFVAR(0294, SET_CAN_RESPRAY_CAR, ib);
DEFVAR(0296, UNLOAD_SPECIAL_CHARACTER, i);
DEFVAR(0297, RESET_NUM_OF_MODELS_KILLED_BY_PLAYER, i);
DEFVAR(0298, GET_NUM_OF_MODELS_KILLED_BY_PLAYER, iiv);
DEFVAR(0299, ACTIVATE_GARAGE, s);
DEFVAR(029B, CREATE_OBJECT_NO_OFFSET, ifff);
DEFVAR(02A0, IS_CHAR_STOPPED, i);
DEFVAR(02A3, SWITCH_WIDESCREEN, b);
DEFVAR(02A7, ADD_SPRITE_BLIP_FOR_CONTACT_POINT, fffiv);
DEFVAR(02A8, ADD_SPRITE_BLIP_FOR_COORD, fffiv);
DEFVAR(02A9, SET_CHAR_ONLY_DAMAGED_BY_PLAYER, ib);
DEFVAR(02AA, SET_CAR_ONLY_DAMAGED_BY_PLAYER, ib);
DEFVAR(02AB, SET_CHAR_PROOFS, ibbbbb);
DEFVAR(02AC, SET_CAR_PROOFS, ibbbbb);
DEFVAR(02B9, DEACTIVATE_GARAGE, s);
DEFVAR(02BF, IS_CAR_IN_WATER, i);
DEFVAR(02C0, GET_CLOSEST_CHAR_NODE, fffvvv);
DEFVAR(02C1, GET_CLOSEST_CAR_NODE, fffvvv);
DEFVAR(02C2, CAR_GOTO_COORDINATES_ACCURATE, ifff);
DEFVAR(02CA, IS_CAR_ON_SCREEN, i);
DEFVAR(02CB, IS_CHAR_ON_SCREEN, i);
DEFVAR(02CC, IS_OBJECT_ON_SCREEN, i);
DEFVAR(02CE, GET_GROUND_Z_FOR_3D_COORD, fffv);
DEFVAR(02CF, START_SCRIPT_FIRE, fffiiv);
DEFVAR(02D0, IS_SCRIPT_FIRE_EXTINGUISHED, i);
DEFVAR(02D1, REMOVE_SCRIPT_FIRE, i);
DEFVAR(02D3, BOAT_GOTO_COORDS, ifff);
DEFVAR(02D4, BOAT_STOP, i);
DEFVAR(02D6, IS_CHAR_SHOOTING_IN_AREA, iffffb);
DEFVAR(02D8, IS_CURRENT_CHAR_WEAPON, ii);
DEFVAR(02DD, GET_RANDOM_CHAR_IN_ZONE, ibbbv);
DEFVAR(02E0, IS_CHAR_SHOOTING, i);
DEFVAR(02E1, CREATE_MONEY_PICKUP, fffibv);
DEFVAR(02E2, SET_CHAR_ACCURACY, ii);
DEFVAR(02E3, GET_CAR_SPEED, iv);
DEFVAR(02EB, RESTORE_CAMERA_JUMPCUT, );
DEFVAR(02ED, SET_COLLECTABLE1_TOTAL, i);
DEFVAR(02EE, IS_PROJECTILE_IN_AREA, ffffff);
DEFVAR(02F2, IS_CHAR_MODEL, ii);
DEFVAR(02F8, GET_CAR_FORWARD_X, iv);
DEFVAR(02F9, GET_CAR_FORWARD_Y, iv);
DEFVAR(02FA, CHANGE_GARAGE_TYPE, si);
DEFVAR(02FD, PRINT_WITH_2_NUMBERS_NOW, siiii);
DEFVAR(02FF, PRINT_WITH_3_NUMBERS, siiiii);
DEFVAR(0302, PRINT_WITH_4_NUMBERS, siiiiii);
DEFVAR(0303, PRINT_WITH_4_NUMBERS_NOW, siiiiii);
DEFVAR(0308, PRINT_WITH_6_NUMBERS, siiiiiiii);
DEFVAR(030C, PLAYER_MADE_PROGRESS, i);
DEFVAR(030D, SET_PROGRESS_TOTAL, i);
DEFVAR(031A, REMOVE_ALL_SCRIPT_FIRES, );
DEFVAR(031D, HAS_CHAR_BEEN_DAMAGED_BY_WEAPON, ii);
DEFVAR(031E, HAS_CAR_BEEN_DAMAGED_BY_WEAPON, ii);
DEFVAR(0321, EXPLODE_CHAR_HEAD, i);
DEFVAR(0323, ANCHOR_BOAT, ib);
DEFVAR(0325, START_CAR_FIRE, iv);
DEFVAR(0326, START_CHAR_FIRE, iv);
DEFVAR(0327, GET_RANDOM_CAR_OF_TYPE_IN_AREA, ffffiv);
DEFVAR(032A, SET_CAMERA_ZOOM, i);
DEFVAR(032B, CREATE_PICKUP_WITH_AMMO, iiifffv);
DEFVAR(0330, SET_PLAYER_NEVER_GETS_TIRED, ib);
DEFVAR(0331, SET_PLAYER_FAST_RELOAD, ib);
DEFVAR(0332, SET_CHAR_BLEEDING, ib);
DEFVAR(0335, SET_FREE_RESPRAYS, b);
DEFVAR(0337, SET_CHAR_VISIBLE, ib);
DEFVAR(0338, SET_CAR_VISIBLE, ib);
DEFVAR(0339, IS_AREA_OCCUPIED, ffffffbbbbb);
DEFVAR(033E, DISPLAY_TEXT, ffs);
DEFVAR(033F, SET_TEXT_SCALE, ff);
DEFVAR(0340, SET_TEXT_COLOUR, iiii);
DEFVAR(0341, SET_TEXT_JUSTIFY, b);
DEFVAR(0342, SET_TEXT_CENTRE, b);
DEFVAR(0343, SET_TEXT_WRAPX, f);
DEFVAR(0344, SET_TEXT_CENTRE_SIZE, f);
DEFVAR(0345, SET_TEXT_BACKGROUND, b);
DEFVAR(0348, SET_TEXT_PROPORTIONAL, b);
DEFVAR(0349, SET_TEXT_FONT, i);
DEFVAR(034D, ROTATE_OBJECT, iffb);
DEFVAR(034E, SLIDE_OBJECT, iffffffb);
DEFVAR(034F, REMOVE_CHAR_ELEGANTLY, i);
DEFVAR(0350, SET_CHAR_STAY_IN_SAME_PLACE, ib);
DEFVAR(0356, IS_EXPLOSION_IN_AREA, iffffff);
DEFVAR(035C, PLACE_OBJECT_RELATIVE_TO_CAR, iifff);
DEFVAR(035D, MAKE_OBJECT_TARGETABLE, ib);//page5



DEFVAR(0362, WARP_CHAR_FROM_CAR_TO_COORD, ifff);
DEFVAR(038B, LOAD_ALL_MODELS_NOW, );
DEFVAR(03FE, SET_CHAR_MONEY, ii);
DEFVAR(0446, SET_CHAR_SUFFERS_CRITICAL_HITS, ib);
DEFVAR(0453, SET_OBJECT_ROTATION, ifff);
DEFVAR(04BB, SET_AREA_VISIBLE, i);
DEFVAR(04CE, ADD_SHORT_RANGE_SPRITE_BLIP_FOR_COORD, fffiv);
DEFVAR(04E4, REQUEST_COLLISION, ff);
DEFVAR(053F, SET_CAN_BURST_CAR_TYRES, ib);
DEFVAR(0570, ADD_SHORT_RANGE_SPRITE_BLIP_FOR_CONTACT_POINT, fffiv);
DEFVAR(0581, DISPLAY_RADAR, b);
DEFVAR(06DF, DELETE_PLAYER, i);
DEFVAR(075E, LOAD_SHOP, s);
DEFVAR(07FE, GIVE_MELEE_ATTACK_TO_CHAR, iii);
DEFVAR(07FF, SET_CAR_HYDRAULICS, ib);
DEFVAR(0826, DISPLAY_HUD, b);
DEFVAR(083E, SET_CHAR_ROTATION, ifff);
DEFVAR(087E, SET_CHAR_DROPS_WEAPONS_WHEN_DEAD, ib);
DEFVAR(0920, CAMERA_SET_VECTOR_TRACK, ffffffib);
DEFVAR(0936, CAMERA_SET_VECTOR_MOVE, ffffffib);
DEFVAR(09BA, DISPLAY_ZONE_NAMES, b);
DEFVAR(09C4, SET_PETROL_TANK_WEAKPOINT, ib);

#endif // __SCRIPTING_H
