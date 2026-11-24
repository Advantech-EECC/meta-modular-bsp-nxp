DRAM_TIMING_BASE_NAME ?= "lpddr4_timing"

SRC_URI += " \
    file://${DRAM_TIMING_BASE_NAME}.c \
    file://rsb3720-u-boot.dtsi \
    file://rsb3720.dtsi \
    file://${MACHINE}.dts \
    file://0001-rsb3720-change-uart-mapping.patch \
    file://0002-rsb3720-enable-i2c-level-translator.patch \
"

do_configure:prepend() {
    cp "${UNPACKDIR}/${DRAM_TIMING_BASE_NAME}.c" \
        "${S}/board/nxp/imx8mp_evk/"
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

    sed -i "/^CONFIG_DEFAULT_FDT_FILE=/c\CONFIG_DEFAULT_FDT_FILE=\"${MACHINE}.dtb\"" ${S}/configs/imx8mp_evk_defconfig
    sed -i "s/lpddr4_timing.o/${DRAM_TIMING_BASE_NAME}.o/g" ${S}/board/nxp/imx8mp_evk/Makefile
}
