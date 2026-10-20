SRC_URI += " \
    file://usb-disable-tcpc.cfg \
"

do_configure:prepend() {
	sed -i "/^CONFIG_DEFAULT_FDT_FILE=/c\CONFIG_DEFAULT_FDT_FILE=\"rom5722-db2510.dtb\"" ${S}/configs/imx8mp_evk_defconfig
}
