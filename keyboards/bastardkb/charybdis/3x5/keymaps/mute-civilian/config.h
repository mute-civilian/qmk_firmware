#pragma once

#define CHARYBDIS_DRAGSCROLL_REVERSE_Y
#define CHARYBDIS_MINIMUM_SNIPING_DPI 400

#if defined(KEYBOARD_bastardkb_charybdis_3x5_v2_splinky_3)
  #define CHARYBDIS_MINIMUM_DEFAULT_DPI 1750
  #undef ROTATIONAL_TRANSFORM_ANGLE
  #define ROTATIONAL_TRANSFORM_ANGLE -45
#else
  #define CHARYBDIS_MINIMUM_DEFAULT_DPI 1200
#endif

#ifdef ENCODER_ENABLE

  #if defined(KEYBOARD_bastardkb_charybdis_3x5_v2_splinky_3)
    #define ENCODERS_PAD_A { GP23 }
    #define ENCODERS_PAD_B { GP22 }
    #define ENCODER_RESOLUTIONS { 2 }
  #else
    #define ENCODERS_PAD_A { B2 }
    #define ENCODERS_PAD_B { B1 }
    #define ENCODER_RESOLUTIONS { 4 }
  #endif

  #define ENCODERS_PAD_A_RIGHT {  }
  #define ENCODERS_PAD_B_RIGHT {  }
  #define ENCODER_RESOLUTIONS_RIGHT {  }
#endif
