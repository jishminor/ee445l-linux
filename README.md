# ee445l-linux

A complete repository for writing, compiling and flashing code for the TI Stellaris, along with a sample project. Based on a completely open-source toolchain, without the need to rely on cumbersome development environments.

![TM4C123GXL](https://media.licdn.com/mpr/mpr/AAEAAQAAAAAAAAUoAAAAJDEyNWNhMmY0LWMxZGQtNDBhNC1iYjM2LWE0OTQ5OWQ4ZDA2Ng.jpg)

Tested on OS X. Should work on most GNU/Linux/POSIX environments.

## Requirements

 - [ARM EABI Toolchain Builder](https://github.com/jsnyder/arm-eabi-toolchain)
 - [lm4tools](https://github.com/utzig/lm4tools)
 - [TI Stellaris TM4C123GXL dev board](http://www.ti.com/tool/EK-TM4C123GXL)
 - bash


## Installing

1. Fork this repository then clone your forked copy into your directory of choice locally.

2. In the root directory, run
    ```
    $ bash setup.sh
    ```
    to install all dependencies.
3. If prompted to override rwxr-xr-x  root/admin for /usr/local/bin/lm4flash, enter y and press enter.

## Run Test Project

Hook up an unlocked TM4C via USB on the debug port (top).
Move to the TestProject directory then build the project and flash by running:
```
$ cd TestProject
$ make flash
```
If all goes correctly, the blue LED should come on and your up and running!

## Working on a New Project

The general workflow for beginning a new project is a follows:
1. Create directory in git root directory corresponding to the lab you are working on (ie lab1, lab2, etc). To use the given gitignore, make sure it is all lower case.
    ```
    $ mkdir lab1
    ```
2. Copy over _Makefile_ from the TestProject directory into the new lab directory.
    ```
    $ cp TestProject/Makefile lab1/
    ```
3. Run text editor of choice to modify lab1/Makefile, for example vim
    ```
    $ vim lab1/Makefile
    ```
4. Find the line
    ```
    PROJ_NAME = TestProject
    ```
    and change it to
    ```
    PROJ_NAME = lab1
    ```
5. Add all the starter files you need to the lab1 directory and get coding!


**Good Practice**: The shared directory is great to for placing the modules you write that can be shared across projects.
There's already a few in there from ValvanoWare which you will find useful through the semester.
To include files from this directory in your projects just place a
```c
#include shared/your_file.h
```
at the top of a c file which you need the module in.

## Usage
To build project in current directory:
```
$ make
```

To flash the TM4C:
```
$ make flash
```

To clean up the directory:
```
$ make clean
```

## Authors

* **Josh Minor** - [jishminor](https://github.com/jishminor)
* **Sean Kirmani** - [kirmani](https://github.com/kirmani)

## Acknowledgments

* Thanks to Christian Jann for his tutorial https://www.jann.cc/2012/12/11/getting_started_with_the_ti_stellaris_launchpad_on_linux.html
