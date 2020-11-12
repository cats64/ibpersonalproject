#!/bin/sh
set -e
# build-tools.sh: a tool that creates the cross-compiler needed for building
# Not done yet, DON'T RUN THIS
export arch=i686-elf
export prefix=$1

printf "Downloading GCC sources..."
mkdir -p build/{build-gcc,build-binutils}
# we download gcc 10.1 and binutils 2.34
wget #Save gcc sources
wget #Save binutils sources
cd build/build-binutils
tar xpvf *.xz
./binutils-x.y.z/configure --disable-nls --with-sysroot --arch=$arch
make
make install
cd ../build-gcc
tar xpvf *.xz
./gcc-x.y.z/configure --disable-nls --with-sysroot --arch=$arch
make #figure this out
make install
printf "Build complete, GCC and Binutils are ready for use."
