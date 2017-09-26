TITLE CS271_Assignment_1      (brandaur_assignment_1.asm)

; Author: Riley Brandau
; Course: CS271-400 / Project ID: Assignment_1                 Date: 10/4/16
; Description: displays my name, displays instructions for user, performs calculations on integer input
; Description: EXTRA CREDIT #1 - Program Repeats Until User Chooses to Quit
; Description: Extra CREDIT #2 - Program Validates that the second number is less than the first.
INCLUDE Irvine32.inc

; (insert constant definitions here)

.data
; (insert variable definitions here)
intro_1		BYTE "Greetings, my name is Riley Brandau. This is Assignment #1 for OSU's CS 271-400!" , 0
prompt_1	BYTE "Please enter two integers. I'll show you the Sum, Difference, Product, Quotient, and Remainder." , 0
prompt_2	BYTE "Please make them positive integers. Thank you." , 0
prompt_3	BYTE "First Integer: " , 0
prompt_4	BYTE "Second Integer: " , 0
userNum_1	DWORD ?					; user's first entry stored here
userNum_2	DWORD ?					; user's second entry stored here
addStr		BYTE " + " , 0			
subtractStr	BYTE " - " , 0			; tried to name this "subStr" but got errors...
mulStr		BYTE " * " , 0
divStr		BYTE " / " , 0
equalStr	BYTE " = " , 0
remStr		BYTE " remainder " , 0
addResult	DWORD ?					; addition result stored here
subResult	DWORD ?					; subtraction result stored here
mulResult	DWORD ?					; multiplication result stored here
divResult	DWORD ?					; division result stored here
remResult	DWORD ?					; remainder result stored here
goodBye		BYTE "Sayonara! (Good Bye!)" , 0

; Extra Credit data
ecValidate	BYTE "(Extra Credit #2) Second value was greater than the first!" , 0
loopMsg		BYTE "(Extra Credit #1) Do you want to compare more numbers? 1 for yes, 0 for no: " , 0
ecChoice	DWORD ?
ecContinue	BYTE "Continue calculations anyway? 1 for yes, 0 for no: ", 0

.code
main PROC
; Introduction
	mov		edx, OFFSET intro_1		; set up intro_1
	call	WriteString			    ; print intro_1
	call	CrLF				    ; carriage return line fix (move cursor to next line)

; Give User Instructions
	mov		edx, OFFSET prompt_1	; set up prompt_1
	call	WriteString				; display prompt_1
	mov		edx, OFFSET prompt_2	; set up prompt_2
	call	WriteString				; display prompt_2
	call	CrLF

; Start of Loop
Start:
; Get User Data
	mov		edx, OFFSET prompt_3	; set up prompt_3
	call	WriteString				; display prompt_3
	call	ReadInt					; user input (num 1)
	mov		userNum_1, eax			; store user input in userNum_1
	mov		edx, OFFSET prompt_4	; set up prompt_4
	call	WriteString				; display prompt_4
	call	ReadInt					; user input (num 2)
	mov		userNum_2, eax			; store user input in userNum_2

; Extra Credit - Validation
	mov		eax, userNum_2
	cmp		eax, userNum_1			; comparing the user's numbers
	jg		ValError				; jumps if the 2nd number is > the first
	jle		Calculations			; continues to Calculations if 2nd number is <= first

ValError:
	mov		edx, OFFSET ecValidate
	call	WriteString
	call	CrLF
	mov		edx, OFFSET ecContinue
	call	WriteString
	call	ReadInt
	mov		ecChoice, eax
	cmp		eax, 1
	je		Calculations			; allowing user to continue with calculations
	jne		ecLoop

Calculations:
; Calculate & Display Addition
	mov		eax, userNum_1			; store userNum_1 in EAX
	add		eax, userNum_2			; add userNum_2 to EAX
	mov		addResult, eax			; store result in addResult
; Display Result
	mov		eax, userNum_1			
	call	WriteDec
	mov		edx, OFFSET addStr
	call	WriteString
	mov		eax, userNum_2
	call	WriteDec
	mov		edx, OFFSET equalStr
	call	WriteString				; display addPrompt
	mov		eax, addResult			; set up to display addResult
	call	WriteDec				; display addResult
	call	CrLF					; carriage return


; Calculate & Display Subtraction
	mov		eax, userNum_1
	sub		eax, userNum_2
	mov		subResult, eax
; Display Result
	mov		eax, userNum_1
	call	WriteDec
	mov		edx, OFFSET subtractStr
	call	WriteString
	mov		eax, userNum_2
	call	WriteDec
	mov		edx, OFFSET equalStr
	call	WriteString
	mov		eax, subResult
	call	WriteInt				; using this in case a negative needs to be displayed
	call	CrLF


; Calculate & Display Multiplication
	mov		eax, userNum_1
	mov		ebx, userNum_2
	mul		ebx
	mov		mulResult, eax
; Display Result
	mov		eax, userNum_1
	call	WriteDec
	mov		edx, OFFSET mulStr
	call	WriteString
	mov		eax, userNum_2
	call	WriteDec
	mov		edx, OFFSET equalStr
	call	WriteString
	mov		eax, mulResult
	call	WriteDec
	call	CrLF


; Calculate & Display Division (including remainder)
	mov		edx, 0
	mov		eax, userNum_1
	mov		ebx, userNum_2
	div		ebx
	mov		divResult, eax
	mov		remResult, edx
; Display Result
	mov		eax, userNum_1
	call	WriteDec
	mov		edx, OFFSET divStr
	call	WriteString
	mov		eax, userNum_2
	call	WriteDec
	mov		edx, OFFSET equalStr
	call	WriteString
	mov		eax, divResult
	call	WriteDec
	mov		edx, OFFSET remStr
	call	WriteString
	mov		eax, remResult
	call	WriteDec
	call	CrLF

ecLoop:							; EXTRA CREDIT #1 - Program loops until user wants to quit.
	mov		edx, OFFSET loopMsg
	call	WriteString
	call	ReadInt
	mov		ecChoice, eax
	cmp		eax, 1				; jump to start if user inputs 1
	je		Start

; Display Terminating Message
	mov		edx, OFFSET goodBye
	call	WriteString
	call	CrLF

	exit	; exit to operating system
main ENDP

; (insert additional procedures here)

END main
