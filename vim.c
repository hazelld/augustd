/**
 * This file holds VIM specific features for the layout. 
 */


/**
 * Escape hatch feature allows for quickly moving between a terminal vim session and
 * the terminal by using the pause-process and 'fg' commands. Internal state is kept
 * for knowing which should be swapped between.
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


/**
 * Movement feature allows for quickly navigating between split vim windows by using
 * the keys that normally feature the arrow keys
 */
static inline void vim_window_move_left(void) {
    SEND_STRING(SS_TAP(X_ESCAPE));
    SEND_STRING(SS_LCTRL("w")"h");
}

static inline void vim_window_move_right(void) {
    SEND_STRING(SS_TAP(X_ESCAPE));
    SEND_STRING(SS_LCTRL("w")"l");
}
