#!/bin/sh
# iso.sh: Make a bootable ISO with GRUB
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/simpleos.kernel isodir/boot/simpleos.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "simpleos" {
	multiboot /boot/simpleos.kernel
}
EOF
grub2-mkrescue -o simpleos.iso isodir
