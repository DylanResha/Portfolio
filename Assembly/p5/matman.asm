; Dylan Resha
; Assignment 5 Matrix Managment
; 10/09/2020
;  Write an assembly language program, named matman.asm, in a folder named p5,  that defines an arbitrary two-dimensional array of signed integers in the data segment.  You should also define constants ROWS and COLS that specify the actual number of rows and columns in the matrix. Your code should calculate the sum of each row and place the sum in the corresponding slot of the array RowSums. Your code should also calculate the sum of each column and place the sum in the corresponding slot of the array ColSums. A grand total should also be calculated (sum of all integers in the matrix).  Two test cases are given below.  You should run your code on each, and verify your code is working . Your code should also work for other matrices properly defined.  You may define additional variables to assist you with this assignment. 

ROWS:   EQU     5       ; defines a constant ROWS set to 5.
COLS:   EQU     7       ; defines a constant COLS set to 7.
 

SECTION .data
; define data/variables here.  Think DB, DW, DD, DQ


MyMatrix: 	dd	 1,  2,  3,  4,  5,  6,  7
	    	dd	 8,  9, 10, 11, 12, 13, 14
		dd	15, 16, 17, 18, 19, 20, 21
		dd	22, 23, 24, 25, 26, 27, 28
		dd	29, 30, 31, 32, 33, 34, 35
SECTION .bss
; define uninitialized data here

RowSums:	RESD ROWS
ColSums:	RESD COLS
Sum:		RESD 1
saveECX: 	RESD 1

SECTION .text
global _main
_main:
; put your code here
	
        mov     ecx,ROWS
	mov     eax,0
           
Routter:

        mov     [saveECX],ecx   ;;;   Save this loop count so you can start another loop count
;;inner loop
        mov     ecx,COLS           
Rinner:
	inin:
	add	eax,[MyMatrix+ecx*2]
        loop    Rinner           
        mov     ecx,[saveECX]   ;;;   Restore outter loops count
        mov     [RowSums+ecx*2],eax
	loop    Routter          


break:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;coloumns sum
        mov     ecx,COLS
        mov     ebx,0

coutter:

        ;mov    [RowSums+ecx*4],eax
        mov     [saveECX],ecx   ;;;   Save this loop count so you can start another loop count
;;inner loop
        mov     ecx,ROWS
cinner:
        
        add     ebx,[MyMatrix+ecx*2]
        loop    cinner
        mov     ecx,[saveECX]   ;;;   Restore outter loops count
        mov     [ColSums+ecx*2],ebx
        loop    coutter
;;total sum
        mov     ecx,COLS
        mov     edx,0

toutter:

        ;mov    [RowSums+ecx*4],eax
        mov     [saveECX],ecx   ;;;   Save this loop count so you can start another loop count
;;inner loop
        mov     ecx,ROWS
tinner:

        add     edx,[MyMatrix+ecx*2]
        loop    tinner
        mov     ecx,[saveECX]   ;;;   Restore outter loops count
        loop    toutter

mov [Sum],edx

total:
		
	
lastBreak:
; Normal termination code
mov eax, 1
mov ebx, 0
int 80h
