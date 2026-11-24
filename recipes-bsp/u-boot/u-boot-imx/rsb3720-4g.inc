DRAM_TIMING_BASE_NAME = "lpddr4_timing_rsb3720a2_4G"

require recipes-bsp/u-boot/u-boot-imx/common/rsb3720-base.inc

do_configure:prepend() {
    tgt=${S}/include/configs/imx8mp_evk.h
	RAM_SIZE=0x80000000 RAM2_SIZE=0x80000000 RAM2_OFFSET=0xc0000000

	sed -i "/^#define[[:space:]]\+PHYS_SDRAM_SIZE[[:space:]]/c#define PHYS_SDRAM_SIZE ${RAM_SIZE}" "$tgt"
	sed -i "/^#define[[:space:]]\+PHYS_SDRAM_2[[:space:]]\+/c#define PHYS_SDRAM_2 ${RAM2_OFFSET}" "$tgt"
	sed -i "/^#define[[:space:]]\+PHYS_SDRAM_2_SIZE[[:space:]]\+/c#define PHYS_SDRAM_2_SIZE ${RAM2_SIZE}" "$tgt"
}
