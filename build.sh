#!/bin/bash

PROJECTPATH=pwd
if [ ! -d "../buildroot" ]; then 
	git clone git://git.buildroot.net/buildroot ../buildroot
	make
fi

cp ./config/.config ../buildroot/

cp -r ./target/* ../buildroot/output/target/

cd ../buildroot/

make

