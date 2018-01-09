/*
 * Copyright 2015, Freescale Semiconductor
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _ASM_ARMV8_FSL_LAYERSCAPE_CONFIG_H_
#define _ASM_ARMV8_FSL_LAYERSCAPE_CONFIG_H_

#include <linux/kconfig.h>
#include <fsl_ddrc_version.h>

#define CONFIG_STANDALONE_LOAD_ADDR	0x80300000

/*
 * Reserve secure memory
 * To be aligned with MMU block size
 */
#define CONFIG_SYS_MEM_RESERVE_SECURE	(2048 * 1024)	/* 2MB */

#ifdef CONFIG_LS2080A
#define CONFIG_SYS_FSL_CLUSTER_CLOCKS		{ 1, 1, 4, 4 }
#define	SRDS_MAX_LANES	8
#define CONFIG_SYS_PAGE_SIZE		0x10000
#ifndef L1_CACHE_BYTES
#define L1_CACHE_SHIFT		6
#define L1_CACHE_BYTES		BIT(L1_CACHE_SHIFT)
#define CONFIG_FSL_TZASC_400
#endif

#define CONFIG_SYS_FSL_OCRAM_BASE	0x18000000	/* initial RAM */
#define CONFIG_SYS_FSL_OCRAM_SIZE	0x00200000	/* 2M */

/* DDR */
#define CONFIG_SYS_LS2_DDR_BLOCK1_SIZE	((phys_size_t)2 << 30)
#define CONFIG_MAX_MEM_MAPPED		CONFIG_SYS_LS2_DDR_BLOCK1_SIZE

#define CONFIG_SYS_FSL_CCSR_GUR_LE
#define CONFIG_SYS_FSL_CCSR_SCFG_LE
#define CONFIG_SYS_FSL_ESDHC_LE
#define CONFIG_SYS_FSL_IFC_LE
#define CONFIG_SYS_FSL_PEX_LUT_LE

#define CONFIG_SYS_MEMAC_LITTLE_ENDIAN

/* Generic Interrupt Controller Definitions */
#define GICD_BASE			0x06000000
#define GICR_BASE			0x06100000

/* SMMU Defintions */
#define SMMU_BASE			0x05000000 /* GR0 Base */

/* SFP */
#define CONFIG_SYS_FSL_SFP_VER_3_4
#define CONFIG_SYS_FSL_SFP_LE
#define CONFIG_SYS_FSL_SRK_LE

/* SEC */
#define CONFIG_SYS_FSL_SEC_LE
#define CONFIG_SYS_FSL_SEC_COMPAT	5

/* Security Monitor */
#define CONFIG_SYS_FSL_SEC_MON_LE

/* Secure Boot */
#define CONFIG_ESBC_HDR_LS

/* DCFG - GUR */
#define CONFIG_SYS_FSL_CCSR_GUR_LE

/* Cache Coherent Interconnect */
#define CCI_MN_BASE			0x04000000
#define CCI_MN_RNF_NODEID_LIST		0x180
#define CCI_MN_DVM_DOMAIN_CTL		0x200
#define CCI_MN_DVM_DOMAIN_CTL_SET	0x210

#define CCI_HN_F_0_BASE			(CCI_MN_BASE + 0x200000)
#define CCI_HN_F_1_BASE			(CCI_MN_BASE + 0x210000)
#define CCN_HN_F_SAM_CTL		0x8	/* offset on base HN_F base */
#define CCN_HN_F_SAM_NODEID_MASK	0x7f
#define CCN_HN_F_SAM_NODEID_DDR0	0x4
#define CCN_HN_F_SAM_NODEID_DDR1	0xe

