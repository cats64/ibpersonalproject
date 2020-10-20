#!/bin/sh
# qemu.sh: Start a QEMU emulator from the arch built
set -e
. ./iso.sh

qemu-system-$(./target-triplet-to-arch.sh $HOST) -cdrom simpleos.iso
