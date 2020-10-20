#!/bin/sh
# headers.sh: install headers into our OS (we will need these for future apps)
set -e
. ./config.sh

mkdir -p "$SYSROOT"

for PROJECT in $SYSTEM_HEADER_PROJECTS; do
  (cd $PROJECT && DESTDIR="$SYSROOT" $MAKE install-headers)
done
