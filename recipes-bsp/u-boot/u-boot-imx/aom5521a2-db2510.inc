SRC_URI += " \
    file://0001-Add-support-for-i.MX95-AOM-5521-A2.patch \
"

do_configure:prepend() {

    # Point to custom device tree
    sed -i "/^CONFIG_DEFAULT_FDT_FILE=/c\CONFIG_DEFAULT_FDT_FILE=\"${MACHINE}.dtb\"" \
        ${S}/configs/imx95_19x19_evk_defconfig

    # Adjust SPI flash speed for AOM-5521 hardware
    sed -i "/^CONFIG_SF_DEFAULT_SPEED=/c\CONFIG_SF_DEFAULT_SPEED=40000000" \
        ${S}/configs/imx95_19x19_evk_defconfig

    sed -i "/^CONFIG_RTC_EMULATION=/c\# CONFIG_RTC_EMULATION is not set" \
        ${S}/configs/imx95_19x19_evk_defconfig

    sed -i "/^CONFIG_SUPPORT_EMMC_RPMB=y/c\# CONFIG_SUPPORT_EMMC_RPMB is not set" \
        ${S}/configs/imx95_19x19_evk_defconfig

    # Disable USB TCPC (not present on AOM-5521)
    sed -i "/^CONFIG_USB_TCPC=y/c\# CONFIG_USB_TCPC is not set" \
        ${S}/configs/imx95_19x19_evk_defconfig

    # Simplify boot command (no sr_ir_v2_cmd on this board)
    sed -i '/^CONFIG_BOOTCOMMAND=/c\CONFIG_BOOTCOMMAND="bootflow scan -l; run bsp_bootcmd"' \
        ${S}/configs/imx95_19x19_evk_defconfig

    # Remove EFI
    sed -i "/^CONFIG_EFI_MM_COMM_TEE=/c\# CONFIG_EFI_MM_COMM_TEE is not set" \
        ${S}/configs/imx95_19x19_evk_defconfig
    sed -i "/^=CONFIG_EFI_VAR_BUF_SIZE/c\#  CONFIG_EFI_VAR_BUF_SIZEis not set" \
        ${S}/configs/imx95_19x19_evk_defconfig
    sed -i "/^=CONFIG_EFI_SET_TIME/c\# CONFIG_EFI_SET_TIME is not set" \
        ${S}/configs/imx95_19x19_evk_defconfig
    sed -i "/^CONFIG_EFI_RUNTIME_UPDATE_CAPSULE=/c\# CONFIG_EFI_RUNTIME_UPDATE_CAPSULE is not set" \
        ${S}/configs/imx95_19x19_evk_defconfig
    sed -i "/^CONFIG_EFI_CAPSULE_ON_DISK=/c\# CONFIG_EFI_CAPSULE_ON_DISK is not set" \
        ${S}/configs/imx95_19x19_evk_defconfig
    sed -i "/^CONFIG_EFI_SECURE_BOOT=/c\# CONFIG_EFI_SECURE_BOOT is not set" \
        ${S}/configs/imx95_19x19_evk_defconfig
    sed -i "/^CONFIG_EFI_IGNORE_OSINDICATIONS=/c\# CONFIG_EFI_IGNORE_OSINDICATIONS is not set" \
        ${S}/configs/imx95_19x19_evk_defconfig
    sed -i "/^CONFIG_EFI_CAPSULE_FIRMWARE_RAW=/c\# CONFIG_EFI_CAPSULE_FIRMWARE_RAW is not set" \
        ${S}/configs/imx95_19x19_evk_defconfig
    sed -i "/^CONFIG_EFI_CAPSULE_AUTHENTICATE=/c\# CONFIG_EFI_CAPSULE_AUTHENTICATE is not set" \
        ${S}/configs/imx95_19x19_evk_defconfig
    sed -i "/^CONFIG_EFI_CAPSULE_CRT_FILE=/c\# CONFIG_EFI_CAPSULE_CRT_FILE is not set" \
        ${S}/configs/imx95_19x19_evk_defconfig

    # Remove PCIe/NVMe
    sed -i "/^CONFIG_PCIE_DW_IMX=/c\# CONFIG_PCIE_DW_IMX is not set" \
        ${S}/configs/imx95_19x19_evk_defconfig
    sed -i "/^CONFIG_NVME=/c\# CONFIG_NVME is not set" \
        ${S}/configs/imx95_19x19_evk_defconfig
    sed -i "/^CONFIG_NVME_PCI=/c\# CONFIG_NVME_PCI is not set" \
        ${S}/configs/imx95_19x19_evk_defconfig
    sed -i "/^CONFIG_CMD_NVME=/c\# CONFIG_CMD_NVME is not set" \
        ${S}/configs/imx95_19x19_evk_defconfig

    # Remove Backlight Control
    sed -i "/^CONFIG_CLK_IMX95_BLKCTRL=/c\# CONFIG_CLK_IMX95_BLKCTRL is not set" \
        ${S}/configs/imx95_19x19_evk_defconfig

    # Add USB Gadget Support
    echo "CONFIG_CI_UDC=y" >> ${S}/configs/imx95_19x19_evk_defconfig
    echo "CONFIG_DM_USB_GADGET=y" >> ${S}/configs/imx95_19x19_evk_defconfig
    echo "CONFIG_SPL_DM_USB_GADGET=y" >> ${S}/configs/imx95_19x19_evk_defconfig

    # Add Winbond SPI flash support
    echo "CONFIG_SPI_FLASH_WINBOND=y" >> ${S}/configs/imx95_19x19_evk_defconfig
}
