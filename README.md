# Nm-otool
C implementation of Unix binary analysis tools ```nm``` &amp; ```otool -t```  
This project was helpful to learn about the structure of macho-o files as well as how to parse and analyse them.
- ```nm``` displays the list of **symbols** of a macho-o file.
- ```otool``` hexdumps a specified segment or section of a macho-o file, in this case the ```(__TEXT,__text)``` section.

## Commands
### Build
```bash
make # compile ft_nm & ft_otool executables
make clean # remove object files
make fclean # remove ft_nm & ft_otool executables, remove object files
```

### Testing
Both ```ft_nm``` and ```ft_otool``` can be tested using the binaries in ```/usr/bin/```.

```bash
./ft_nm <object file> <...>
./ft_otool <object file> <...>
```
## Implementation
### Process
Before anything we have to identify the input file.  
We can do this by checking the file **magic number** (first byte of the file) and comparing it to known magic numbers..  
For mach-o files ```<mach-o/loader.h>```:  
```c
#define	MH_MAGIC	0xfeedface	/* the mach magic number */
#define MH_CIGAM	0xcefaedfe	/* NXSwapInt(MH_MAGIC) */
#define MH_MAGIC_64 0xfeedfacf /* the 64-bit mach magic number */
#define MH_CIGAM_64 0xcffaedfe /* NXSwapInt(MH_MAGIC_64) */
```
For FAT binaries (contains executable for multiple platforms)```<mach-o/fat.h>```:  
```c
#define FAT_MAGIC	0xcafebabe
#define FAT_CIGAM	0xbebafeca	/* NXSwapLong(FAT_MAGIC) */
```
For archives  ```<ar.h>```:  
```c
#define  ARMAG   "!<arch>\n"    /* magic string */
#define  SARMAG   8             /* length of magic string */
```

Once we know the type of file we are dealing with, we know its structure.  
All of the structures required to parse through the header, the segments and the sections are defined in ```<mach-o/loader.h>```.

![alt text](https://blog.timac.org/2016/0723-cryptedhelloworld-app-with-encrypted-mach-o-sections/macho.png)

```ft_nm``` will create a virtual list of each symbol found in the ```LC_SYMTAB``` segment command

```c
typedef struct			s_sym
{
	char				*name;
	char				type;
	bool				name_failed;
	uint8_t				n_type;
	uint8_t				n_sect;
	uint64_t			n_value;
}						t_sym;
```

But the information available on each symbol in the ```LC_SYMTAB``` is insufficient. We must then iterate through all of the sections to check the type of sections they come from, and assign it to ```type``` (see ```nm_sym_type.c```).  
Once the list of symbols if complete, all that is left is to print it.  

```ft_otool``` will simply search for the ```__text``` section of the ```__TEXT``` segment and hexdump its data.  

### Features
- Concise code able to handle different types of macho-o files from a variety of architectures using a single algorithm  
- Protected against corrupted binaries (checking file or segment overflows, invalid headers)

### Supported files
- 32bit and 64bit binaries
- Big and Small endian binaries
- Archives
- FAT binaries

## Useful links
[Parsing mach-o files](https://lowlevelbits.org/parsing-mach-o-files/)  
[Macho file format reference](https://github.com/aidansteele/osx-abi-macho-file-format-reference)  
[Comparison of different executable file formats](https://en.wikipedia.org/wiki/Comparison_of_executable_file_formats)  
[Big and little endian](https://medium.com/worldsensing-techblog/big-endian-or-little-endian-37c3ed008c94)  
[Symbol types from ```nm``` Linux man page](https://linux.die.net/man/1/nm)  
