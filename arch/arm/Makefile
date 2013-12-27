#
# arch/arm/Makefile
#
# This file is included by the global makefile so that you can add your own
# architecture-specific flags and dependencies.
#
# This file is subject to the terms and conditions of the GNU General Public
# License.  See the file "COPYING" in the main directory of this archive
# for more details.
#
# Copyright (C) 1995-2001 by Russell King

# Ensure linker flags are correct
LDFLAGS		:=

# Platform Names

platname-$(CONFIG_BOARD_OMAP34XX) 		+= "OMAP3"
platname-$(CONFIG_BOARD_AM335X) 		+= "AM335X"
platname-$(CONFIG_BOARD_ARM_REALVIEW) 	+= "RealView"
platname-$(CONFIG_BOARD_HPTOUCHPAD)		+= "HP-TouchPad"

export platname-y := $(platname-y)

KBUILD_CFLAGS	+=-fstack-protector -DBUILD_STYLE=\"DEVELOPMENT\" -DBUILD_TAG=\"$(shell git describe --dirty)\" \
				-DPLATFORM_NAME=$(platname-y)

# Little endian
KBUILD_CPPFLAGS	+= -mlittle-endian
AS		+= -EL
LD		+= -EL -nostdlib

omma = ,

# Processor type
arch-$(CONFIG_PROC_CORTEX_A8)		=-D__LINUX_ARM_ARCH__=7 $(call cc-option,-march=armv7-a,-march=armv5t -Wa$(comma)-march=armv7-a)
arch-$(PROC_ARM1176JZFS)			=-D__LINUX_ARM_ARCH__=6 $(call cc-option,-march=armv6,-march=armv5t -Wa$(comma)-march=armv6)

# Evaluate arch cc-option calls now
arch-y := $(arch-y)

textofs-y 							:= 0x00000040
textofs-$(CONFIG_BOARD_OMAP34XX) 	:= 0x84000040
textofs-$(CONFIG_BOARD_AM335X) 		:= 0x84000040
textofs-$(CONFIG_BOARD_ARM_REALVIEW)	:= 0x84000040
textofs-$(CONFIG_BOARD_HPTOUCHPAD)	:= 0x44000040

export TEXT_OFFSET := $(textofs-y)

# Soft float.
KBUILD_CFLAGS	+=$(arch-y) -msoft-float -Uarm
KBUILD_AFLAGS	+=$(arch-y) -msoft-float

all: uImage

KBUILD_IMAGE = uImage
PHONY += uImage

archprepare:
	$(Q)$(MAKE) $(build)=images Images

uImage:
	# Create image.
	@echo Generating uImage...
	@$(OBJCOPY) -g -S -O binary vmlinux vmlinux.raw
	@mkimage -A arm -O linux -T kernel -C none -a $(TEXT_OFFSET) -e $(TEXT_OFFSET) -n "Linux 2.6" -d vmlinux.raw uImage
	@rm -f vmlinux.raw

# Boards
core-$(CONFIG_BOARD_OMAP34XX) 		+= arch/arm/plat-omap3/
core-$(CONFIG_BOARD_AM335X) 		+= arch/arm/plat-am335x/
core-$(CONFIG_BOARD_ARM_REALVIEW) 	+= arch/arm/plat-realview/
core-$(CONFIG_BOARD_HPTOUCHPAD)		+= arch/arm/plat-hptouchpad/

core-y				+= arch/arm/common/
