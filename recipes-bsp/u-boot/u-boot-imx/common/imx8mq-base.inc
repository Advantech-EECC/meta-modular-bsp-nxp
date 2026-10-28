SRC_URI += " \
    file://0001-imx8mq-common.patch \
    file://board.cfg \
    file://imx8mq-base.cfg \
"

EVK_CONFIGS_INCLUDE = "${S}/include/configs/imx8mq_evk.h"

do_configure:prepend() {
    sed -i "s/fdtfile=${UBOOT_DTB_NAME}/fdtfile=${MACHINE}.dtb/g" "${EVK_CONFIGS_INCLUDE}" || true
}
