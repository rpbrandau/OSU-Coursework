TITLE Assignment6a - Designing Low-Level I/O Procedures    (brandaur_assignment6a.asm)

; Author: Riley Brandau
; Course / Project ID  CS271-400               Date: 11/26/16 (due 12/05/16)
; Description: Gets 10 unsigned integers from the user, stores them in an array,
;              then displays the integers, their sum, and their average.
;			   Uses macros and low-level I/O procedures.

INCLUDE Irvine32.inc
; (insert constant definitions here)

ARRSIZE = 10				 ;number of integers needed

;-------------------------------------------------------------------------------
;*****************************REQUIRED MACROS***********************************
;-------------------------------------------------------------------------------

;*******************************************************************************
;getString MACRO
;Description: Stores the user's input into a memory location
;Parameters: address, length
;*******************************************************************************
getString MACRO strAddress, strLength
	push ecx				 ;save ecx 
	push edx				 ;save edx
	mov edx, strAddress		 ;move userBuffer into edx to be written to
	mov ecx, strLength		 ;move userBuffer length into ecx
	call ReadString			 ;get user input, stores in userBuffer in edx
	pop edx					 ;restore edx
	pop ecx					 ;restore ecx
ENDM

;******************************************************************************
;displayString MACRO
;Description: Writes the string stored in a specified memory location
;Parameters: displayMe
;******************************************************************************
displayString MACRO displayMe
	push edx
	mov edx, OFFSET displayMe   ;load the string to be displayed and write it
	call WriteString
	pop edx
ENDM

.data
; (insert variable definitions here)
;intro variables 
intro_1 BYTE "Macros and Low-Level I/O Procedures",0
intro_2 BYTE "Programmed by: Riley Brandau",0

;program description variables 
desc_1 BYTE "This program will take 10 unsigned integers (up to 32-bit) from the user,",0
desc_2 BYTE "display them, their sum, and their average. ",0

;outro variables 
outro_1 BYTE "Terminating program.",0
outro_2 BYTE "Bye!",0

;user prompt variables 
userPrompt_1 BYTE "Please enter an unsigned integer: ",0

;data validation variables 
errorPrompt_1 BYTE "ERROR: The number you entered was too big or signed.",0

;calculation variables 
numList DWORD 10 DUP(0)		   ;create an array based on what user enters
userBuffer	BYTE 255 DUP(0)    ;stores users number to be placed in array
arrSum DWORD ?				   ;variable to store sum
arrAvg DWORD ?                 ;variable to store average
tempList BYTE 32 DUP(?)		   ;temporary string

;results variables 
resultPrompt_1 BYTE "You entered the following numbers: ",0
resultPrompt_2 BYTE "The sum of entered numbers: ",0
resultPrompt_3 BYTE "The average of entered numbers: ",0


.code
main PROC
; (insert executable instructions here)
;1) Display Program Name, Programmer's Name, and Program Description 
	displayString intro_1				 
	call CRLF
	displayString intro_2
	call CRLF
	call CRLF
	displayString desc_1
	call CRLF
	displayString desc_2
	call CRLF
	call CRLF
	mov ecx, ARRSIZE				;10 integers to be entered
	mov edi, OFFSET numList			;move the number list into edi

;2) Get user's input (readVal invokes getString)
getInput:
	displayString userPrompt_1		;display user prompt
	push OFFSET userBuffer			;buffer to be used for user input
	push SIZEOF userBuffer
	call ReadVal
	mov eax, DWORD PTR userBuffer   ;point to first digit
	mov [edi], eax                  ;move number into numList
	add edi, 4						;advance pointer to next element
	loop getInput					;loop for 10 valid integers

;3) Convert numeric values to a string of digits
;3.b) Display: Output array
	mov ecx, ARRSIZE				;reset loop for displaying array
	mov esi, OFFSET numList         ;load array
	mov ebx, 0                      ;register used for sum
	displayString resultPrompt_1
	call CRLF
