FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append:rom5720-db5901 = " file://0001-add-imx8mq-rom5720a1-2G-support.patch "
SRC_URI:append:rom5721-1g-db5901 = " file://0001-add-imx8mm-rom5721a1-1G-support.patch "
SRC_URI:append:rom5722-4g-db5901 = " file://0001-add-imx8mp-4G-support.patch"
SRC_URI:append:rsb3720-4g = " file://0001-add-imx8mp-4G-support.patch"
