ERGODOX_BASE_DIR="${HOME}/lib/qmk_firmware"
ERGODOX_KEYMAP_DIR="/keyboards/ergodox_ez/keymaps/whazell/"

CWD=$(pwd)

cp * ${ERGODOX_BASE_DIR}${ERGODOX_KEYMAP_DIR}
cd ${ERGODOX_BASE_DIR} && qmk compile -kb ergodox_ez -km augustd
cd ${CWD}
cp ${ERGODOX_BASE_DIR}/ergodox_ez_augustd.hex . 
