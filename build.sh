ERGODOX_BASE_DIR="${HOME}/lib/qmk_firmware"
ERGODOX_KEYMAP_DIR="/keyboards/ergodox_ez/keymaps/whazell/"

CWD=$(pwd)

cp * ${ERGODOX_BASE_DIR}${ERGODOX_KEYMAP_DIR}
cd ${ERGODOX_BASE_DIR} && make ergodox_ez:whazell
cd ${CWD}
cp ${ERGODOX_BASE_DIR}/ergodox_ez_whazell.hex .
