// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.
//int R0,R1,R2;
//while(R1>0)
//R2+=R0,R1--;

@2
M=0
@1
D=M
(Loop)
@End
D;JLE
@0
D=M
@2
M=M+D
@1
MD=M-1
@Loop
0;JMP
(End)
@End
0;JMP