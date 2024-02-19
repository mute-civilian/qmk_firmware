#include "mutecivilian.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_charybdis_3x5(
    KC_Q   , KC_W  , KC_E    , KC_R  , KC_T       ,                      KC_Y     , KC_U      , KC_I      , KC_O   , KC_P     ,
    KC_CA  , KC_AS , KC_GD   , KC_SF , MOU_G      ,                      MOU_H    , KC_SJ     , KC_GK     , KC_AL  , KC_CSCLN ,
    NAV_Z  , KC_X  , KC_C    , KC_V  , KC_B       ,                      KC_N     , KC_M      , KC_COMM   , KC_DOT , SYM_SLSH ,
                     /* SYM_ENT , KC_NO , WORDS_BACK ,                      MISC_DEL , NAV_SPACE */
                     WORDS_BACK, KC_NO , SYM_ENT ,                      NAV_SPACE, MISC_DEL
  ),

  [_MISC] = LAYOUT_charybdis_3x5(
    _______  , _______ , DESKTOP , _______ , _______ ,                   AM_CYCLE   , _______  , _______ , _______  , QK_BOOT  ,
    AM_LEFT  , DESK_L  , MISSION , DESK_R  , AM_RITE ,                   AM_INC_PAN , AM_1     , AM_2    , AM_3     , AM_CCW   ,
    KC_LCTL  , _______ , _______ , _______ , _______ ,                   AM_DEC_PAN , MS_BACK  , MS_FORE , TAB_BACK , TAB_FORE ,
                         /* ZOO_MIC , KC_NO   , ZOO_CAM ,                   _______    , ZOO_HAND */
                         ZOO_CAM , KC_NO   , ZOO_MIC ,                   ZOO_HAND    , _______
  ),

  [_MOUSE] = LAYOUT_charybdis_3x5(
    _______ , _______ , _______ , _______ , _______ ,                    _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,                    _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , SNIPING , DRGSCRL , _______ ,                    _______ , DRGSCRL , SNIPING , _______ , _______ ,
                        L_CLICK , KC_NO   , R_CLICK ,                    R_CLICK , L_CLICK
  ),

  [_NAV] = LAYOUT_charybdis_3x5(
    _______ , KC_F6      , ALT_U     , _______ , _______  ,             GUI_L      , KC_HOME , KC_END     , GUI_R , _______ ,
    _______ , WEB_B      , ALT_D     , WEB_F   , _______  ,             LEFT       , KC_DOWN , KC_UP      , RIGHT , _______ ,
    _______ , SL_CL_RPAN , SL_EMOJI  , SL_DMS  , SL_LATER ,             ALT_L      , _______ , _______    , ALT_R , _______ ,
                           /* SL_THREAD , KC_NO   , SL_HOME  ,             SCREEN_CAP , _______ */
                           SL_HOME , KC_NO   , SL_THREAD  ,             _______ , SCREEN_CAP
  ),

  [_SYMBOLS] = LAYOUT_charybdis_3x5(
    _______ , _______ , _______  , _______  , _______ ,                  _______ , KC_7 , KC_8   , KC_9 , KC_EQL  ,
    _______ , _______ , KC_GRAVE , KC_TILDE , _______ ,                  _______ , KC_4 , KC_5   , KC_6 , KC_COLN ,
    KC_LSFT , CUT     , COPY     , PASTE    , _______ ,                  KC_RSFT , KC_1 , KC_2   , KC_3 , KC_BSLS ,
                        _______  , KC_NO    , _______ ,                  KC_DOT  , KC_0
  ),

  [_WORDS] = LAYOUT_charybdis_3x5(
    KC_SEC_1 , KC_SEC_2 , KC_SEC_5   , KC_SEC_9 , KC_SEC_10 ,            _______ , _______ , _______ , _______ , SARCASM ,
    KC_SEC_3 , KC_SEC_4 , _______    , _______  , _______   ,            _______ , CAPS    , _______ , _______ , _______ ,
    KC_SEC_7 , KC_SEC_6 , KC_SEC_8   , _______  , _______   ,            _______ , _______ , _______ , _______ , _______ ,
                          /* LGUI(KC_0) , KC_NO    , _______   ,            _______ , _______ */
                          _______ , KC_NO , LGUI(KC_0) ,             _______ , _______
  ),

  /* [_TEMPLATE] = LAYOUT_charybdis_3x5( */
  /*    _______ , _______ , _______ , _______ , _______ ,                   _______ , _______ , _______ , _______ , _______ , */
  /*    _______ , _______ , _______ , _______ , _______ ,                   _______ , _______ , _______ , _______ , _______ , */
  /*    _______ , _______ , _______ , _______ , _______ ,                   _______ , _______ , _______ , _______ , _______ , */
  /*                        _______ , KC_NO   , _______ ,                   _______ , _______ */
  /* ), */
};

layer_state_t layer_state_set_user(layer_state_t state) {
  const layer_state_t current_layer = get_highest_layer(state);
  charybdis_set_pointer_dragscroll_enabled(current_layer == _WORDS);
  return state;
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE]    = { ENCODER_CCW_CW( KC_MS_WH_DOWN,  KC_MS_WH_UP            )},
    [_NAV]     = { ENCODER_CCW_CW( KC_VOLD,        KC_VOLU                )},
    [_SYMBOLS] = { ENCODER_CCW_CW( KC_MS_WH_RIGHT, KC_MS_WH_LEFT          )},
    [_MISC]    = { ENCODER_CCW_CW( KC_NO,          KC_NO                  )},
    [_WORDS]   = { ENCODER_CCW_CW( LGUI(KC_MINUS), (LGUI(LSFT(KC_EQUAL))) )}
};
#endif
