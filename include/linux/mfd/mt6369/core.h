/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2021 MediaTek Inc.
 */

#ifndef __MFD_MT6369_CORE_H__
#define __MFD_MT6369_CORE_H__

#define MT6369_REG_WIDTH 8

enum mt6369_irq_top_status_shift {
	MT6369_BUCK_TOP = 0,
	MT6369_LDO_TOP,
	MT6369_PSC_TOP,
	MT6369_MISC_TOP,
	MT6369_HK_TOP,
	MT6369_SCK_TOP,
	MT6369_BM_TOP,
	MT6369_AUD_TOP,
};

enum mt6369_irq_numbers {
	MT6369_IRQ_VBUCK1_OC = 0,
	MT6369_IRQ_VPA_OC = 6,
	MT6369_IRQ_VMDDR_OC = 8,
	MT6369_IRQ_VMDDQ_OC,
	MT6369_IRQ_VSIM1_OC,
	MT6369_IRQ_VSIM2_OC,
	MT6369_IRQ_VIBR_OC,
	MT6369_IRQ_VIO28_OC,
	MT6369_IRQ_VFP_OC,
	MT6369_IRQ_VTP_OC,
	MT6369_IRQ_VUSB_OC,
	MT6369_IRQ_VAUD28_OC,
	MT6369_IRQ_VCN33_1_OC,
	MT6369_IRQ_VCN33_2_OC,
	MT6369_IRQ_VEFUSE_OC,
	MT6369_IRQ_VMCH_OC,
	MT6369_IRQ_VMC_OC,
	MT6369_IRQ_VSRAM_CORE_OC,
	MT6369_IRQ_VDIGRF_OC,
	MT6369_IRQ_VANT18_OC,
	MT6369_IRQ_VAUX18_OC,
	MT6369_IRQ_RCS0 = 32,
	MT6369_IRQ_SPMI_CMD_ALERT,
	MT6369_IRQ_SPMI_P_CMD_ALERT,
	MT6369_IRQ_BUCK_PROTREG = 40,
	MT6369_IRQ_LDO_PROTREG,
	MT6369_IRQ_PSC_PROTREG,
	MT6369_IRQ_PLT_PROTREG,
	MT6369_IRQ_HK_PROTREG,
	MT6369_IRQ_TOP_PROTREG = 47,
	MT6369_IRQ_THR_H = 54,
	MT6369_IRQ_THR_L,
	MT6369_IRQ_AUDIO,
	MT6369_IRQ_ACCDET,
	MT6369_IRQ_ACCDET_EINT0,
	MT6369_IRQ_ACCDET_EINT1,
	MT6369_IRQ_NR = 60,
};

#define MT6369_IRQ_BUCK_BASE            0
#define MT6369_IRQ_LDO_BASE             8
#define MT6369_IRQ_MISC_BASE            32
#define MT6369_IRQ_HK_BASE              48
#define MT6369_IRQ_AUD_BASE             56

#define MT6369_IRQ_BUCK_MAX_BIT         MT6369_IRQ_VPA_OC
#define MT6369_IRQ_LDO_MAX_BIT          MT6369_IRQ_VAUX18_OC
#define MT6369_IRQ_MISC_MAX_BIT         MT6369_IRQ_TOP_PROTREG
#define MT6369_IRQ_HK_MAX_BIT           MT6369_IRQ_THR_L
#define MT6369_IRQ_AUD_MAX_BIT          MT6369_IRQ_ACCDET_EINT1

#define MT6369_TOP_GEN(sp) \
{ \
	.hwirq_base = MT6369_IRQ_##sp##_BASE, \
	.num_int_regs = \
		((MT6369_IRQ_##sp##_MAX_BIT - MT6369_IRQ_##sp##_BASE) / MT6369_REG_WIDTH) + 1, \
	.en_reg = MT6369_##sp##_TOP_INT_CON0, \
	.en_reg_shift = 0x3, \
	.sta_reg = MT6369_##sp##_TOP_INT_STATUS0, \
	.sta_reg_shift = 0x1, \
	.top_offset = MT6369_##sp##_TOP, \
}

#endif /* __MFD_MT6369_CORE_H__ */