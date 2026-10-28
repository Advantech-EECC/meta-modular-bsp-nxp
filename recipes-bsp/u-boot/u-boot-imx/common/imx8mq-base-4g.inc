SRC_URI += " \
    file://0000-imx8mq-4gb.patch \
    file://lpddr4_timing_4g.c \
"

require recipes-bsp/u-boot/u-boot-imx/common/imx8mq-base.inc

do_configure:prepend() {
    cp "${UNPACKDIR}/lpddr4_timing_4g.c" "${S}/board/freescale/imx8mq_evk/"
}
