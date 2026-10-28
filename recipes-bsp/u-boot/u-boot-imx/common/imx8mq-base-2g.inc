SRC_URI += " \
    file://0000-imx8mq-2gb.patch \
    file://lpddr4_timing_2g.c;subdir=git/board/freescale/imx8mq_evk \
    file://lpddr4_timing_b0.c;subdir=git/board/freescale/imx8mq_evk \
"

require recipes-bsp/u-boot/u-boot-imx/common/imx8mq-base.inc
