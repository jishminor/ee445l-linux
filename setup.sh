#!/bin/sh
#
# setup.sh
# Copyright (C) 2017 Josh Minor <joshminor@utexas.edu>
#
# Distributed under terms of the MIT license.
#
# This script sets up the build environment.
PROJECT_DIR=`pwd -P`

which -s brew
if [[ $? != 0 ]] ; then
    # Install Homebrew
    ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
else
    brew update
fi

#get ARM toolchain
brew tap PX4/homebrew-px4
brew update
brew install gcc-arm-none-eabi

#add toolchain to path if not present
LINE='export PATH="$PATH:/usr/local/Cellar/arm-gcc-bin/6-2017-q2-update/bin/"'
grep -qF "$LINE" ~/.bashrc || echo "$LINE" >> ~/.bashrc

#install libusb
brew install libusb

#get lm4flash
rm /usr/local/bin/lm4flash
rm -rf lm4tools
git clone https://github.com/utzig/lm4tools.git
cd lm4tools/lm4flash/
make
sudo cp lm4flash /usr/local/bin/
cd ../..
rm -rf lm4tools

exit 0


