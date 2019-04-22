ERGODOX_BASE_DIR="${HOME}/lib/qmk_firmware"
ERGODOX_KEYMAP_DIR="/keyboards/ergodox_ez/keymaps/whazell/"

cp * ${ERGODOX_BASE_DIR}${ERGODOX_KEYMAP_DIR}
cd ${ERGODOX_BASE_DIR} && make ergodox_ez:whazell
