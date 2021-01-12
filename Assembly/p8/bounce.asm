; Dylan Resha	
; 11/6/2020
; Asignment 8 Bounce
;For this assignment you are to create an assembly language program named bounce.asm that will perpetually  “bounce” a message from left to right, and back on your console screen.
%macro Print 2
	 mov eax, 4     ; syswrite
         mov ebx, 1     ; stdout
         mov ecx, %1    ; starting address of string
         mov edx, %2  ; len of string
         int 80h

%endmacro

%macro setCursor 2

        mov     ah,%1
        mov     al,%2
        call   	cursor

%endmacro

SECTION .data

message:	db	" "  ;;; one space
		db	"Have You heard the tale of Darth Plaguis the Wise"
		db	" "  ;;; one more space
msglen:	EQU	($-message)


; counter:	db	0
; Clear Screen control characters 
cls	db	1bh, '[2J' 

; Set cursor position control characters
pos	db	1bh, '[' 
row	db	'00'
	db	';'
col	db	'00'
	db	'H'

; Data structure 
sec	dd	0,100000000
count	db	0 ;;our counter that denotes the current coloumn

SECTION .text
global _main, _sleep, cursor, _clrscr
_main:

mov ebp,0
mov [count],ebp;;making sure count is 0
;;;;  call _setcursor   pass ah=row, al=col

inctop:;;incrementing loop
call _clrscr
	setCursor 10,[count];;positions the cursor for printing
	Print message,msglen;; prints our message
	call    _sleep;; sleep to slow down the bounce

	mov ebp, [count];;mov our counter into a register for comparing
	cmp ebp,79-msglen;;cmp our counter to 79- our msg length
	je dec;;jump to decrementing when we get to a total of 79 colomns to the right
inc:
	inc ebp
	mov [count], ebp

loop inctop

dectop:;;decrementing loop
call _clrscr

	setCursor 10,[count]
	Print message,msglen
	call    _sleep

	mov ebp,[count]
	cmp ebp,0 ;;compare our counter to zero if equal send back to the right
	je inc
dec:
	dec ebp
	mov [count], ebp

loop dectop

; Normal termination code
	mov eax, 1
	mov ebx, 0
	int 80h

;. _setcursor expects AH = row, AL = col
;  Only works for 1 or 2 digit numbers.
cursor:
	pusha
;;; save original to get col later
	push	eax
;;;;;; process row
	shr	ax,8	;; shift row to right
	mov	bl,10
	div	bl	;; puts ax/10 in al, remainder in ah
	add	ah,'0'
	add	al,'0'
	mov	BYTE [row],al
	mov	BYTE [row+1],ah
;;;; process col
	pop	eax	;; restore original parms
	and	ax,0FFh ;; erase row, leave col
	mov	bl,10
	div	bl	;; puts ax/10 in al, remainder in ah
	add	ah,'0'
	add	al,'0'
	mov	BYTE [col],al
	mov	BYTE [col+1],ah

	;;;;; now print the set cursor codes
	mov	eax,4
	mov	ebx,1
	mov 	ecx,pos
	mov	edx,8
	int 	80h

	popa
	ret

;;;;; sleep requests sec,nanoseconds pause
_sleep:
	pusha
	mov	eax,162
	mov	ebx,sec
	mov	ecx,0
	int	80h
	popa
	ret

;;
_clrscr:
	pusha
        mov     eax,4
        mov     ebx,1
        mov     ecx,cls
        mov     edx,4
        int     80h
	popa
	ret






