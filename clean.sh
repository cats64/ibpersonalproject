#!/bin/sh
# clean.sh: A function that removes bloat after build
set -e
. ./config.sh

for PROJECT in $PROJECTS; do
  (cd $PROJECT && $MAKE clean)
done

rm -rf sysroot
rm -rf isodir
rm -rf simpleos.iso

test commit
