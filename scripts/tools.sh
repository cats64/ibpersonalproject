#!/bin/sh
set -e
# build-tools.sh: a tool that creates the cross-compiler needed for building
export PREFIX="$HOME/.local/bin/crosscompiler"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

# we download gcc 10.1 and binutils 2.34
buildbinutils() {
    echo "Building bintutils..."
    cd $HOME/.cache/build-binutils
    wget https://ftp.gnu.org/gnu/binutils/binutils-2.35.tar.xz
    tar xpvf binutils-2.35.tar.xz
    ../binutils-2.35/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
    make
    make install
}

buildgcc() {
    echo "Building gcc..."
    cd $HOME/.cache/build-gcc
    wget https://ftp.gnu.org/gnu/gcc/gcc-10.2.0/gcc-10.2.0.tar.xz
    tar xpvf gcc-10.2.0.tar.xz
    ../gcc-10.2.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
    make all-gcc
    make all-target-libgcc
    make install-gcc
    make install-target-libgcc
}

starter() {
    mkdir -p $HOME/.local/bin/crosscompiler $HOME/.cache/src/{build-gcc,build-binutils}
}

ender() {
    printf "\nThe build is now complete. The cross compiler has been installed to ~/.local/bin/crosscompiler, you should be able to build the prokect successfuly."
    printf "\nDeleting extra files no longer needed..."
    rm -rf $HOME/.cache/{build-gcc, build-binutils}
    printf "\nDeletion successful."
    
}

while true; do
    printf "\nDo you wish to build these programs? Installing this may cause high thermal temperatures in the process and will likely lock up your computer for a couple moments while GCC builds. NO REFUNDS.\n[Y\N]: "
    read yn
    case $yn in
	[Yy]* ) starter; buildbinutils; buildgcc; ender; break;;
	[Nn]* ) exit;;
	* ) echo "Please answer yes or no.";;
    esac
done

    
