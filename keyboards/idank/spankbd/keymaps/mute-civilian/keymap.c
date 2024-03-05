#include "mutecivilian.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x5_3(
    KC_Q   , KC_W  , KC_E    , KC_R       , KC_T    ,                  KC_Y      , KC_U     , KC_I     , KC_O   , KC_P     ,
    KC_CA  , KC_AS , KC_GD   , KC_SF      , MOU_G   ,                  MOU_H     , KC_SJ    , KC_GK    , KC_AL  , KC_CSCLN ,
    NAV_Z  , KC_X  , KC_C    , KC_V       , KC_B    ,                  KC_N      , KC_M     , KC_COMM  , KC_DOT , SYM_SLSH ,
                     DOC_SZ  , WORDS_BACK , SYM_ENT ,                  NAV_SPACE , MISC_DEL , ZOO_HAND
                     /* DOC_SZ  , SYM_ENT , WORDS_BACK ,                  MISC_DEL , NAV_SPACE , ZOO_HAND */
  ),

  [_MISC] = LAYOUT_split_3x5_3(
    _______  , _______ , DESKTOP , _______ , _______ ,                 AM_CYCLE   , _______ , _______ , _______  , QK_BOOT  ,
    AM_LEFT  , DESK_L  , MISSION , DESK_R  , AM_RITE ,                 AM_INC_PAN , AM_1    , AM_2    , AM_3     , AM_CCW   ,
    KC_LCTL  , _______ , _______ , _______ , _______ ,                 AM_DEC_PAN , MS_BACK , MS_FORE , TAB_BACK , TAB_FORE ,
                         _______ , ZOO_CAM , ZOO_MIC ,                 ZOO_HAND   , _______ , _______
  ),

  [_MOUSE] = LAYOUT_split_3x5_3(
    _______ , _______ , _______ , _______ , _______ ,                   _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,                   _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , KC_VOLD , KC_VOLU ,                   KC_VOLD , KC_VOLU , _______ , _______ , _______ ,
                        _______ , R_CLICK , L_CLICK ,                   L_CLICK , R_CLICK , _______
  ),

  [_NAV] = LAYOUT_split_3x5_3(
    _______ , KC_F6      , ALT_U    , _______  , _______  ,             GUI_L   , KC_HOME    , KC_END  , GUI_R , _______ ,
    _______ , WEB_B      , ALT_D    , WEB_F    , _______  ,             LEFT    , KC_DOWN    , KC_UP   , RIGHT , _______ ,
    _______ , SL_CL_RPAN , SL_EMOJI , SL_DMS   , SL_LATER ,             ALT_L   , _______    , _______ , ALT_R , _______ ,
                           _______  , SL_THREAD , SL_HOME ,             _______ , SCREEN_CAP , _______
  ),

  [_SYMBOLS] = LAYOUT_split_3x5_3(
    _______ , _______ , _______  , _______  , _______ ,                 _______ , KC_7 , KC_8    , KC_9 , KC_EQL  ,
    _______ , _______ , KC_GRAVE , KC_TILDE , _______ ,                 _______ , KC_4 , KC_5    , KC_6 , KC_COLN ,
    KC_LSFT , CUT     , COPY     , PASTE    , _______ ,                 KC_RSFT , KC_1 , KC_2    , KC_3 , KC_BSLS ,
                        _______  , _______  , _______ ,                 KC_DOT  , KC_0 , _______
  ),

  [_WORDS] = LAYOUT_split_3x5_3(
    KC_SEC_1 , KC_SEC_2 , KC_SEC_5 , KC_SEC_8 , KC_SEC_10  ,            _______ , _______ , _______ , _______ , SARCASM ,
    KC_SEC_3 , KC_SEC_4 , _______  , _______  , _______    ,            _______ , CAPS    , _______ , _______ , _______ ,
    KC_SEC_7 , KC_SEC_6 , KC_SEC_9 , _______  , _______    ,            _______ , _______ , _______ , _______ , _______ ,
                          _______  , _______  , LGUI(KC_0) ,            _______ , _______ , _______
                          /* _______  , LGUI(KC_0)  , _______ ,            _______ , _______ , _______ */
  ),

  /* [_TEMPLATE] = LAYOUT_split_3x5_3( */
  /*    _______ , _______ , _______ , _______ , _______ ,                   _______ , _______ , _______ , _______ , _______ , */
  /*    _______ , _______ , _______ , _______ , _______ ,                   _______ , _______ , _______ , _______ , _______ , */
  /*    _______ , _______ , _______ , _______ , _______ ,                   _______ , _______ , _______ , _______ , _______ , */
  /*                        _______ , _______ , _______ ,                   _______ , _______ , _______*/
  /* ), */
};
