// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "keymap_german.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum planck_layers {
  _QWERTY,
  _QWERTZ,
  _LOWER,
  _RAISE,
  _FUNC,
  _GAMING,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  QWERTZ,
  LOWER,
  RAISE,
  FUNC,
  BACKLIT,
  GAMING
};

enum {
    SH_CP = 0,
    PRV_NXT = 1,
    SEM = 2,
    TT = 3
};


#define ALT_INS LALT(KC_INS)


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define M_AE M(1)
#define M_UE M(2)
#define M_OE M(3)
#define M_SS M(4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| GUI  | Alt  | Ctrl |Lower |Space | Bksp |Raise | Left | Down |  Up  |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {TD(TT),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    KC_LBRC},
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,  KC_K,    KC_L,    TD(SEM), KC_QUOT},
  {TD(SH_CP), KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT },
  {FUNC,    KC_LGUI, KC_LALT, KC_LCTL, LOWER,   KC_SPC,  KC_BSPC, RAISE, LALT(LCTL(KC_DEL)), _______, KC_RCTL, KC_ENT}
},

/* Qwertz
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  |  Ü   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ö  |  Ä   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |Space | Bksp |Raise |CAltDl|      | Ctrl |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTZ] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,     S(DE_UE)},
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    S(DE_OE), S(DE_AE)},
  {TD(SH_CP), KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT },
  {FUNC,    KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_BSPC, RAISE,   LALT(LCTL(KC_DEL)), _______, KC_RCTL,    KC_ENT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   +  | Pg Up|Pg Dn |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  Del |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    _______, _______, _______},
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS,    KC_PLUS,    KC_PGUP, KC_PGDN, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______},
  {_______, _______, _______, _______, _______, _______, KC_DEL,  _______,    _______,    _______, _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |      |      |      |      |      |   {  |   }  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   4  |   5  |   6  |      |      |      |   =  |   _  |   (  |   )  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   7  |   8  |   9  |      |      |      |ISO # |ISO / |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   0  |      |      |             |      | Play | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_BSPC},
  {_______, KC_4,    KC_5,    KC_6,    _______, _______, _______, KC_EQL,  KC_UNDS, KC_LPRN, KC_RPRN, KC_BSLS},
  {_______, KC_7,    KC_8,    KC_9,    _______, _______, _______, KC_NUHS, KC_NUBS, KC_LBRC, KC_RBRC, _______},
  {_______, XXXXXXX, KC_0,    XXXXXXX, _______, _______, _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, TD(PRV_NXT)}
},

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   Ü  |AltIns|   Ö  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   Ä  |   ß  |      |      |      | Left |Right | Down |  Up  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNC] = {
  {_______, _______,  _______, _______, _______, _______, _______, M(1), ALT_INS, M(2), _______, BACKLIT},
  {_______, M(3), M(4), _______, _______, _______, KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT,  _______, _______},
  {_______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______,  _______, _______},
  {_______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______,  _______, _______}
},

/* Gaming
 * ,-----------------------------------------------------------------------------------.
 * | Reset|      |      |      |      |      |  ESC |   1  |   2  |   3  |   4  |   5  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |  TAB |   Q  |   W  |   E  |   R  |   6  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |  ALT |   A  |   S  |   D  |   F  |   7  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Shift|   Z  |   X  |   C  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = {
  {QWERTY,  _______, _______, _______, _______, _______, KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5},
  {_______, _______, _______, _______, _______, _______, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_6},
  {_______, _______, _______, _______, _______, _______, KC_LALT, KC_A, KC_S, KC_D, KC_F, M(0)},
  {_______, _______, _______, _______, _______, _______, KC_LSFT, KC_Z, KC_X, KC_C, KC_SPC, KC_SPC}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|      |      |Qwerty|Qwertz|Gaming|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL },
  {_______, _______, _______, AU_ON,   AU_OFF,  _______, _______, QWERTY,  QWERTZ,  GAMING,  _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
        PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
      }
      return false;
      break;
    case QWERTZ:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTZ);
        PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case FUNC:
      if (record->event.pressed) {
        layer_on(_FUNC);
      } else {
        layer_off(_FUNC);
      }
      return false;
      break;
    case GAMING:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_GAMING);
        PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      }
      return false;
      break;
  }
  return true;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
    switch(id) {
      case 0:
        return MACRO(T(7), T(8), END);
      case 1: // UE
        return MACRO(D(LALT), T(LSFT), U(LALT), T(LBRC), D(LALT), T(LSFT), U(LALT), END);
      case 2: // OE
        return MACRO(D(LALT), T(LSFT), U(LALT), T(SCLN), D(LALT), T(LSFT), U(LALT), END);
      case 3: // AE
        return MACRO(D(LALT), T(LSFT), U(LALT), T(QUOT), D(LALT), T(LSFT), U(LALT), END);
      case 4: // SS
        return MACRO(D(LALT), T(LSFT), U(LALT), T(MINS), D(LALT), T(LSFT), U(LALT), END);
    }
  }
  return MACRO_NONE;
};


void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

void td_sem(qk_tap_dance_state_t *state, void *user_data) {
    switch(state->count) {
        case 1:
            register_code(KC_SCLN);
            unregister_code(KC_SCLN);
            break;
        case 2:
            register_code(KC_ESC);
            unregister_code(KC_ESC);
            register_code(KC_LSFT);
            register_code(KC_A);
            unregister_code(KC_A);
            unregister_code(KC_LSFT);
            register_code(KC_SCLN);
            unregister_code(KC_SCLN);
            register_code(KC_ESC);
            unregister_code(KC_ESC);
            break;
        default:
            for (int i = 0; i < state->count; i++) {
                register_code(KC_SCLN);
                unregister_code(KC_SCLN);
            }
            break;
    }
}

void double_tab(qk_tap_dance_state_t *state, void *user_data) {
    switch(state->count) {
        case 1:
            register_code(KC_TAB);
            unregister_code(KC_TAB);
            break;
        case 2:
            register_code(KC_LSFT);
            register_code(KC_TAB);
            unregister_code(KC_TAB);
            unregister_code(KC_LSFT);
            break;
        default:
            for (int i = 0; i < state->count; i++) {
                register_code(KC_TAB);
                unregister_code(KC_TAB);
            }
            break;
    }
}

void shift_lock_each(qk_tap_dance_state_t *state, void *user_data) {
    register_code(KC_LSFT);
}

void shift_lock_cancel(qk_tap_dance_state_t *state, void *user_data) {
    for (int i = 0; i < state->count; i++) {
        unregister_code(KC_LSFT);
    }
}


void shift_lock_complete(qk_tap_dance_state_t *state, void *user_data) {
    switch(state->count) {
        case 3:
            register_code(KC_CAPS);
            unregister_code(KC_CAPS);
            break;
    }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [SH_CP]  = ACTION_TAP_DANCE_FN_ADVANCED(shift_lock_each, shift_lock_complete, shift_lock_cancel), // ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
  // Double tap media next for media prev
  [PRV_NXT]  = ACTION_TAP_DANCE_DOUBLE(KC_MNXT, KC_MPRV),
  // Double tap ; to get out of insert mode and append ; at the end of the line
  [SEM] = ACTION_TAP_DANCE_FN(td_sem),
  // Double tap TAB to tab backwards
  [TT] = ACTION_TAP_DANCE_FN(double_tab)
};

#endif
