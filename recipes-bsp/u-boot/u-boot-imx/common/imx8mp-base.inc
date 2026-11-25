DRAM_TIMING_BASE_NAME ?= "lpddr4_timing"

SRC_URI += " \
    file://${DRAM_TIMING_BASE_NAME}.c \
    file://0001-rsb3720-change-uart-mapping.patch \
    file://0002-rsb3720-enable-i2c-level-translator.patch \
    file://usb-disable-tcpc.cfg \
"

do_configure:prepend() {
    cp "${UNPACKDIR}/${DRAM_TIMING_BASE_NAME}.c" "${S}/board/nxp/imx8mp_evk/"

    sed -i "/^CONFIG_DEFAULT_FDT_FILE=/c\CONFIG_DEFAULT_FDT_FILE=\"${MACHINE}.dtb\"" ${S}/configs/imx8mp_evk_defconfig
    sed -i "s/lpddr4_timing.o/${DRAM_TIMING_BASE_NAME}.o/g" ${S}/board/nxp/imx8mp_evk/Makefile
}
