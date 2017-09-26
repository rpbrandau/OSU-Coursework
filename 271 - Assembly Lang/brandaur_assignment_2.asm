TITLE Fibonacci Numbers     (brandaur_assignment_2.asm)

; Author: Riley Brandau
; Course / Project ID: 271-400                Date:10/14/16
; Description: Generates a Fibonacci sequence for a specified amount of terms

INCLUDE Irvine32.inc
; (insert constant definitions here)
maxTerms = 46			;maximum amount of terms allowed

.data
; (insert variable definitions here)
userName	BYTE 33 DUP(0)			
intro_1		BYTE "Fibonacci Numbers",0
intro_2		BYTE "Programmed by Riley Brandau",0
userNum		DWORD ?
name_prompt	BYTE "What is your name? ",0
greeting	BYTE "Hello, ",0
user_prompt1	BYTE "Enter the number of Fibonacci terms to be displayed.",0
user_prompt2	BYTE "Please give an integer in the range of 1 through 46. ",0
error_msg	BYTE "Out of range.",0
outro_1		BYTE "Results certified by Riley Brandau.",0
outro_2		BYTE "Goodbye, ",0	
padding		BYTE "     ",0 ;5 spaces to be put inbetween terms
fibPrev		DWORD ?
termCount	DWORD 0

.code
main PROC
; (insert executable instructions here)


;1.a) Display the Program's name "Fibonacci Numbers"
	mov		edx, OFFSET intro_1
	call	WriteString
	call	CRLF
;1.b) Display the programmer's name: "Programmed by Riley Brandau"
	mov		edx, OFFSET intro_2
	call	WriteString
	call	CRLF
	call	CRLF
;2.a) Ask for the user's name
	mov		edx, OFFSET name_prompt
	call	WriteString
	mov		edx, OFFSEt userName
	mov		ecx, 32
	call	ReadString
	
;2.b) Greet the user using their name
	mov		edx, OFFSET	greeting
	call	Writestring
	mov		edx, OFFSET userName
	call	WriteString
	call	CRLF

;3.a) Prompt the user to enter the number of terms to be entered (1 through 46)
	mov		edx, OFFSET user_prompt1
	call	WriteString
	call	CRLF
	mov		edx, OFFSET user_prompt2
	call	WriteString
	call	CRLF

;3.b) Get user's input
Start:
	call	ReadInt
	mov		userNum, eax
	
;3.c) check if user's input is within range
	mov		eax, userNum
	cmp		eax, maxTerms
	jg		ValError
	cmp		eax, 0
	jle		ValError
	jg		Calculations
;3.d) if out of range, issue warning and restate prompt
ValError:
	mov		edx, OFFSET error_msg
	call	WriteString
	call	CRLF
	mov		edx, OFFSET user_prompt2
	call	WriteString
	call	CRLF
	jmp		Start

;4.a) Display the fibonacci terms, 5 terms to a line separated by 5 spaces
Calculations:
	;dec		userNum
	mov		ecx, userNum
	mov		eax, 0
	mov		ebx, 1
	cmp		userNum, 3
	jl		L3

L1:
	mov		fibPrev, eax
	add		eax, ebx
	call	WriteDec
	mov		edx, OFFSET padding
	call	WriteString
	mov		ebx, fibPrev
	inc		termCount
	cmp		termCount, 5
	je		L2
	loop	L1
	jmp		Outro

L2:													;adds a line break when the term count = 5
	call	CRLF
	mov		termCount, 0
	dec		ecx
	cmp		ecx, 0
	je		Outro
	jmp		L1

L3:
	mov		eax, 1
	call	WriteDec
	mov		edx, OFFSET padding
	call	WriteString
	loop	L3


;5.a) Display "Results certified by Riley Brandau"
Outro:
	call	CRLF
	mov		edx, OFFSET outro_1
	call	WriteString
	call	CRLF
	
;6.a) Say goodbye to the user.
	mov		edx, OFFSET outro_2
	call	WriteString
	mov		edx, OFFSET userName
	call	WriteString
	call	CRLF


	exit	; exit to operating system
main ENDP
; (insert additional procedures here)

END main
