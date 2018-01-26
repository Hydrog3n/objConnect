#!/bin/bash

PROJECTPATH=`pwd`
BUILDROOTDIR="../buildroot"
if [ ! -d $BUILDROOTDIR ]; then 
	git clone git://git.buildroot.net/buildroot ../buildroot
	make beaglebone_defconfig
	make
fi

echo $BUILDROOTDIR

## Copy all packages in build root
cp -r package/* $BUILDROOTDIR/package

## Prepare buildroot config and target
cp ./config/.config $BUILDROOTDIR
cp -r ./target/* $BUILDROOTDIR/output/target/

## Build 
cd $BUILDROOTDIR
make

