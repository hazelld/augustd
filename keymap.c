#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"

/* Hack to include files since compilation only does this file */
#include "vim.c"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    EPRM,
    RGB_SLD,
    
    /* Have one button press that cycles through all the layers */
    CYCLE_OS_LAYERS,
    
    /* Custom Vim Keycodes */
    VIM_ESCAPE_HATCH,
    VIM_WINDOW_MOVE_LEFT,
    VIM_WINDOW_MOVE_RIGHT,
};

/* Layer names easily defined */
#define __BASE 0
#define __BASE_SHIFT 1

/* OS Specific Layers + the default*/
#define __LINUX 2
#define __MAC 3
#define __DEFAULT_OS __LINUX
    
/* Application Specific Layers */
#define __VIM 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base layout */
    [__BASE] = LAYOUT_ergodox(\
            /* Left Hand */
            KC_DLR,KC_AMPR,KC_LBRACKET,KC_LCBR,KC_RCBR,KC_LPRN,KC_EQUAL, \
            KC_TAB,KC_SCOLON,KC_COMMA,KC_DOT,KC_P,KC_Y,KC_BSLASH, \
            KC_ESCAPE,KC_A,KC_O,KC_E,KC_U,KC_I, \
            MO(__BASE_SHIFT),KC_QUOTE,KC_Q,KC_J,KC_K,KC_X,KC_HYPR, \
            KC_LCTRL,KC_TRANSPARENT,LALT(KC_NO),KC_LEFT,KC_RIGHT,
            /* Left Thumb */
            KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_SPACE,KC_ENTER,TG(__VIM), \
            
            /* Right Hand */
            KC_ASTR,KC_RPRN,KC_PLUS,KC_RBRACKET,KC_EXLM,KC_HASH,KC_BSPACE, \
            KC_AT,KC_F,KC_G,KC_C,KC_R,KC_L,KC_SLASH, \
            KC_D,KC_H,KC_T,KC_N,KC_S,KC_MINUS, \
            KC_MEH,KC_B,KC_M,KC_W,KC_V,KC_Z,KC_RSHIFT, \
            KC_UP,KC_DOWN,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT, \
            /* Right Thumb */
            KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,CYCLE_OS_LAYERS,KC_TAB,KC_ENTER \
            ),

    /* Base layout when shift is pressed */
    [__BASE_SHIFT] = LAYOUT_ergodox(\
            /* Left Hand */ 
            KC_TILD,KC_PERC,KC_7,KC_5,KC_3,KC_1,KC_9,
            KC_TRANSPARENT,KC_COLN,KC_LABK,KC_RABK,LSFT(KC_P),LSFT(KC_Y),LSFT(KC_BSLASH),
            KC_TRANSPARENT,LSFT(KC_A),LSFT(KC_O),LSFT(KC_E),LSFT(KC_U),LSFT(KC_I),
            KC_TRANSPARENT,KC_DQUO,LSFT(KC_Q),LSFT(KC_J),LSFT(KC_K),LSFT(KC_X),KC_TRANSPARENT,
            KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
            /* Left Thumb */
            KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
            
            /* Right Hand */
            KC_0,KC_2,KC_4,KC_6,KC_8,KC_GRAVE,KC_TRANSPARENT,
            KC_CIRC,LSFT(KC_F),LSFT(KC_G),LSFT(KC_C),LSFT(KC_R),LSFT(KC_L),KC_QUES,
            LSFT(KC_D),LSFT(KC_H),LSFT(KC_T),LSFT(KC_N),LSFT(KC_S),KC_UNDS,
            KC_TRANSPARENT,LSFT(KC_B),LSFT(KC_M),LSFT(KC_W),LSFT(KC_V),LSFT(KC_Z),KC_TRANSPARENT,
            KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
            /* Right Thumb */
            KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),
 
    /* Linux specific shortcuts */
    [__LINUX] = LAYOUT_ergodox( \
            /* Left Hand */ 
            _______, _______, _______, _______, _______, _______, _______,  
            _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, 
            /* Left Thumb */
            _______, _______, _______, _______, _______, _______, 

            /* Right Hand */ 
            _______, _______, _______, _______, _______, _______, _______,  
            _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, 
            /* Right Thumb */
            _______, _______, _______, _______, _______, _______ \
    ),

    /* Mac specific shortcuts */
    [__MAC] = LAYOUT_ergodox( \
            /* Left Hand */ 
            _______, _______, _______, _______, _______, _______, _______,  
            _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, 
            /* Left Thumb */
            _______, _______, _______, _______, _______, _______, 

            /* Right Hand */ 
            _______, _______, _______, _______, _______, _______, _______,  
            _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, 
            /* Right Thumb */
            _______, _______, _______, _______, _______, _______ \
    ),

    /* Vim specific layouts */
    [__VIM] = LAYOUT_ergodox( \
            /* Left Hand */ 
            _______, _______, _______, _______, _______, _______, _______,  
            _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, VIM_WINDOW_MOVE_LEFT, VIM_WINDOW_MOVE_RIGHT, 
            /* Left Thumb */
            _______, _______, _______, _______, VIM_ESCAPE_HATCH, _______, 

            /* Right Hand */ 
            _______, _______, _______, _______, _______, _______, _______,  
            _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, _______, _______, 
            _______, _______, _______, _______, _______, 
            /* Right Thumb */
            _______, _______, _______, _______, _______, _______ \
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // dynamically generate these.
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
            break;
        
        case CYCLE_OS_LAYERS:
            if (record->event.pressed) {
                if (IS_LAYER_ON(__LINUX)) {
                    layer_off(__LINUX);
                    layer_on(__MAC);
                    break;
                }

                if (IS_LAYER_ON(__MAC)) {
                    layer_off(__MAC);
                    layer_on(__LINUX);
                }
            }
            return false;
            break;

        case VIM_ESCAPE_HATCH:
            if (record->event.pressed) {
                vim_escape_hatch();
            }
            return false;
            break;

        case VIM_WINDOW_MOVE_LEFT:
            if (record->event.pressed) { vim_window_move_left(); }
            return false;

        case VIM_WINDOW_MOVE_RIGHT:
            if (record->event.pressed) { vim_window_move_right(); }
            return false;
    }
    return true;
}

/* On initialization of the keyboard, set the default OS layer */
void matrix_init_user(void) {
    layer_on(__DEFAULT_OS);
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
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
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }
    return state;

};
