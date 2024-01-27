#include "mutecivilian.h"
#include <stdio.h>

char wpm_str[10];

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_Q   , KC_W  , KC_E       , KC_R  , KC_T ,  MUTE , KC_Y , KC_U  , KC_I      , KC_O   , KC_P      ,
    KC_CA  , KC_AS , KC_GD      , KC_SF , KC_G ,         KC_H , KC_SJ , KC_GK     , KC_AL  , KC_CSCLN  ,
    NAV_Z  , KC_X  , KC_C       , KC_V  , KC_B ,         KC_N , KC_M  , KC_COMM   , KC_DOT , SYM_SLSH ,
                     CAPS_MOUSE ,    SYM_ENT   ,           NAV_SPACE  , MISC_DASH
  ),

#ifdef RGB_MATRIX_ENABLE
  [_MISC] = LAYOUT(
    RGB_MOD  , RGB_VAI , RGB_HUI , RGB_SAI , _______ , RGB_TOG , _______ , _______   , _______   , _______ , SARCASM ,
    RGB_RMOD , RGB_VAD , RGB_HUD , RGB_SAD , _______ ,           _______ , VOL_D     , VOL_U     , MUTE    , _______ ,
    _______  , _______ , _______ , _______ , QK_BOOT ,           _______ , SCRN_DARK , SCRN_BRIT , _______ , _______ ,
                         _______ ,      _______      ,                _______        , _______
  ),
#else
  [_MISC] = LAYOUT(
    _______ , _______ , DESKTOP , _______ , ______  , _______ , _______ , _______ , _______ , _______ , SARCASM ,
    _______ , DESK_L  , MISSION , DESK_R  , _______ ,           _______ , VOL_D   , VOL_U   , MUTE    , _______ ,
    _______ , _______ , _______ , _______ , QK_BOOT ,           _______ , _______ , _______ , _______ , _______ ,
                        _______ ,      _______      ,                _______      , _______
  ),
#endif

  [_MOUSE] = LAYOUT(
    KC_SECRET_1 , KC_SECRET_2 , _______ , KC_ACL2 ,  _______ , _______ , MS_BACK    , AM_1       , AM_2     , MS_FORE     , _______ ,
    KC_SECRET_3 , KC_SECRET_4 , _______ , KC_ACL1 ,  _______ ,           KC_MS_LEFT , KC_MS_DOWN , KC_MS_UP , KC_MS_RIGHT , _______ ,
    _______     , _______     , _______ , KC_ACL0 ,  _______ ,           KC_LGUI    , KC_LSFT    , TAB_BACK , TAB_FORE    , _______ ,
                                _______ ,      KC_ACL2       ,                   L_CLICK         , R_CLICK
  ),

  [_NAV] = LAYOUT(
    _______ , KC_F6   , ALT_U   , _______ , _______ , _______ , GUI_L , KC_HOME , KC_END     , GUI_R , _______ ,
    _______ , WEB_B   , ALT_D   , WEB_F   , _______ ,           LEFT  , KC_DOWN , KC_UP      , RIGHT , _______ ,
    _______ , _______ , _______ , _______ , _______ ,           ALT_L , _______ , _______    , ALT_R , _______ ,
                        _______ ,     _______       ,               _______     , SCREEN_CAP
  ),

  [_SYMBOLS] = LAYOUT(
    KC_RCBR , KC_RBRC , R_PAREN , KC_GRAVE , _______ , _______ , _______ , KC_7 , KC_8   , KC_9 , KC_EQL  ,
    KC_LCBR , KC_LBRC , L_PAREN , KC_TILDE , _______ ,           _______ , KC_4 , KC_5   , KC_6 , KC_COLN ,
    KC_LSFT , CUT     , COPY    , PASTE    , _______ ,           KC_RSFT , KC_1 , KC_2   , KC_3 , KC_BSLS ,
                        _______ ,       _______      ,                 KC_0     , KC_DOT
  ),

  /* [_TEMPLATE] = LAYOUT( */
    /* _______ , _______ , _______ , _______ ,  _______ , _______ , _______ , _______ , _______ , _______ , _______ , */
  /*   _______ , _______ , _______ , _______ ,  _______ ,           _______ , _______ , _______ , _______ , _______ , */
  /*   _______ , _______ , _______ , _______ ,  _______ ,           _______ , _______ , _______ , _______ , _______ , */
  /*                       _______ ,      _______       ,                _______      , _______ */
  /* ), */
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_90;
}

void render_lechiffre_logo(void) {
  static const char PROGMEM lechiffre_logo[] = {
  // 'lechiffre_logo', 32x20px
   0x00, 0x3e, 0x20, 0x20, 0x00, 0x18, 0x2c, 0xa8, 0x80, 0x00, 0x1c, 0x22, 0x22, 0x00, 0x3e, 0x08,
0x30, 0x00, 0x34, 0x00, 0x3c, 0x0a, 0x00, 0xbc, 0x8a, 0x00, 0x38, 0x08, 0x00, 0x18, 0x2c, 0x28,
0x00, 0xb6, 0xb6, 0x00, 0xdb, 0xdb, 0x00, 0x6d, 0x6d, 0x00, 0xdb, 0xdb, 0x00, 0xdb, 0xdb, 0x00,
0x00, 0xdb, 0xdb, 0x00, 0xdb, 0xdb, 0x00, 0x6d, 0x6d, 0x00, 0xdb, 0xdb, 0x00, 0xb6, 0xb6, 0x00,
0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00,
0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00
};

  oled_write_raw_P(lechiffre_logo, sizeof(lechiffre_logo));
}

