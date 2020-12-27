#!/bin/sh
abspath() {
	cd ..
	TEST=$(pwd)
	export TEST
}
cat > ${TEST}/isodir/boot/grub/grub.cfg << EOF
menuentry "Boot SimpleOS" {
	multiboot /boot/simpleos.kernel
}
EOF
