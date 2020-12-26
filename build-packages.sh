#!/bin/sh
set -e
# build-packages.sh: install all distro-specific packages.
getdistro() {
    if [ -e /etc/redhat-release ]; then
	export DISTRO="REDHAT"
    elif [ -e /etc/fedora-release ]; then
	export DISTRO="REDHAT"
    elif [-e /etc/debian_release ]; then
	export DISTRO="DEBIAN"
    elif [-e /etc/gentoo-release ]; then
	export DISTRO="GENTOO"
    elif [ $(sysctl kern.version | cut -f 2 -d =) = "OpenBSD" ]; then
	export DISTRO="OPENBSD"
    else
	printf "Your distro is unsupported. Look at README.org for further details.\n"
	break
    fi
}
installpkg() {
    if [ $DISTRO = "REDHAT" ]; then
	sudo dnf install gcc gcc-c++ make bison flex gmp-devel libmpc-devel mpfr-devel texinfo grub2-tools-extra xorriso grub2 qemu
    elif [ $DISTRO = "DEBIAN" ]; then
	sudo apt install build-essential bison flex libgmp3-dev libmpc-dev libmpfr-dev texinfo libcloog-isl-dev libisl-dev xorriso grub2 qemu
    elif [ $DISTRO = "GENTOO" ]; then
	echo "Please set QEMU_PLATFORMS="i386" in make.conf"
	sudo emerge --ask sys-devel/gcc sys-devel/make sys-devel/bison sys-devel/flex dev-libs/gmp dev-libs/mpc dev-libs/mpfr sys-apps/texinfo dev-libs/cloog dev-libs/isl sys-boot/grub:2 dev-libs/libisoburn qemu
    elif [ $DISTRO = "OPENBSD"]; then
	echo "You'll need to build xorriso. YOU HAVE BEEN WARNED."
	doas pkg_add bison flex gmp libmpc mpfr texinfo qemu
    fi
}

printf "Starting install...\n"
getdistro
while true; do
    printf "Do you wish to install programs required for this build?\n[Y/N]: "
    read yn
    case $yn in
	[Yy]* ) installpkg; break;;
	[Nn]* ) exit;;
	* ) echo "Please answer yes or no.";;
    esac
done
printf "Now run build-tools.sh to install the rest of the toolchain.\n"
