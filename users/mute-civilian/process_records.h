#pragma once
#include "mutecivilian.h"

enum userspace_custom_keycodes {
  SARCASM = SAFE_RANGE,
  KC_SEC_1,
  KC_SEC_2,
  KC_SEC_3,
  KC_SEC_4,
  KC_SEC_5,
  KC_SEC_6,
  KC_SEC_7,
  KC_SEC_8,
  KC_SEC_9,
  KC_SEC_10,
  KC_SEC_END
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
void post_process_record_keymap(uint16_t keycode, keyrecord_t *record);
