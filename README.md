# ee445l-linux

A complete repository for writing, compiling and flashing code for the TI Stellaris, along with a sample project. Based on a completely open-source toolchain, without the need to rely on cumbersome development environments.

![TM4C123GXL](https://github.com/jishminor/ee445l-linux/blob/master/TivaWare/.metadata/images/TivaWare.png)

Tested on OS X and Ubuntu 16.04. Should work on most GNU/Linux/POSIX environments.

## Requirements

 - [ARM EABI Toolchain Builder](https://github.com/jsnyder/arm-eabi-toolchain)
 - [lm4tools](https://github.com/utzig/lm4tools)
 - [TI Stellaris TM4C123GXL dev board](http://www.ti.com/tool/EK-TM4C123GXL)

Follow the instructions in the next section to install the required packages.

## Installing

1. Create a duplicate of this repository for you own local development by doing the following:
    1. Create a new github repository and name it to your liking. Make sure it is **Private**.
    2. Open terminal.
    3. Create a bare clone of the repository:
        ```
        $ git clone --bare https://github.com/jishminor/ee445l-linux.git
        ```
    4. Mirror push to the new repository made in step i:
        ```
        $ cd ee445l-linux.git
        $ git push --mirror https://github.com/exampleuser/your-repository.git
        ```
    5. Remove the temporary local repository you created in step iii:
        ```
        $ cd ..
        $ rm -rf ee445l-linux.git
        ```
    6. Now navigate to a directory of your choice and clone your new repository:
        ```
        $ git clone https://github.com/exampleuser/your-repository.git
        ```

2. In the root directory of your repo, run
    
    For OS X:
    ```
    $ bash setup-osx.sh
    ```
    For Linux:
    ```
    $ bash setup-linux.sh
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


**Good Practice**: The shared directory is great for placing the modules you write that can be shared across projects.
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
    
For OS X:
    ```
    $ make flash
    ```
    
For Linux:
    ```
    $ sudo make flash
    ```

To clean up the directory:
```
$ make clean
```

### Debugger
The debugger requires gdb-arm-none-eabi and openocd in addition to the other dependencies. They should also be installed by the install script.  

To start debugging, run the following commands in your project folder:  
```
$ sudo make flash
$ make debug
```

Then run the following GDB commands:  
```
(gdb) target remote localhost:3333
(gdb) monitor reset halt
(gdb) load
```
It might print an message in the middle, but it seems to not be a problem as long as you flash the board with the project you're debugging beforehand.  
Now everything is ready to go like a normal GDB session. Set any desired breakpoints and then type `continue` or `c` to continue running the program.  

When your done with your session:
```
(gdb) q
```
and don't forget to kill openocd:
```
sudo pkill openocd
```

## Authors

* **Josh Minor** - [jishminor](https://github.com/jishminor)
* **Sean Kirmani** - [kirmani](https://github.com/kirmani)

## Acknowledgments

* Thanks to Christian Jann for his tutorial https://www.jann.cc/2012/12/11/getting_started_with_the_ti_stellaris_launchpad_on_linux.html
