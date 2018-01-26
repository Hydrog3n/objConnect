#!/bin/bash

PROJECTPATH=`pwd`
BUILDROOTDIR="../buildroot/"
if [ ! -d $BUILDROOTDIR ]; then 
	git clone git://git.buildroot.net/buildroot ../buildroot
	make beaglebone_defconfig
	make
fi

echo $BUILDROOTDIR

## Build client udp
CLIUDPDIR="./src/cliudp"
cd $CLIUDPDIR
make
#cp $CLIUDPDIR/udp $BUILDROOTDIR/output/
make clean
cd $PROJECTPATH



## Prepare buildroot config and target
cp ./config/.config $BUILDROOTDIR
cp -r ./target/* $BUILDROOTDIR/output/target/

## Build 
cd $BUILDROOTDIR
make

