FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:${THISDIR}/${PN}/${MACHINE}:${THISDIR}/${PN}/common:"

include recipes-bsp/u-boot/u-boot-imx/${MACHINE}.inc
