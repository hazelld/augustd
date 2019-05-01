/**
 * This file holds VIM specific features for the layout. 
 */


/**
 * Escape hatch feature allows for quickly moving between a terminal vim session and
 * the terminal by using the pause-process and 'fg' commands. Internal state is kept
 * for knowing which should be swapped between.
 *
 * The VIM layer will also be turned off when escaping out, and will be turned back
 * on when coming back in.
 */

/* Assume the keyboard will be plugged in when not currently in VIM */
#define STATE_NOT_VIM 0
#define STATE_VIM 1
static char app_state = STATE_NOT_VIM;

static inline void vim_escape_hatch(void) {
    if (app_state == STATE_VIM) {
        SEND_STRING(SS_TAP(X_ESCAPE));
        SEND_STRING(SS_LCTRL("z"));        
        app_state = STATE_NOT_VIM;
    } else {
        SEND_STRING("fg\n");
        app_state = STATE_VIM;
    }
}

/* Allow for conditional macros based on whether the keyboard thinks it is in VIM or
 * not. If it isn't, then simply tap_code() the provided code, else call the function
 * provided
 */
#define OUTSIDE_VIM(code) { \
    if (app_state == STATE_NOT_VIM) { \
        tap_code(code); \
        return; \
    } \
}


/**
 * Movement feature allows for quickly navigating between split vim windows by using
 * the keys that normally feature the arrow keys. Note if we aren't currently in vim
 * as tracked by the keyboard, then emit arrow keys normally for use on the command
 * line without turning VIM mode off.
 */
static inline void vim_window_move_left(void) {
    OUTSIDE_VIM(KC_LEFT);
    SEND_STRING(SS_TAP(X_ESCAPE));
    SEND_STRING(SS_LCTRL("w")"h");
}

static inline void vim_window_move_right(void) {
    OUTSIDE_VIM(KC_RIGHT);
    SEND_STRING(SS_TAP(X_ESCAPE));
    SEND_STRING(SS_LCTRL("w")"l");
}

static inline void vim_window_move_up(void) {
    OUTSIDE_VIM(KC_UP);
    SEND_STRING(SS_TAP(X_ESCAPE));
    SEND_STRING(SS_LCTRL("w")"k");
}

static inline void vim_window_move_down(void) {
    OUTSIDE_VIM(KC_DOWN);
    SEND_STRING(SS_TAP(X_ESCAPE));
    SEND_STRING(SS_LCTRL("w")"j");
}


/** 
 * Window creation is a one-tap key that will change the next arrow key movement too
 * a creation action instead of movement action. Note this key doesn't time out, but
 * can be turned off by clicking the switch again.
 */

/* Allow for precedence when creating a window, vertical precedence means that a
 * vertical split will _never_ be made inside a horizontal split window. Rather it
 * will create a new vertical window beside all the horizontal split windows.
 */
#define VERTICAL 0
#define HORIZONTAL 1
#define AXIS_PRECEDENCE VERTICAL

/* Hold whether the create key has been pressed */
#define VIM_CREATE_ON 1
#define VIM_CREATE_OFF 0
static uint8_t vim_create = 0;

/* Macro to wrap the movement keys to first check if it should create or move */
#define CREATE_MOVE(DIRECTION) { \
    if (vim_create == VIM_CREATE_OFF) { vim_window_move_##DIRECTION(); } \
    else { \
        vim_window_create_##DIRECTION(); \
        vim_window_create(VIM_CREATE_OFF); \
    } \
}

static inline void vim_window_create(uint8_t state) {
    vim_create = state;
}

static inline void vim_window_create_up(void) {

}

static inline void vim_window_create_down(void) {

}

static inline void vim_window_create_left(void) {

}

static inline void vim_window_create_right(void) {

}

