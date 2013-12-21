# GenericBooter

These are the release notes for GenericBooter. Please read them carefully
as they explain what this project is all about and how to compile/use it and also
what to do if something goes horribly awry.

## What is GenericBooter?

GenericBooter is a sample boot loader for Darwin/ARM systems. It is intended
to be bootstrapped from another boot loader (namely Das U-boot). It will load
the Mach kernel into memory, flatten the device tree and finally pass control to
it.

## What hardware does GenericBooter run on?

Currently, GenericBooter has ports for:

* Texas Instruments OMAP3-series.
* Texas Instruments AM335x-series.
* ARM RealView boards.

Adding a board port is simple.

## Compiling the boot loader:

You will need standard development libraries and software, such as `ncurses`, `gcc`, `flex`,
and so on. If you can compile the Linux kernel, you can compile this.

To compile using the `arm-none-eabi-` toolchain use:

<pre>
$ make CROSS_COMPILE=arm-none-eabi-
</pre>

You will need to run `make menuconfig` before doing that however.

## Images for the boot loader:

Since this boot loader wraps images into the resulting binary, you will need 3 images
in the `images` folder. They include:

* `mach_kernel`, wrapped as an uncompressed Mach-O file inside an Image3 with magic `krnl`. (Mach.img3)
* A ramdisk, wrapped as an uncompressed raw HFS(+) volume inside an Image3 with magic `rdsk`. (Ramdisk.img3)

If you are using an iOS compatible device tree, make sure you put a devicetree as DeviceTree.img3 inside
the folder with the specified device tree. The same must be performed for an XML device tree.

