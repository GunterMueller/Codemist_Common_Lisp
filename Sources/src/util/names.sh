#!/bin/sh
# echo the CCL name of the configuration
case $1 in
hp9)		type="hp9";;
hp10)		type="hp10";;
axposf1v4)	type=alpha;;
axposf1v3)	type=alpha;;
alpha)		type=alpha;;
linux)		type=linux;;
linuxglibc)	type=linuxglibc;;
sun4os55g)	type="sparc gcc";;
sun4os55c)	type=solaris;;
sun)		type="sparc gcc";;
sgi)		type=sgi;;
irixmips3)	type="sgi mips3";;
irixmips1)	type="sgi mips1";;
rs6000aix4*)	type="aix4 rs6000";;
rs6000aix3)	type="aix3 rs6000";;
*)      type=unknown;;
esac
echo $type
