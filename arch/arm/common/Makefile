BUILD_STYLE = "DEVELOPMENT"
BUILD_PRODUCT = "GenericBooter"

CPPFLAGS_linkerscript.lds := -DTEXT_OFFSET=$(TEXT_OFFSET)

obj-y = bcopy.o bzero.o start.o strchr.o strcmp.o strlen.o strncmp.o version.o
extra-y := $(head-y) linkerscript.lds

PHONY += arch/arm/common/version.S

arch/arm/common/version.S:
	$(Q)arch/arm/common/version.sh arch/arm/common/version.S $(BUILD_PRODUCT) $(platname-y) $(BUILD_STYLE) $(shell git describe --dirty)