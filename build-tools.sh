#!/bin/sh
set -e
# build-tools.sh: a tool that creates the cross-compiler needed for building
# Not done yet, DON'T RUN THIS
export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

printf "\nThis script is dangerous and being terminated for your safety.\n"
break
printf "Starting build..."
mkdir -p $HOME/opt/cross $HOME/src/{build-gcc,build-binutils}
# we download gcc 10.1 and binutils 2.34
buildbinutils() {
    echo "Building bintutils..."
    cd $HOME/src/build-binutils
    wget https://ftp.gnu.org/gnu/binutils/binutils-2.35.tar.xz
    tar xpvf binutils-2.35.tar.xz
    ../binutils-2.35/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
    make
    make install
}

buildgcc() {
    echo "Building gcc..."
    cd $HOME/src/build-gcc
    wget https://ftp.gnu.org/gnu/gcc/gcc-10.2.0/gcc-10.2.0.tar.xz
    tar xpvf gcc-10.2.0.tar.xz
    ../gcc-10.2.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
    make all-gcc
    make all-target-libgcc
    make install-gcc
    make install-target-libgcc
}

while true; do
    printf "\nDo you wish to build these programs? Installing this may cause high thermal temperatures in the process and will likely lock up your computer. NO REFUNDS.\n[Y\N]: "
    read yn
    case $yn in
	[Yy]* ) buildbinutils; buildgcc; break;;
	[Nn]* ) exit;;
	* ) echo "Please answer yes or no.";;
    esac
done

    
