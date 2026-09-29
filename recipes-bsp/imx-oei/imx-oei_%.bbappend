FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append:aom5521a2-db2510 = " \
				    file://adv-imx95-8G-lpddr5.c;subdir=boards/mx95lp5/ddr/  \
                    "

do_configure:prepend:aom5521a2-db2510() {
	cp "${UNPACKDIR}/boards/mx95lp5/ddr/adv-imx95-8G-lpddr5.c" \
            "${S}/boards/mx95lp5/ddr/MIMX95_LPDDR5_EVK_19X19_6400MTS_FW2024.09_timing.c"
}
