#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define MDIA 1 // media keys
#define SYMB 2 // symbols
#define WINM 3 // window movement
#define MOUM 4 // mouse movement

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |  `   |           |  -   |   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  ~L1   |   Q  |   W  |   E  |   R  |   T  | Tab  |           | Back |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  ~L2   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  L2/'  |
 * |--------+------+------+------+------+------| ~L3  |           | Ret  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  L1  |  L2  |  L3  |  L4  | Alt  |                                       |  Alt | CAPS |      |  ~L1 | ~L2  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | LWin | RWin |       | LScr | RScr   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | LAlt |       | RAlt |        |      |
 *                                 | LCtl |Space |------|       |------| Space  | RCtl |
 *                                 |      |      | LGui |       | RGui |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
//KC_EQL
//KC_DELT
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,       KC_1,         KC_2,           KC_3,     KC_4,      KC_5,   KC_GRV,
        MO(1),        KC_Q,         KC_W,           KC_E,     KC_R,      KC_T,   KC_TAB,
        MO(2),        KC_A,         KC_S,           KC_D,     KC_F,      KC_G,
        KC_LSFT,      KC_Z,         KC_X,           KC_C,     KC_V,      KC_B,   MO(3),
        TG(1),        TG(2),        TG(3),          TG(4),    KC_LALT,

                                              LALT(KC_LEFT),   LALT(KC_RIGHT),
                                                               KC_LALT,
                                              KC_LCTL, KC_SPC, KC_LGUI,

        // right hand
             KC_MINS,     KC_6,   KC_7,      KC_8,      KC_9,      KC_0,           KC_EQL,
             KC_BSPC,     KC_Y,   KC_U,      KC_I,      KC_O,      KC_P,           KC_BSLS,
                          KC_H,   KC_J,      KC_K,      KC_L,      KC_SCLN,        LT(2, KC_QUOT),
             KC_ENT,      KC_N,   KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,        KC_RSFT,
                                  KC_LALT,   KC_CAPS,   KC_TRNS,   MO(1),          MO(2),

             LCTL(KC_LEFT),  LCTL(KC_RIGHT),
             KC_RALT,
             KC_RGUI, KC_SPC, KC_RCTL
    ),
/* Keymap 1: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      | Home |PGDown| PGUp | End  |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------| Left | Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | Prev |VolDn | VolUp| Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Play |      |      |      | Mute |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |ScLeft|ScRigh|       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | ScUp |       |      |Brwser|Brwser|
 *                                 | Lclk | Rclk |------|       |------|Back  |Fwd   |
 *                                 |      |      |ScDown|       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MS_U,  KC_TRNS,  KC_TRNS,   KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

                                           KC_WH_L, KC_WH_R,
                                                    KC_WH_U,
                                  KC_BTN1, KC_BTN2, KC_WH_D,
    // right hand
       KC_TRNS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   KC_F11,
       KC_TRNS,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,    KC_TRNS,  KC_F12,
                 KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_F13,   KC_VOLD,  KC_VOLU,  KC_F14,   KC_TRNS,  KC_TRNS,
       /* KC_TRNS,  KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,   KC_TRNS,  KC_TRNS, */
       /* KC_TRNS,  KC_MRWD,  KC_VOLD,  KC_VOLU,  KC_MFFD,   KC_TRNS,  KC_TRNS,  /\* OSX Media Keys *\/ */
                           KC_MPLY,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_MUTE,

       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_WBAK, KC_WFWD
),
/* Keymap 2: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Reset |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   -  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   [  |   ]  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   (  |   )  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0   |  0  |   .  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       RESET,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_TRNS,
       KC_TRNS,  KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,  KC_PIPE,  KC_TRNS,
       KC_TRNS,  KC_HASH,  KC_DLR,   KC_LBRC,  KC_RBRC,  KC_GRV,
       KC_TRNS,  KC_PERC,  KC_CIRC,  KC_LPRN,  KC_RPRN,  KC_TILD,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS,  KC_F6,    KC_F7,  KC_F8,   KC_F9,   KC_F10,   KC_F11,
       KC_TRNS,  KC_UP,    KC_7,   KC_8,    KC_9,    KC_MINS,  KC_F12,
                 KC_DOWN,  KC_4,   KC_5,    KC_6,    KC_PLUS,  KC_TRNS,
       KC_TRNS,  KC_AMPR,  KC_1,   KC_2,    KC_3,    KC_BSLS,  KC_TRNS,
                           KC_0,   KC_0,    KC_DOT,  KC_EQL,   KC_TRNS,

       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 3: Window movement
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |Lnch6 |Lnch7 |Lnch8 |Lnch9 |Lnch0 | Lock   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           | Repo2|MWinL |MWinD |MWinU |MWinR |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| WinL | WinD | WinU | WinR |      |        |
 * |--------+------+------+------+------+------|      |           | Repo |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |ScreeL|      | Max  |ScreeR|      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |Lnch1 |Lnch2 |Lnch3 |Lnch4 |Lnch5  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      | Menu |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Window movement
[WINM] = KEYMAP(
       // left hand
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

                                         KC_TRNS,  KC_TRNS,
                                                   KC_TRNS,
                               KC_TRNS,  KC_TRNS,  KC_TRNS,
       // right hand
       KC_TRNS,                  RGUI(RALT(KC_6)),    RGUI(RALT(KC_7)),    RGUI(RALT(KC_8)),    RGUI(RALT(KC_9)),     RGUI(RALT(KC_0)),  RGUI(RALT(KC_BSPC)),
       LCTL(RGUI(RALT(KC_ENT))), RGUI(RALT(KC_LEFT)), RGUI(RALT(KC_DOWN)), RGUI(RALT(KC_UP)),   RGUI(RALT(KC_RIGHT)), KC_TRNS,           KC_TRNS,
                                 RALT(KC_LEFT),       RALT(KC_DOWN),       RALT(KC_UP),         RALT(KC_RGHT),        KC_TRNS,           KC_TRNS,
       RGUI(RALT(KC_ENT)),       LCTL(KC_LEFT),       KC_NO,               RGUI(RALT(KC_PGUP)), LCTL(KC_RIGHT),       KC_TRNS,           KC_TRNS,
                                                      RGUI(RALT(KC_1)),    RGUI(RALT(KC_2)),    RGUI(RALT(KC_3)),     RGUI(RALT(KC_4)),  RGUI(RALT(KC_5)),
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, LCTL(KC_F2)
),

/* Keymap 4: Mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | MsUp |      |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |MsLeft|MsDown|MsRght|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Lclk |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |ScLeft|ScRght|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | ScUp |      |      |
 *                                 |      |      |------|       |------| Rclk | Lclk |
 *                                 |      |      |      |       |ScDown|      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MOUM] = KEYMAP(
       KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   KC_F11,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MS_U,  KC_TRNS,   KC_TRNS,  KC_F12,
                 KC_TRNS,  KC_MS_L,  KC_MS_D,  KC_MS_R,   KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
                           KC_BTN1,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,

       KC_WH_R, KC_WH_L,
       KC_WH_D,
       KC_WH_U, KC_BTN2, KC_BTN1
)

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
          ergodox_right_led_3_on();
          break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
