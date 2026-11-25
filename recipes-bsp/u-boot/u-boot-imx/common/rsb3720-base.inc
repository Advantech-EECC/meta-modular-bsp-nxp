require recipes-bsp/u-boot/u-boot-imx/common/imx8mp-base.inc

SRC_URI += " \
    file://rsb3720-u-boot.dtsi \
    file://rsb3720.dtsi \
    file://${MACHINE}.dts \
"

do_configure:prepend() {
    cp "${UNPACKDIR}/rsb3720-u-boot.dtsi" \
        "${S}/arch/arm/dts/imx8mp-evk-u-boot.dtsi"
    cp "${UNPACKDIR}/${MACHINE}.dts" \
        "${S}/dts/upstream/src/arm64/freescale/imx8mp-evk.dts"
    cp "${UNPACKDIR}/rsb3720.dtsi" \
        "${S}/dts/upstream/src/arm64/freescale/"

    for i in board/nxp/imx8mp_evk/imx8mp_evk.env ; do
        sed -i 's/console=ttymxc1,115200/console=ttymxc2,115200/g' "${S}/$i"
        sed -i 's/ec_imx6q,0x30890000/ec_imx6q,0x30880000/g' "${S}/$i"
    done
}
