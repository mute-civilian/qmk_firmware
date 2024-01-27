#include "mutecivilian.h"

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_F):
           return TAPPING_TERM - 100;
        case RSFT_T(KC_J):
            return TAPPING_TERM - 100;
        case LT(_SYMBOLS, KC_ENT):
            return TAPPING_TERM - 75;
        case LT(_NAV, KC_SPC):
            return TAPPING_TERM - 75;
        default:
           return TAPPING_TERM;
    }
}
#endif

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;
        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
        case KC_AMPERSAND:
            return true;
        default:
            return false;  // Deactivate Caps Word.
    }
}
