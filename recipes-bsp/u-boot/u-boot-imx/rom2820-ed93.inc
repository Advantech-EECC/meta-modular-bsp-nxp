SRC_URI += " \
    file://usb-disable-tcpc.cfg \
"

do_configure:prepend() {
	sed -i "/^CONFIG_DEFAULT_FDT_FILE=/c\CONFIG_DEFAULT_FDT_FILE=\"rom2820-ed93.dtb\"" ${S}/configs/imx93_11x11_evk_defconfig
}
