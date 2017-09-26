TITLE Dog Years     (Project00.asm)

; Author: Riley Brandau
; Course / Project ID: 271-400                 Date: 9/26/16
; Description: greets user, calculates their age in dog years

INCLUDE Irvine32.inc

; (insert constant definitions here)
DOG_FACTOR = 7

.data

; (insert variable definitions here)
userName	BYTE	33 DUP(0)	;string to be entered by user
userAge		DWORD	?			;integer to be entered by user
intro_1		BYTE	"Hi, my name is Riley, and i'm here to tell you your age in dog years. " , 0
prompt_1	BYTE	"What's your name? " , 0
intro_2		BYTE	"Nice to meet you, " , 0
prompt_2	BYTE	"How old are you? " , 0
dogAge		DWORD	?
result_1	BYTE	"Wow ... that's " , 0
result_2	BYTE	" in dog years !" , 0
goodBye		BYTE	"Good-Bye, " , 0



.code
main PROC

;Introduce programmer
	mov		edx, OFFSET	intro_1
	call	WriteString
	call	CrLf ;carriage return line fix


;Get user name
	mov		edx, OFFSET prompt_1
	call	WriteString
	mov		edx, OFFSET userName
	mov		ecx, 32
	call	ReadString

;Get user age
	mov		edx, OFFSET prompt_2
	call	WriteString
	call	ReadInt
	mov		userAge, eax


;Calculate user "dog years"
	mov		eax, userAge
	mov		ebx, DOG_FACTOR
	mul		ebx
	mov		dogAge, eax

;Report result
	mov		edx, OFFSET result_1
	call	WriteString
	mov		eax, dogAge
	call	WriteDec
	mov		edx, OFFSET result_2
	call	WriteString
	call	CrLf

;say "good-bye"
	mov		edx, OFFSET	goodBye
	call	WriteString
	mov		edx, OFFSET userName
	call	WriteString
	call	CrLf

	exit	; exit to operating system
main ENDP

; (insert additional procedures here)

END main
