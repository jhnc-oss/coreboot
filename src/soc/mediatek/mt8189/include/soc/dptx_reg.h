/* SPDX-License-Identifier: GPL-2.0-only OR MIT */

#ifndef __SOC_MEDIATEK_MT8189_DP_DPTX_REG_H__
#define __SOC_MEDIATEK_MT8189_DP_DPTX_REG_H__

#include <soc/dptx_reg_v2.h>

#define DP_PHY_DIG_TX_CTL_0			0x1444
#define RGS_AUX_LDO_EN_READY_MASK		BIT(2)
#define DRIVING_FORCE				0x18
#define EDP_TX_LN_PRE_EMPH_VAL_MASK		GENMASK(6, 5)
#define EDP_TX_LN_PRE_EMPH_VAL_SHIFT		5
#define EDP_TX_LN_VOLT_SWING_EN_MASK		BIT(0)
#define EDP_TX_LN_PRE_EMPH_EN_MASK		BIT(4)

#endif /* __SOC_MEDIATEK_MT8189_DP_DPTX_REG_H__ */
