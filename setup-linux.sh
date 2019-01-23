#!/bin/bash
#
# setup.sh
# Copyright (C) 2017 Josh Minor <joshminor@utexas.edu>
#
# Distributed under terms of the MIT license.
#
# This script sets up the build environment.
PROJECT_DIR=`pwd -P`

echo WARNING!: This script relies on apt-get to install packages.

#get ARM toolchain
sudo add-apt-repository ppa:team-gcc-arm-embedded/ppa
sudo apt-get update
sudo apt-get install gcc-arm-embedded
sudo apt-get install gdb-arm-none-eabi
sudo apt-get install openocd

#install pkg-config so that lm4flash makefile builds lm4flash
sudo apt-get install pkg-config

#install libusb
sudo apt-get install libusb-1.0-0-dev

#get lm4flash
file="/usr/local/bin/lm4flash"
if [ -f "$file" ]
then
  rm "$file"
  rm -rf lm4tools
fi
git clone https://github.com/utzig/lm4tools.git
cd lm4tools/lm4flash/
make
sudo cp lm4flash /usr/local/bin/
cd ../..
rm -rf lm4tools

exit 0
