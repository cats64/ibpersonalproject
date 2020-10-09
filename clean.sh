#!/bin/sh 
# CLEAN.SH
# Note: you need to build the kernel first!
#
set -e
# Okay, first we come up with ANSI escape codes.
# This allows us to create color-printed text, and that looks good.
RED='\033[31m' # Red
BLU='\033[34m' # Blue
GRN='\033[32m' # Green
YLW='\033[33m' # Yellow
WHT='\033[37m' # White
PRL='\033[35m' # Purple
GRY='\033[37m' # Technically gray
NC='\033[0m' # No color

# A function that does its namesake.
clean_kernel_libc() 
{
	printf "${PRL}=>${GRY} Removing files...\n"
	printf "${PRL}=>${GRY} All files have been removed.\n"
}
printf "${YLW}=>${GRY} Starting clean... ${NC}\n"
clean_kernel_libc
printf "${YLW}=>${GRY} All operations done. ${NC}\n"
exit
