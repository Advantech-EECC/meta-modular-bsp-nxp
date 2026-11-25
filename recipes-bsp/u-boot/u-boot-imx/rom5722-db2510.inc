SRC_URI += " \
    file://usb-disable-tcpc.cfg \
"

do_configure:prepend() {
	sed -i "/^CONFIG_DEFAULT_FDT_FILE=/c\CONFIG_DEFAULT_FDT_FILE=\"${MACHINE}.dtb\"" ${S}/configs/imx8mp_evk_defconfig
}
