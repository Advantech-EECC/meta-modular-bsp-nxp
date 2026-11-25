require common/watchdog_advantech.inc
require common/rtc-s35390a.inc

SRC_URI += " \
    file://rtl8211f-leds.patch \
    file://rom5722-db2510.dtsi \
    file://${MACHINE}.dts \
"

do_configure:prepend() {
    cp "${UNPACKDIR}/"*\.dts* "${S}/arch/arm64/boot/dts/freescale/"

    echo "dtb-$(CONFIG_ARCH_MXC) += ${MACHINE}.dtb" >> ${S}/arch/arm64/boot/dts/freescale/Makefile
    watchdog_advantech_patch
}
