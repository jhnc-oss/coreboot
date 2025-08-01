## SPDX-License-Identifier: GPL-2.0-only OR MIT

all-y += memlayout.ld
all-y += chromeos.c
all-y += reset.c

bootblock-y += bootblock.c

romstage-y += romstage.c
romstage-y += regulator.c

ramstage-y += boardid.c
ramstage-y += mainboard.c
ramstage-y += panel.c
ramstage-y += regulator.c
