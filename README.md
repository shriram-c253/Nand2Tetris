# Nand2Tetris
Solutions to the Nand2Tetris course projects, available from https://www.nand2tetris.org/

This is a set of solutions to the Nand2Tetris projects available from the website linked above. The first five projects consist of 
designing
of circuits to build the Hack microarchitecture, starting from a NAND gate and finishing with a 16-bit instruction CPU and Memory
architecture. The solutions to each circuit design is present in the .hdl file.

The second half of the course includes Projects 6-12, which involve coding of an assembler for Hack, a LLVM translator and a compiler
for the language JACK. The compiler in which these codes are written is C++14. The recommended compiler is GNU G++14.

The HACK Assembler can be executed with the following commands:
```
$ g++ -std=c++14 HackAssembler.cpp -o HackAssembler
$ ./HackAssembler file_name.asm
```
This will generate a file_name.hack file that can be directly executed by the Hack architecture.

The LLVM Translator can be executed with the following commands:
```
$ g++ -std=c++14 VMTranslator.cpp -o VMTranslator
$ ./VMTranslator file_name.vm
```
This will generate a file_name.asm file that can be assembled diretly.

The Jack Compiler can be executed with the following commands:
```
$ g++ -std=c++14 JackCompiler.cpp -o JackCompiler
$ ./JackCompiler file_name.jack
```
This will generate a file_name.vm file that can be interpreted with a translator and produces intermediate files file_name.err
file_name.tok and file_name.anz. You can also compile multiple files:
```
$ g++ -std=c++14 JackCompiler.cpp -o JackCompiler
$ ./JackCompiler file1_name.jack file2_name.jack file3_name.jack
```
This will produce all VM files.
