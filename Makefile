
PWD := $(shell pwd)

.PHONY: build clean install packages tools qemu iso

all: build iso qemu
	@echo "Done."

build:
	@echo Starting build...	
	mkdir -p $(PWD)/sysroot
	@echo Build done.

clean:
	@echo Cleaning...
	rm -rf $(PWD)/sysroot
	rm -rf $(PWD)/isodir
	rm -rf $(PWD)/simpleos.iso
	@echo Cleaned.
iso:
	mkdir -p $(PWD)/isodir/boot/grub
	cp $(PWD)/sysroot/boot/simpleos.kernel $(PWD)/isodir/boot/simpleos.kernel
	/bin/sh -c "$(PWD)/scripts/menuentry.sh"
	grub2-mkrescue -o simpleos.iso $(PWD)/isodir

qemu:
	qemu-system-i386 -cdrom simpleos.iso

packages:
	/bin/sh -c "$(PWD)/scripts/packages.sh"

tools:
	/bin/sh -c "$(PWD)/scripts/tools.sh"