#define CCI_RN_I_0_BASE			(CCI_MN_BASE + 0x800000)
#define CCI_RN_I_2_BASE			(CCI_MN_BASE + 0x820000)
#define CCI_RN_I_6_BASE			(CCI_MN_BASE + 0x860000)
#define CCI_RN_I_12_BASE		(CCI_MN_BASE + 0x8C0000)
#define CCI_RN_I_16_BASE		(CCI_MN_BASE + 0x900000)
#define CCI_RN_I_20_BASE		(CCI_MN_BASE + 0x940000)

#define CCI_S0_QOS_CONTROL_BASE(x) ((CCI_RN_I_0_BASE + (x * 0x10000)) + 0x10)
#define CCI_S1_QOS_CONTROL_BASE(x) ((CCI_RN_I_0_BASE + (x * 0x10000)) + 0x110)
#define CCI_S2_QOS_CONTROL_BASE(x) ((CCI_RN_I_0_BASE + (x * 0x10000)) + 0x210)

#define CCI_AUX_CONTROL_BASE(x) ((CCI_RN_I_0_BASE + (x * 0x10000)) + 0x0500)

/* TZ Protection Controller Definitions */
#define TZPC_BASE				0x02200000
#define TZPCR0SIZE_BASE				(TZPC_BASE)
#define TZPCDECPROT_0_STAT_BASE			(TZPC_BASE + 0x800)
#define TZPCDECPROT_0_SET_BASE			(TZPC_BASE + 0x804)
#define TZPCDECPROT_0_CLR_BASE			(TZPC_BASE + 0x808)
#define TZPCDECPROT_1_STAT_BASE			(TZPC_BASE + 0x80C)
#define TZPCDECPROT_1_SET_BASE			(TZPC_BASE + 0x810)
#define TZPCDECPROT_1_CLR_BASE			(TZPC_BASE + 0x814)
#define TZPCDECPROT_2_STAT_BASE			(TZPC_BASE + 0x818)
#define TZPCDECPROT_2_SET_BASE			(TZPC_BASE + 0x81C)
#define TZPCDECPROT_2_CLR_BASE			(TZPC_BASE + 0x820)

#define DCSR_CGACRE5		0x700070914ULL
#define EPU_EPCMPR5		0x700060914ULL
#define EPU_EPCCR5		0x700060814ULL
#define EPU_EPSMCR5		0x700060228ULL
#define EPU_EPECR5		0x700060314ULL
#define EPU_EPCTR5		0x700060a14ULL
#define EPU_EPGCR		0x700060000ULL

#define CONFIG_SYS_FSL_ERRATUM_A008336
#define CONFIG_SYS_FSL_ERRATUM_A008511
#define CONFIG_SYS_FSL_ERRATUM_A008514
#define CONFIG_SYS_FSL_ERRATUM_A008585
#define CONFIG_SYS_FSL_ERRATUM_A008751
#define CONFIG_SYS_FSL_ERRATUM_A009635
#define CONFIG_SYS_FSL_ERRATUM_A009663
#define CONFIG_SYS_FSL_ERRATUM_A009801
#define CONFIG_SYS_FSL_ERRATUM_A009803
#define CONFIG_SYS_FSL_ERRATUM_A009942
#define CONFIG_SYS_FSL_ERRATUM_A010165

/* ARM A57 CORE ERRATA */
#define CONFIG_ARM_ERRATA_826974
#define CONFIG_ARM_ERRATA_828024
#define CONFIG_ARM_ERRATA_829520
#define CONFIG_ARM_ERRATA_833471

#define CONFIG_SYS_FSL_MAX_NUM_OF_SEC		1
#elif defined(CONFIG_FSL_LSCH2)
#define CONFIG_SYS_FSL_SEC_COMPAT		5
#define CONFIG_SYS_FSL_OCRAM_BASE		0x10000000 /* initial RAM */
#define CONFIG_SYS_FSL_OCRAM_SIZE		0x00200000 /* 2M */

