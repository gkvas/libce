Introduction
------------

This library acts as a compatibility layer for WinCE to provide missing Win32
bits. The initial parts are taken from the Ruby WinCE port. Currently, the
library is driven by the Avian VM port (https://github.com/gkvas/avian/) to 
Windows CE.

Building
--------

Currently, the only way to build is to open the provided Visual Studio 2008
project. 

Organisation
------------

Win32 compatibility is achieved by providing missing functionality via 
additional header files. In case these header files do not exist under Windows
CE, the same name is used in the library. 

Examples: stddef.h (The corresponding implementation shall reside in a file 
                    called stddef.c)

In case the header file already exists, but misses functionality, an additional
header file with the same name, but "_wce" appended to the file name is used.

Examples: stdio_wce.h (The corresponding implementation shall reside in a file 
                       called stdio.c)