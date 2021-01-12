; Dylan Resha
; Assignment 3 summing integers
; 9/28/2020
; Write assembly language code that sums all of the elements in each of the arrays, and places the sum in the corresponding sum variable. 
; Finally, place a grand total into the grandTotal variable.  Treat all of these values as signed integers.

SECTION .data
; define data/variables here.  Think DB, DW, DD, DQ

bArray:		DB		-1,2,-3,4,-5,6
wArray:		DW		09h,0ah,0bh,0ch,0dh
dArray:		DD		-10,-20,-30,-40,-50
bArraySum:	DB		0
wArraySum:	DW		0
dArraySum:	DD		0
grandTotal:	DD		0

SECTION .bss
; define uninitialized data here

SECTION .text
global _main
_main:

; put your code here
	mov al,[bArray]
	add al,[bArray+1]
	add al,[bArray+2]
	add al,[bArray+3]
	add al,[bArray+4]
	add al,[bArray+5]
	add [bArraySum],al
	
break1:

        mov bx,[wArray]
        add bx,[wArray+2]
        add bx,[wArray+4]
        add bx,[wArray+6]
        add bx,[wArray+8]
        mov [wArraySum],bx

break2:

        mov edx,[dArray]
        add edx,[dArray+4]
        add edx,[dArray+8]
        add edx,[dArray+12]
        add edx,[dArray+16]
        mov [dArraySum],edx
break3:
	
	mov al,[bArraySum]
	mov bx,[wArraySum]
	mov ecx,[dArraySum]
	
	MOVSX eax,al
	MOVSX ebx,bx	

	add ecx,eax
	add ecx,ebx

	mov [grandTotal], ecx
break4:

lastBreak:
; Normal termination code
mov eax, 1
mov ebx, 0
int 80h
