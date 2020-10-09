#!/bin/sh 
# BUILD.SH
# Note: you must have /bin/sh reflect a POSIX shell. 
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
build_kernel() 
{
	printf "${PRL}=>${GRY} Starting kernel build... ${NC}\n"
}

# A function that does its namesake.
build_libc() 
{
	printf "${PRL}=>${GRY} Starting libc build... ${NC}\n"
}

# A function that enables certain features.
set_vars()
{
	# Check to see if we can make the build faster. If so, enable it.
	if [ $1 = "-k" ]; then
	printf "${BLU}=>${GRY} Multithreaded build has been enabled.\n"
	MPROC=1 
	else
	printf "${BLU}=>${GRY} Multithreaded build has been disabled.\n"
	MPROC=0 
	fi
}

printf "${YLW}=>${GRY} Starting build... ${NC}\n"
printf "${YLW}=>${GRY} Setting build variables... ${NC}\n"
set_vars $1
printf "${YLW}=>${GRY} Build variables have been set. ${NC}\n"
build_kernel
build_libc
printf "${YLW}=>${GRY} There is nothing to do. ${NC}\n"
exit
