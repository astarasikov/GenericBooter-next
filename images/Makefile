Images: Ramdisk.o DeviceTree.o Mach.o

Ramdisk.o:
	$(Q)$(LD) -r -b binary -o images/Ramdisk.o images/Ramdisk.img3
	$(Q)$(OBJCOPY) --rename-section .data=.ramdisk images/Ramdisk.o images/Ramdisk.o

DeviceTree.o:
	$(Q)$(LD) -r -b binary -o images/DeviceTree.o images/DeviceTree.img3
	$(Q)$(OBJCOPY) --rename-section .data=.devicetree images/DeviceTree.o images/DeviceTree.o

Mach.o:
	$(Q)$(LD) -r -b binary -o images/Mach.o images/Mach.img3
	$(Q)$(OBJCOPY) --rename-section .data=.mach images/Mach.o images/Mach.o
