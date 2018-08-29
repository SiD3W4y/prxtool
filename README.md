PRXTool
=======
This is a simple tool to manipulate Sony PSP(tm) PRX files. Prxtool can:

* output an IDC file which can be used with IDA Pro
* output an ELF file
* output a Radare2 script file to be used by r2
* disassemble PRX files into a pretty printed format

Installation
------------

To compile `prxtool`, run:

    $ ./bootstrap
    $ ./configure
    $ make

You can install it by running:

    $ [sudo] make install

You can load the radare2 script from r2 as such:
```
$ r2 <your bin>
[0x00000000] . <your symbol file>
```

Modifications from the original
-------------------------------
* Added a --r2out / -2 option to output a radare2 script
* Added a NidNames file containing all nids scraped from PPSSPP
* This will try to resolve the nid names from the numbers if possible

License
-------

TyRaNiD (c) 2k6

PRXTool is licensed under the AFL v2.0. Please read the LICENSE file for further
information.

Thanks to

* Mrbrown for adding autoconfig
* all the other people who contribute to legit PSP dev work.

This is a good companion to libdoc as that provides the XML file used to get
names and such for functions.

