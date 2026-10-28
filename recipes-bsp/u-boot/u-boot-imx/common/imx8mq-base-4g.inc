SRC_URI += " \
    file://0000-imx8mq-4gb.patch \
    file://lpddr4_timing_4g.c;subdir=git/board/freescale/imx8mq_evk/ \
"

require recipes-bsp/u-boot/u-boot-imx/common/imx8mq-base.inc
