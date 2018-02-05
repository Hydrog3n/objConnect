#!/bin/bash

PROJECTPATH=`pwd`
BUILDROOTDIR="../buildroot"
if [ ! -d $BUILDROOTDIR ]; then
	echo "add buildroot" 
	git clone git://git.buildroot.net/buildroot ../buildroot
	cd $BUILDROOTDIR
	git checkout 2017.11.x
	git pull origin 2017.11.x
	make beaglebone_defconfig
	make
	cd $PROJECTPATH
fi


## Copy all packages in build root
echo "Copy packages"
cp -r package/* $BUILDROOTDIR/package

## Prepare buildroot config and target
echo "Copy config"
cp ./config/.config $BUILDROOTDIR
cp -r ./target/* $BUILDROOTDIR/output/target/

## Build 
echo "Build"
cd $BUILDROOTDIR
make

