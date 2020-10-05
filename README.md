# Classroom Post Backup
A simple tool, which can be built for Windows, macOS, and Linux, that makes it easy to archive posts from Google Classroom in a logical format.

## Building on macOS
  1. Firstly, you'll need to install Homebrew if you haven't already.
  2. Once you have installed Homebrew, you'll need to install gcc, pkg-config, and gtk+3. This can be done using the following commands:
    a. `brew install gcc`
    b. `brew install pkg-config`
    c. `brew install gtk+3`
  3. Next, you'll need to download the source file (currently just main.cpp) if you haven't already. You may also change the extention to .c if you wish as the .cpp extension is used, mainly by me, for debugging only; the contents of the file is fully valid C code.
  4. Once you have downloaded main.cpp, you'll need to change the fist line so it looks like this:
    `#define POSIX 1`
  5. Finally, change directory to the folder containing main.cpp and build using the following command:
    ``gcc `pkg-config --cflags gtk+-3.0` -o postbackup main.cpp `pkg-config --libs gtk+-3.0` ``
  6. If everything worked as it should have, you should now be able to run the application using the following command:
    `./postbackup`

## Building on Chrome OS
  1. Firstly, you'll need to install Crostini (a.k.a. Linux (Beta)) if you haven't already; an in-depth guide can be found here: [https://chromeos.dev/en/linux/setup](https://chromeos.dev/en/linux/setup)
  2. Once you have installed Linux (Beta), you'll need to install build-essential and libgtk-3-dev. This can be done using the following commands:
    a. `sudo apt-get install build-essential`
    b. `sudo apt-get install libgtk-3-dev`
  3. Next, you'll need to download the source file (currently just main.cpp) and move it into a folder that appears in the Linux files section if you haven't already. You may also change the extention to .c if you wish as the .cpp extension is used, mainly by me, for debugging only; the contents of the file is fully valid C code.
  4. Once you have downloaded main.cpp, you'll need to change the fist line so it looks like this:
    `#define POSIX 1`
  5. Finally, change directory to the folder containing main.cpp and build using the following command:
    ``gcc `pkg-config --cflags gtk+-3.0` -o postbackup main.cpp `pkg-config --libs gtk+-3.0` ``
  6. If everything worked as it should have, you should now be able to run the application using the following command:
    `./postbackup`