#define CONFIG_SYS_FSL_CCSR_SCFG_BE
#define CONFIG_SYS_FSL_ESDHC_BE
#define CONFIG_SYS_FSL_WDOG_BE
#define CONFIG_SYS_FSL_DSPI_BE
#define CONFIG_SYS_FSL_QSPI_BE
#define CONFIG_SYS_FSL_CCSR_GUR_BE
#define CONFIG_SYS_FSL_PEX_LUT_BE
#define CONFIG_SYS_FSL_SEC_BE

/* SoC related */
#ifdef CONFIG_LS1043A
#define CONFIG_SYS_FMAN_V3
#define CONFIG_SYS_NUM_FMAN			1
#define CONFIG_SYS_NUM_FM1_DTSEC		7
#define CONFIG_SYS_NUM_FM1_10GEC		1
#define CONFIG_SYS_DDR_BLOCK1_SIZE		((phys_size_t)2 << 30)
#define CONFIG_MAX_MEM_MAPPED			CONFIG_SYS_DDR_BLOCK1_SIZE

#define QE_MURAM_SIZE		0x6000UL
#define MAX_QE_RISC		1
#define QE_NUM_OF_SNUM		28

#define CONFIG_SYS_FSL_IFC_BE
#define CONFIG_SYS_FSL_SFP_VER_3_2
#define CONFIG_SYS_FSL_SEC_MON_BE
#define CONFIG_SYS_FSL_SFP_BE
#define CONFIG_SYS_FSL_SRK_LE
#define CONFIG_KEY_REVOCATION

/* SMMU Defintions */
#define SMMU_BASE		0x09000000

/* Generic Interrupt Controller Definitions */
#define GICD_BASE		0x01401000
#define GICC_BASE		0x01402000

#define CONFIG_SYS_FSL_ERRATUM_A008850
#define CONFIG_SYS_FSL_ERRATUM_A009663
#define CONFIG_SYS_FSL_ERRATUM_A009929
#define CONFIG_SYS_FSL_ERRATUM_A009942
#define CONFIG_SYS_FSL_ERRATUM_A009660
#define CONFIG_SYS_FSL_MAX_NUM_OF_SEC		1
#elif defined(CONFIG_ARCH_LS1012A)
#undef	CONFIG_SYS_FSL_DDRC_ARM_GEN3

#define GICD_BASE		0x01401000
#define GICC_BASE		0x01402000
#elif defined(CONFIG_ARCH_LS1046A)
#define CONFIG_SYS_FMAN_V3
#define CONFIG_SYS_NUM_FMAN			1
#define CONFIG_SYS_NUM_FM1_DTSEC		8
#define CONFIG_SYS_NUM_FM1_10GEC		2
#define CONFIG_SYS_DDR_BLOCK1_SIZE  ((phys_size_t)2 << 30)
#define CONFIG_MAX_MEM_MAPPED           CONFIG_SYS_DDR_BLOCK1_SIZE

#define CONFIG_SYS_FSL_IFC_BE
#define CONFIG_SYS_FSL_SFP_VER_3_2
#define CONFIG_SYS_FSL_SNVS_LE
#define CONFIG_SYS_FSL_SFP_BE
#define CONFIG_SYS_FSL_SRK_LE
#define CONFIG_KEY_REVOCATION

/* SMMU Defintions */
#define SMMU_BASE		0x09000000

/* Generic Interrupt Controller Definitions */
#define GICD_BASE		0x01410000
#define GICC_BASE		0x01420000

#define CONFIG_SYS_FSL_MAX_NUM_OF_SEC		1

#define CONFIG_SYS_FSL_ERRATUM_A008511
#define CONFIG_SYS_FSL_ERRATUM_A009801
#define CONFIG_SYS_FSL_ERRATUM_A009803
#define CONFIG_SYS_FSL_ERRATUM_A009942
#define CONFIG_SYS_FSL_ERRATUM_A010165
#else
#error SoC not defined
#endif
#endif

#endif /* _ASM_ARMV8_FSL_LAYERSCAPE_CONFIG_H_ */
