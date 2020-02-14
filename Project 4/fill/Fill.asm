// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.
// if(kbd!=0) screen=black
// else if(kbd==0) screen=white

(Loop)
	@KBD
	D=M
	@Else
	D;JEQ
		@SCREEN
		D=A
		@KBD
		D=D-A
		(Fill)
		@EndIf
		D;JGE
		@KBD
		A=A+D
		M=-1
		D=D+1
		@Fill
		0;JMP
		(EndIf)
		@EndLoop
		0;JMP
	(Else)
		@SCREEN
		D=A
		@KBD
		D=D-A
		(Fille)
		@EndElse
		D;JGE
		@KBD
		A=A+D
		M=0
		D=D+1
		@Fille
		0;JMP
		(EndElse)
	(EndLoop)
@Loop
0;JMP