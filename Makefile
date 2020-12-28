
PWD := $(shell pwd)
export PWD
SYSTEM_HEADER_PROJECTS="libc kernel"
export SYSTEM_HEADER_PROJECTS
PROJECTS="libc kernel"
export PROJECTS

MAKE=${MAKE:-make}
export MAKE
HOST=i686-elf
export HOST

AR=${HOST}-ar
export AR
AS=${HOST}-as
export AS
CMP=${HOST}-gcc
export CMP

PREFIX=/usr
export PREFIX
EXEC_PREFIX=/usr
export EXEC_PREFIX
BOOTDIR=/boot
export BOOTDIR
LIBDIR=/usr/lib
export LIBDIR
INCLUDEDIR=/usr/include
export INCLUDEDIR

# A ton of compiler flags that make the build faster
CFLAGS=-O2 -g -pipe -fomit-frame-pointer
CPPFLAGS=''
export CFLAGS
# Configure the cross-compiler to use the desired system root.
SYSROOT=$(PWD)/sysroot
export SYSROOT
CC=$(CMP) --sysroot=$(SYSROOT) -isystem=$(INCLUDEDIR)
export CC


.PHONY: build clean install packages tools qemu iso

all: build iso qemu
	@echo "Done."
build:
	@echo Starting build...
	mkdir -p $(PWD)/sysroot
	cd $(PWD)/libc && DESTDIR="$(SYSROOT)" make install-headers
	cd $(PWD)/kernel && DESTDIR="$(SYSROOT)" make install-headers
	cd $(PWD)/libc && DESTDIR="$(SYSROOT)" make install
	cd $(PWD)/kernel && DESTDIR="$(SYSROOT)" make install
	@echo Build done.
clean:
	@echo Cleaning...
	cd $(PWD)/libc && make clean
	cd $(PWD)/kernel && make clean
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
