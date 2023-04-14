#include QMK_KEYBOARD_H

#define LT_CPS LT(1, KC_CAPS)
#define WIN_LED_IDX 29
#define OSX_LED_IDX 43
#define POE_LED_IDX 57

enum {
      _LAYER0 = 0,
      _LAYER1,
      _LAYER2,
      _LAYER3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LAYER0] = LAYOUT_65_ansi_blocker( /* Win Layer */
                                       QK_GESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL ,     KC_BSPC    , KC_F13  ,
                                       KC_TAB     , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BACKSLASH  , TO(0)  ,
                                       LT_CPS        , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,      KC_ENT      , TO(1)  ,
                                       KC_LSFT            , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,   KC_RSFT   , KC_UP  , TO(2)  ,
                                       KC_LCTL  ,  KC_LGUI ,  KC_LALT ,                KC_SPC                                  ,  KC_RALT ,   TT(3)  ,     KC_LEFT, KC_DOWN, KC_RIGHT),
    [_LAYER1] = LAYOUT_65_ansi_blocker( /* OS X Layer */

                                       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______    , _______  ,
                                       _______    , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______    , _______  ,
                                       _______       , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______     , _______  ,
                                       _______            , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______   , _______, _______  ,
                                       _______  ,  KC_LALT ,  KC_LGUI ,                _______                                 ,  KC_RGUI ,  _______ ,     _______, _______, _______),

    [_LAYER2] = LAYOUT_65_ansi_blocker( /* PoE */
                                       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______    , _______  ,
                                       _______    , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______    , _______  ,
                                       _______       , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______     , _______  ,
                                       _______            , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______   , _______, _______  ,
                                       _______  ,  _______ ,  _______ ,                _______                                 ,  _______ ,  _______ ,     _______, _______, _______),

    [_LAYER3] = LAYOUT_65_ansi_blocker( /* FN, MUSIC Controls */
                                       KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,     KC_DEL     , _______  ,
                                       _______    , KC_BSPC, KC_PGUP, KC_DEL , KC_LBRC, KC_RBRC, _______, _______, KC_UP  , _______, _______, _______, _______, _______    , _______  ,
                                       _______       , KC_HOME, KC_PGDN, KC_END , KC_LCBR, KC_RCBR, _______, KC_LEFT, KC_DOWN,KC_RIGHT, _______, _______,      _______     , _______  ,
                                       _______            , _______, _______, _______, KC_LPRN, KC_RPRN, KC_MPLY, KC_MUTE, KC_MPRV, KC_MNXT, _______,   _______   , KC_BRIU, _______  ,
                                       _______  ,  _______ ,  _______ ,                _______                                 ,  _______ ,  _______ ,     KC_VOLD, KC_BRID, KC_VOLU),

};

void keyboard_post_init_user(void) {
    // Call the post init code.
    rgb_matrix_mode(RGB_MATRIX_NONE);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case 0:
            rgb_matrix_set_color_all(0,0,0);
            rgb_matrix_set_color(WIN_LED_IDX, RGB_BLUE);
            break;
        case 1:
            rgb_matrix_set_color_all(0,0,0);
            rgb_matrix_set_color(OSX_LED_IDX, RGB_BLUE);
            break;
        case 2:
            rgb_matrix_set_color_all(0,0,0);
            rgb_matrix_set_color(POE_LED_IDX, RGB_BLUE);
            break;
        default:
            break;
    }
    return false;
}