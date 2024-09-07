Call to Power 2 - SDL2

This version uses SDL2 by default on Windows as well as GNU/Linux distro's to provide a smoother, more seamless experience for all users on all systems (macOS coming soon too).

GNU/Linux Compilation Guide

1. Make sure all dependencies are installed 'bison, flex, etc..' as well as development libs for SDL2, SDL2 Image and SDL2 Mixer

2. Use the makefile or the configure script to compile

======================================================

Windows Compilation Guide

1. Set System Variables:
CDKDIR: Set the CDKDIR environment variable to point to the bin directory where the binaries for Flex, Bison, and other necessary tools are located within the repository.

3. Configure Build Settings:
Set the build configuration to 64-bit and Final.

5. Compile Map DLL Projects:
Begin by compiling the Crater, and other map-related DLL projects.

7. Compile the Game:
Once the map projects are compiled, compile the game project ctp2.

9. Locate Compiled Files:
After the compilation, you will find the compiled binary along with the dependent DLL files in the map directory.
