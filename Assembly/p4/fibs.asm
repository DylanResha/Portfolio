; Dylan Resha
; Assignment 4 fibonacci Sequence
; 10/02/2020
; Write assembly language code that, using the first two digits of the fibonacci sequence calculates and adds the first 16 values of fibonacci together  
;Manually assign the first two Fibonacci numbers to your array Fibs.
;Calculate the 14 missing Fibs, and place them in the correct location of Fibs.
;Place the label “done:” after the Fibs array is completed, and before normal termination.
;You may do this manually, or, look ahead and use a loop.  The loop is not required.
 

SECTION .data
; define data/variables here.  Think DB, DW, DD, DQ


SECTION .bss
; define uninitialized data here
Fibs: RESD 16

SECTION .text
global _main
_main:
; put your code here
 mov eax, 0
 mov [Fibs], eax
 mov eax, 1
 mov [Fibs+2], eax
 mov ebx,0

 top:
 cmp ebx,14
 jge done

   mov edx,[Fibs+ebx*2]
        inc ebx
b1:
   add edx,[Fibs+ebx*2]
b2:
        inc ebx
   mov [Fibs+ebx*2],edx
        dec ebx
  jmp top

done:
; Normal termination code
mov eax, 1
mov ebx, 0
int 80h
