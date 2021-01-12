; Dylan Resha	
; 11/11/2020
; Asignment 9 sort
; For this assignment you are to create an assembly language program named sort.asm, in a folder named p9, that will print out a sequence of integers, sort them in increasing order, and print them out again.
%macro Print 2
pusha
	 mov eax, 4     ; syswrite
         mov ebx, 1     ; stdout
         mov ecx, %1    ; starting address of string
         mov edx, %2  ; len of string
         int 80h
popa
%endmacro

%macro	PrintArray 2
pusha
mov ebx,0
%%top:
	mov    al,[%1+ebx]
	inc ebx
	call    _convert
	Print   output,4

	cmp	ebx,%2
	jl 	%%top
popa		
%endmacro

%macro SortArray 2
pusha
mov ebx,0
mov ecx,%2
;mov esp,%1

%%outter:
%%inner:
;Print nl,4;;;visual debug
;PrintArray nums,numslen
	mov al,[%1+ebx]
	mov dl,[%1+ebx+1]
	
	cmp dl,al
	jb 	%%true
	jmp %%false

	%%true:
	  mov [%1+ebx+1],al
	  mov [%1+ebx],dl
	%%false:
	inc ebx	
	cmp ebx,%2-1
	jl	%%inner

mov ebx,0
loop %%outter

popa
%endmacro


SECTION .data
nums:	db	100, 200, 5, 10, 0, 88, 22; should work with more
numslen:	EQU	($-nums)

nl: db	"   ",10
output:	db	"   ",10
hundred: db	100
ten: db		10

oaheader:       db      "Original Array",10         
oalen: EQU      ($-oaheader)

saheader:	db	"Sorted Array",10
salen: EQU	($-saheader)

; Clear Screen control characters 
cls	db	1bh, '[2J' 

; Set cursor position control characters
pos	db	1bh, '[' 
row	db	'00'
	db	';'
col	db	'00'
	db	'H'

; Data structure 

SECTION .text
global _main, _clrscr,_convert
_main:

call 	_clrscr
Print 	oaheader,oalen;header for original Array
PrintArray nums,numslen;print original array
SortArray nums,numslen
Print saheader,salen;header for Sorted Array
PrintArray nums,numslen;print Sorted Array

lastBreak:
; Normal termination code
	mov eax, 1
	mov ebx, 0
	int 80h

_clrscr:
	pusha
        mov     eax,4
        mov     ebx,1
        mov     ecx,cls
        mov     edx,4
        int     80h
	popa
	ret


_convert:
	pusha
	
	mov	ebx,output
	xor 	ah,ah
	div	BYTE [hundred]
	add	al,'0'
	mov	[ebx],al
	inc	ebx
	shr	ax,8
	div	BYTE [ten]
	add	al,'0'
	mov	[ebx],al
	add	ah,'0'
	inc	ebx
	mov	[ebx],ah	

	popa
	ret
	