static void render_layer_status(void) {
  oled_write_ln_P(PSTR(" "), false);
  switch (get_highest_layer(layer_state)) {
    case _BASE:
      oled_write_P(PSTR("BASIC"), false);
      break;
    case _SYMBOLS:
      oled_write_P(PSTR("SYMBL"), false);
      break;
    case _NAV:
      oled_write_P(PSTR("NAVIG"), false);
      break;
    case _MISC:
      oled_write_P(PSTR("MISCL"), false);
      break;
    case _MOUSE:
      oled_write_P(PSTR("MOUSE"), false);
      break;
    default:
      oled_write_P(PSTR("?????"), false);
    }
}

void render_keylock_status(led_t led_state) {
  oled_write_ln_P(PSTR(" "), false);
  oled_write_P(PSTR("W "), caps_word_get());
  oled_write_P(PSTR("CAP"), (caps_word_get() || led_state.caps_lock));
}

void render_mod_status(uint8_t modifiers) {
  static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
  static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
  static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
  static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

  static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
  static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
  static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
  static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

  static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
  static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
  static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
  static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

  static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
  static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
  static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
  static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

  // fillers between the modifier icons bleed into the icon frames
  static const char PROGMEM off_off_1[] = {0xc5, 0};
  static const char PROGMEM off_off_2[] = {0xc6, 0};
  static const char PROGMEM on_off_1[] = {0xc7, 0};
  static const char PROGMEM on_off_2[] = {0xc8, 0};
  static const char PROGMEM off_on_1[] = {0xc9, 0};
  static const char PROGMEM off_on_2[] = {0xca, 0};
  static const char PROGMEM on_on_1[] = {0xcb, 0};
  static const char PROGMEM on_on_2[] = {0xcc, 0};

  oled_write_ln_P(PSTR(" "), false);

  if(modifiers & MOD_MASK_CTRL) {
      oled_write_P(ctrl_on_1, false);
  } else {
      oled_write_P(ctrl_off_1, false);
  }

  if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
      oled_write_P(on_on_1, false);
  } else if(modifiers & MOD_MASK_CTRL) {
      oled_write_P(on_off_1, false);
  } else if(modifiers & MOD_MASK_SHIFT) {
      oled_write_P(off_on_1, false);
  } else {
      oled_write_P(off_off_1, false);
  }

  if(modifiers & MOD_MASK_SHIFT) {
      oled_write_P(shift_on_1, false);
  } else {
      oled_write_P(shift_off_1, false);
  }

  if(modifiers & MOD_MASK_CTRL) {
      oled_write_P(ctrl_on_2, false);
  } else {
      oled_write_P(ctrl_off_2, false);
  }

  if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
      oled_write_P(on_on_2, false);
  } else if(modifiers & MOD_MASK_CTRL) {
      oled_write_P(on_off_2, false);
  } else if(modifiers & MOD_MASK_SHIFT) {
      oled_write_P(off_on_2, false);
  } else {
      oled_write_P(off_off_2, false);
  }

  if(modifiers & MOD_MASK_SHIFT) {
      oled_write_P(shift_on_2, false);
  } else {
      oled_write_P(shift_off_2, false);
  }

  if(modifiers & MOD_MASK_GUI) {
      oled_write_P(gui_on_1, false);
  } else {
      oled_write_P(gui_off_1, false);
  }

  if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
      oled_write_P(on_on_1, false);
  } else if(modifiers & MOD_MASK_GUI) {
      oled_write_P(on_off_1, false);
  } else if(modifiers & MOD_MASK_ALT) {
      oled_write_P(off_on_1, false);
  } else {
      oled_write_P(off_off_1, false);
  }

  if(modifiers & MOD_MASK_ALT) {
      oled_write_P(alt_on_1, false);
  } else {
      oled_write_P(alt_off_1, false);
  }

  if(modifiers & MOD_MASK_GUI) {
      oled_write_P(gui_on_2, false);
  } else {
      oled_write_P(gui_off_2, false);
  }

  if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
      oled_write_P(on_on_2, false);
  } else if(modifiers & MOD_MASK_GUI) {
      oled_write_P(on_off_2, false);
  } else if(modifiers & MOD_MASK_ALT) {
      oled_write_P(off_on_2, false);
  } else {
      oled_write_P(off_off_2, false);
  }

  if(modifiers & MOD_MASK_ALT) {
      oled_write_P(alt_on_2, false);
  } else {
      oled_write_P(alt_off_2, false);
  }
}

static void render_wpm(void) {
  oled_write_ln_P(PSTR(" "), false);
  sprintf(wpm_str, " %03d", get_current_wpm());
  oled_write(wpm_str, false);
}

void oled_task_user(void) {
  render_lechiffre_logo();
  oled_set_cursor(0,3);
  render_layer_status();
  render_mod_status(get_mods()|get_oneshot_mods());
  render_keylock_status(host_keyboard_led_state());
  render_wpm();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_caps_word(keycode, record)) { return false; }

  static bool tAuNtTeXt = false;

  if (tAuNtTeXt) {
    if (record->event.pressed) {
      if (keycode != KC_SPC) {
        tap_code(KC_CAPS);
      }
    }
  }

  switch (keycode) {
    case SARCASM:
      if (record->event.pressed) {
        tAuNtTeXt = !tAuNtTeXt;
        if (tAuNtTeXt) {
          tap_code(KC_CAPS);
        }
        else if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
          tap_code(KC_CAPS);
        }
      }
      return false;

    default:
      return true;
  }
}
#endif
