FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append:aom5521a1-db2510 = " \
                    file://0001-Add-AOM5521A1-16G-8G-LPDDR5-board-ports-for-i.MX95.patch \
"

#lpddr5_timing.c comes from: https://github.com/ADVANTECH-Corp/meta-advantech2/commit/8b596b6341b13e3c45733e0c6b8730735287b6c4
SRC_URI:append:aom5521a2-db2510 = " \
                    file://lpddr5_timing.c;subdir=boards/mx95lp5/ddr/ \
"

do_configure:prepend:aom5521a2-db2510() {
	cp "${UNPACKDIR}/boards/mx95lp5/ddr/lpddr5_timing.c" \
            "${S}/boards/mx95lp5/ddr/MIMX95_LPDDR5_EVK_19X19_6400MTS_FW2024.09_timing.c"
}

