# Nm-otool
C implementation of Unix binary analysis tools nm &amp; otool -t  
This project was helpful to learn about the structure and variety of macho-o files

## Features
- Concise code able to handle different types of macho-o files from a variety of architectures using a single algorithm  
- Protected against corrupted binaries (checkoverflow)

### Supported files
- 32bit and 64bit binaries
- Big and Small endian binaries
- Archives
- FAT binaries

## Useful links
[Macho file format reference](https://github.com/aidansteele/osx-abi-macho-file-format-reference)  
[Comparison of different executable file formats](https://en.wikipedia.org/wiki/Comparison_of_executable_file_formats)  
[Big and little endian](https://medium.com/worldsensing-techblog/big-endian-or-little-endian-37c3ed008c94)  
[Symbol types from ```nm``` Linux man page](https://linux.die.net/man/1/nm)  