;3.c) Calculate Sum
sumArray:
	mov eax, [esi]                  ;load array values into eax
	add ebx, eax                    ;add array values together
	push eax
	push OFFSET tempList
	call WriteVal
	call CRLF
	add esi, 4						;increment pointer
	loop sumArray
;3.d) Display Sum
	mov eax, ebx                    ;move array sum into eax
	mov arrSum, eax
	displayString   resultPrompt_2	;display sum
	push arrSum
	push OFFSET tempList
	call WriteVal
	call CRLF
;3.e) Calculate Average
	mov ebx, ARRSIZE				;dividing by 10 to get average
	mov edx, 0						;prepping edx for division
	div ebx							;eax still holds array sum
	mov arrAvg, eax					;move average into variable
;3.f) Display Average
	displayString resultPrompt_3
	push arrAvg
	push OFFSET tempList
	call WriteVal
	call CRLF
	call CRLF
;4) Display farewell 
	displayString outro_1			    ;passing outro text
	call CRLF
	displayString outro_2			    ;passing outro text
	call CRLF
	call CRLF

	exit	; exit to operating system
main ENDP
; (insert additional procedures here)

;-------------------------------------------------------------------------------
;***************************REQUIRED PROCEDURES*********************************
;-------------------------------------------------------------------------------

;*******************************************************************************
;ReadVal  - invokes the getString macro to get the user's string of digits.
;         - converts the digit string to numeric
;         - validates the user's input
;*******************************************************************************
ReadVal PROC
	push ebp
	mov ebp, esp
	pushad								;saving registers
S:										;changed label from Start to S during testing
	mov edx, [ebp+12]					;address of userBuffer
	mov ecx, [ebp+8]					;size of userBuffer
	getString edx, ecx
	mov esi, edx						;move userBuffer into esi
	mov eax, 0							;clearing eax
	mov ecx, 0							;clearing ecx
	mov ebx, 10							;value to mul by
StepThrough:
	lodsb								;loads from esi
	cmp ax, 0							;search for terminating character
	je Fin								;numeral is complete
	cmp ax, 48							;compare value to '0'
	jl	Error							;if less than '0', display error
	cmp ax, 57							;compare value to '9'
	jg  Error							;if greater than '9', display error
	sub ax, 48							;subtract 48 to arrive at correct numeral
	xchg eax, ecx						;
	mul ebx								;calculate digit's place
	jc	Error							;carry flag was set (value too large)
	jnc Continue						;continue processing
Error:
	displayString	errorPrompt_1		;display error message
	jmp S							;go to start of loop
Continue:
	add eax, ecx						;add the numeral back into eax
	xchg eax, ecx						;exchange to prepare for next loop
	jmp StepThrough						;advance to next byte
Fin:
	xchg ecx, eax
	mov  DWORD PTR userBuffer, eax      ;save the int
	popad								;restore saved registers
	pop ebp
	ret 8								;clean up stack
ReadVal ENDP


;*******************************************************************************
;WriteVal - converts a numeric value to a string of digits
;		  - invokes the displayString macro to produce the output
;*******************************************************************************
WriteVal PROC
	push ebp
	mov ebp, esp
	pushad								;save registers
	mov eax, [ebp+12]					;load int to turn into a string
	mov edi, [ebp+8]					;loading address for storing the string
	mov ebx, 10							;value to divide by for digit placement
	push 0								;set top of stack
S:
	mov edx, 0							;clear edx for division
	div ebx								;used for digit placement
	add edx, 48
	push edx							;push digit onto stack
	cmp eax, 0							;see if we've reached the end
	jne S
StackVal:
	pop [edi]							;pop string values
	mov eax, [edi]						;move values into eax
	inc edi								;advance edi
	cmp eax, 0							;check to see if finished
	jne StackVal						;repeat loop if not finished
Fin:
	mov edx, [ebp+8]					;move string to edx
	displayString OFFSET tempList		;print string of values
	call CRLF
	popad								;restore registers
	pop ebp
	ret 8								;clean up stack
WriteVal ENDP

END main
