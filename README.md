# tesf-loadorder
A simple mod manager for The Elder Scrolls and Fallout games running through Proton on Linux

## Building

Make sure you have the packages necessary to compile c code installed

Install ncurses

Clone or download the repository

While inside the downloaded directory, compile and install the program with
```
make install
```

run the program with
```
tesf
```


## Installing mods

Using the installer will help you avoid case sensitivity related problems you might encounter in manual installation. FOMOD installers or similar are not supported.

Launching the program for the first time creates a directory called "Mods" inside the game directory. To install a mod, Unpack the downloaded archive into its own directory inside the Mods directory. It should now show up as available to install. 

Sometimes the program might crash when installing a large mod. Just restarting the program and trying again should work. I'm looking into fixing this.
