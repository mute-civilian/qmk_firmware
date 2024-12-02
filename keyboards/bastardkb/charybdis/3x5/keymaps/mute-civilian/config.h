#pragma once

#define CHARYBDIS_DRAGSCROLL_REVERSE_Y
#define CHARYBDIS_MINIMUM_SNIPING_DPI 400

/* home keeb*/
/* #define CHARYBDIS_MINIMUM_DEFAULT_DPI 1750 */
/* office keeb */
#define CHARYBDIS_MINIMUM_DEFAULT_DPI 2000
#undef ROTATIONAL_TRANSFORM_ANGLE
#define ROTATIONAL_TRANSFORM_ANGLE -45

#ifdef ENCODER_ENABLE
/* home keeb */
  /* #define ENCODER_RESOLUTIONS { 4 } */
/* office keeb */
  #define ENCODER_RESOLUTIONS { 2 }

  #if !(defined(KEYBOARD_bastardkb_charybdis_3x5_v2_splinky_3))
    #define ENCODERS_PAD_A { B2 }
    #define ENCODERS_PAD_B { B1 }
  #else
    #define ENCODERS_PAD_A { GP23 }
    #define ENCODERS_PAD_B { GP22 }
  #endif

  #define ENCODERS_PAD_A_RIGHT {  }
  #define ENCODERS_PAD_B_RIGHT {  }
  #define ENCODER_RESOLUTIONS_RIGHT {  }
#endif
