# ee445l-linux

A complete repository for writing, compiling and flashing code for the TI Stellaris, along with a sample project. Based on a completely open-source toolchain, without the need to rely on cumbersome development environments.

Tested on OS X. Should work on most GNU/Linux/POSIX environments.

## Requirements

 - [ARM EABI Toolchain Builder](https://github.com/jsnyder/arm-eabi-toolchain)
 - [lm4tools](https://github.com/utzig/lm4tools)
 - [TI Stellaris TM4C123GXL dev board](http://www.ti.com/tool/EK-TM4C123GXL)
 - bash


## Installing

Clone this repository into your directory of choice.

In the root directory, run
```
bash setup.sh
```
to install all dependencies.

### Run Test Project

Hook up an unlocked TM4C via usb on the debug port (top).
Move to the TestProject Directory and attemp to make and flash the board.
```
cd TestProject
make flash
```
This should create the object file and flash the board.
If all goes correctly the blue LED should come on.

## Working on a New Project

The general workflow for beginning work on a new project is a follows:
1. Create directory in git root directory corresponding to the lab you are working on (ie lab1, lab2, etc). To use the given gitignore, make sure it is all lower case.
```
mkdir lab1
```
2. Copy over _Makefile_ from the TestProject directory into the new lab directory.
```
cp TestProject/Makefile lab1/
```
3. Run text editor of choice to modify lab1/Makefile, for example vim
```
vim lab1/Makefile
```
4. Change the line
```
PROJ_NAME = TestProject
```
to
```
PROJ_NAME = lab1
```
5. Add all the starter files you need to the lab1 directory and get coding!


The shared directory is great to for placing the modules you write that can be shared across projects.
To include files from this directory in your projects just place a
```c
#include shared/your_file.h
```
at the top of a c file which you need the module in.

## Authors

* **Josh Minor** - [jishminor](https://github.com/jishminor)
* **Sean Kirmani** - [kirmani](https://github.com/kirmani)

## Acknowledgments

* Thanks to Christian Jann for his tutorial https://www.jann.cc/2012/12/11/getting_started_with_the_ti_stellaris_launchpad_on_linux.html
