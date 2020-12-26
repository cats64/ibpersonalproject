#!/bin/sh
# qemu.sh: Start a QEMU emulator from the arch built
set -e
. ./iso.sh
renice -n 19 $$ &>/dev/null
qemu-system-$(./target-triplet-to-arch.sh $HOST) -cdrom simpleos.iso
