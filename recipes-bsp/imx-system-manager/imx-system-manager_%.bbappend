FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append:aom5521a2-db2510 = " \
        file://0001-sm-adv-aom5521-m7-resource-ownership.patch  \
        file://0002-sm-adv-aom5521-i2c-recovery-drop-pcal6408a.patch \
"
