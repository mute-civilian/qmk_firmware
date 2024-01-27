#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _MOUSE,
  _SIDESCROLL,
 _WORDS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

enum {
    TD_COPY_PASTE,
};

enum layers {
  _BASE,
  _MOUSE,
  _SIDESCROLL,
 _WORDS,
};

/* Mission Control */
  #define DESK_L RCTL(KC_LEFT)
  #define DESK_R RCTL(KC_RIGHT)
  #define DESKTOP KC_F11
  #define MISSION RCTL(KC_UP)
/* Audio */
  #define MUTE KC_AUDIO_MUTE
/* Amethyst */
  #define AM_1 KC_F4
  /* #define AM_1_SS LT(_SIDESCROLL, KC_F4) */
  #define AM_2 KC_F2
  #define AM_RITE LALT(LCTL(LSFT(KC_2)))
  #define AM_LEFT LALT(LCTL(LSFT(KC_1)))
  #define VOL_D KC_AUDIO_VOL_DOWN
  #define VOL_U KC_AUDIO_VOL_UP
  #define MUTE KC_AUDIO_MUTE
/* Amethyst */
  #define AM_1 KC_F4
  /* #define AM_1_SS LT(_SIDESCROLL, KC_F4) */
  #define AM_2 KC_F2
  #define AM_3 KC_F3
  #define AM_LEFT LALT(LCTL(LSFT(KC_2)))
  #define AM_RITE LALT(LCTL(LSFT(KC_1)))
  #define AM_RITE LALT(LCTL(LSFT(KC_2)))
  #define AM_LEFT LALT(LCTL(LSFT(KC_1)))
  #define AM_CYCLE LSFT(LALT(LCTL(KC_SPC)))
  #define AM_CW LSFT(LALT(KC_J))
  #define AM_CCW LSFT(LALT(KC_K))
/* ALT Arrows */
  /* #define ALT_U RALT(KC_DOWN) */
  /* #define ALT_D RALT(KC_UP) */
/* Google Meet */
  #define MUTE_MIC LGUI(KC_D)
  #define MUTE_CAM LGUI(KC_E)
  #define RAZ_HAND LCTL(LGUI(KC_H))
/* Google Meet */
  #define MUTE_MIC LGUI(KC_D)
  #define MUTE_CAM LGUI(KC_E)
/* MISC */
  #define COPY LGUI(KC_C)
  #define PASTE LGUI(KC_V)
/* MOUSE */
  #define L_CLICK KC_MS_BTN1
  #define R_CLICK KC_MS_BTN2
  /* These are mapped in SteerMouse */
  #define MS_BACK KC_MS_BTN4
  #define MS_FORE KC_MS_BTN5

  #define TAB_BACK LCTL(LSFT(KC_TAB))
  #define TAB_FORE LCTL(KC_TAB)

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case _WORDS:
      writePinHigh(LED_GREEN);
      writePinHigh(LED_RED);
      break;
    case _SIDESCROLL:
      writePinHigh(LED_GREEN);
      writePinLow(LED_RED);
      break;
    case _MOUSE:
      writePinLow(LED_GREEN);
      writePinHigh(LED_RED);
      break;
    default:
      writePinLow(LED_GREEN);
      writePinLow(LED_RED);
      break;
  }
  return state;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_4x4(
    MUTE     , _______  , _______  , _______ ,
    _______  , _______  , _______  , _______ ,
    _______  , _______  , _______  , _______ ,
    MUTE_MIC , MUTE_CAM , RAZ_HAND , _______
  ),

  /* [_TEMPLATE] = LAYOUT_ortho_4x4( */
  /*    _______ , _______ , _______ , _______ , */
  /*    _______ , _______ , _______ , _______ , */
  /*    _______ , _______ , _______ , _______ , */
  /*    _______ , _______ , _______ , _______ */
  /* ), */
};

// Set led state during powerup
/* void keyboard_post_init_user(void) { */
/*     writePinHigh(LED_RED); */
/* } */

bool encoder_update_user(uint8_t index, bool clockwise) {

  #define TAB_BACK LCTL(LSFT(KC_TAB))
  #define TAB_FORE LCTL(KC_TAB)

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_COPY_PASTE] = ACTION_TAP_DANCE_DOUBLE(COPY, PASTE),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case _WORDS:
      writePinHigh(LED_GREEN);
      writePinHigh(LED_RED);
      break;
    case _SIDESCROLL:
      writePinHigh(LED_GREEN);
      writePinLow(LED_RED);
      break;
    case _MOUSE:
      writePinLow(LED_GREEN);
      writePinHigh(LED_RED);
      break;
    default:
      writePinLow(LED_GREEN);
      writePinLow(LED_RED);
      break;
  }
  return state;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_4x4(
    MUTE     , _______  , _______  , _______ ,
    _______  , _______  , _______  , _______ ,
    _______  , _______  , _______  , _______ ,
    MUTE_MIC , MUTE_CAM , RAZ_HAND , _______
  ),

  /* [_TEMPLATE] = LAYOUT_ortho_4x4( */
  /*    _______ , _______ , _______ , _______ , */
  /*    _______ , _______ , _______ , _______ , */
  /*    _______ , _______ , _______ , _______ , */
  /*    _______ , _______ , _______ , _______ */
  /* ), */
};

// Set led state during powerup
/* void keyboard_post_init_user(void) { */
/*     writePinHigh(LED_RED); */
/* } */

bool encoder_update_user(uint8_t index, bool clockwise) {
/*
Rev1
,-----------------------,
|  E1 |     |     |  E2 |
|-----+-----+-----+-----|
|     |     |     |     |
|-----+-----+-----+-----|
|     |     |     |     |
|-----+-----+-----+-----|
|     |     |     |     |
`-----------------------'
 */

  // First encoder (E1)
  if (index == 0) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  // Second encoder (E2)
  } else if (index == 1) {
    if (IS_LAYER_ON(_SIDESCROLL)) {
      if (clockwise) {
        tap_code(KC_MS_WH_RIGHT);
      } else {
        tap_code(KC_MS_WH_LEFT);
      }
    } else {
      if (clockwise) {
        tap_code(KC_MS_WH_UP);
      } else {
        tap_code(KC_MS_WH_DOWN);
      }
    }
  }
  return true;
    if (clockwise) {
      tap_code(KC_PGDN);
    } else {
      if (clockwise) {
        tap_code(KC_MS_WH_UP);
      } else {
        tap_code(KC_MS_WH_DOWN);
      }
    }
  }
}
