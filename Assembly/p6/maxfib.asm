; Dylan Resha
; Assignment 6 max fibonacci Sequence
; 10/19/2020
; Write code that calculates the largest unsigned fibonacci number that can be stored in a double word
 

SECTION .data
; define data/variables here.  Think DB, DW, DD, DQ


SECTION .bss
; define uninitialized data here
MaxFib: RESD 1

SECTION .text
global _main
_main:
; put your code here
mov eax, 0
mov ebx, 1

while:

mov ecx,ebx
add ebx,eax
mov eax,ecx
b1:

jnc while

mov [MaxFib],eax

lastBreak:
; Normal termination code
mov eax, 1
mov ebx, 0
int 80h
