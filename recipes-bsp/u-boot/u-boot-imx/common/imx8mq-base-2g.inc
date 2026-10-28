SRC_URI += " \
    file://0000-imx8mq-2gb.patch \
    file://lpddr4_timing_2g.c \
    file://lpddr4_timing_b0.c \
"

require recipes-bsp/u-boot/u-boot-imx/common/imx8mq-base.inc

do_configure:prepend() {
    cp "${UNPACKDIR}/lpddr4_timing_2g.c" "${UNPACKDIR}/lpddr4_timing_b0.c" \
       "${S}/board/nxp/imx8mq_evk/"
}
