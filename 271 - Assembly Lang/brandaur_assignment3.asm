TITLE Assignment #3     (brandaur_assignment3.asm)

; Author: Riley Brandau
; Course / Project ID: 271-400                 Date: 10/26/16 (Due: 10/30/16)
; Description: Get's user input (name, integers), displays number of negative numbers entered, their sum, and average
; **EC DESCRIPTION**: Kept track of, and displayed the line number for user input

INCLUDE Irvine32.inc
; (insert constant definitions here)
minNum = -100   ;defining lower bound
maxNum = -1     ;defining upper bound

.data
; (insert variable definitions here)
userName BYTE 33 DUP(0)
userNum DWORD ?
sum	DWORD 0
count DWORD 0
avg	DWORD 0
lineCount DWORD 0    ;*extra credit variable*

intro_1 BYTE "Integer Accumulator",0
intro_2 BYTE "Programmed by: Riley Brandau",0

name_prompt BYTE "What is your name? ",0
greeting BYTE "How do you do, ",0
greeting_2 BYTE "?",0

user_prompt1 BYTE "Please enter integers in the range of -100 to -1.",0
user_prompt2 BYTE "To exit and see results: enter a non-negative integer.",0
enter_prompt BYTE "Enter Number: ",0
enter_prompt2 BYTE "Line #",0
enter_prompt3 BYTE ":",0

result_special BYTE "No negative integers were entered!",0
result_count BYTE "Number of valid integers entered: ",0
result_sum BYTE "The sum of your valid integers is: ",0
result_avg BYTE "The rounded average of your valid integers is: ",0

farewell_1 BYTE "Thank you for using my humble Integer Accumulator.",0
farewell_2 BYTE "So long, and thanks for all the fish, ",0
farewell_3 BYTE "!",0

ecPrompt BYTE "Extra Credit: Line Count",0

.code
main PROC
; (insert executable instructions here)
;1) Display program title
	mov edx, OFFSET intro_1
	call WriteString
	call CRLF
;1b) Display programmer's name
	mov edx, OFFSET intro_2
	call WriteString
	call CRLF
;1c) Display extra credit prompts
	mov edx, OFFSET ecPrompt
	call WriteString
	call CRLF
	call CRLF
;2) Prompt user for name
	mov edx, OFFSET name_prompt
	call WriteString
	mov edx, OFFSET userName
	mov ecx, 32
	call ReadString
;2b) Greet user using their name
	mov edx, OFFSET greeting
	call WriteString
	mov edx, OFFSET username
	call WriteString
	mov edx, OFFSET greeting_2
	call WriteString
	call CRLF
	call CRLF
;3) Display instructions
	mov edx, OFFSET user_prompt1
	call WriteString
	call CRLF
	mov edx, OFFSET user_prompt2
	call WriteString
	call CRLF
	call CRLF
	jmp Input
;4) Loop when values entered are between -100 & -1 (inclusive)
InputErr:
	mov edx, OFFSET user_prompt1
	call Writestring
	dec lineCount                  ;*extra credit* need to reduce lineCount if error occurs
	call CRLF
	call CRLF
Input:
	inc lineCount                  ;*extra credit* increase lineCount per loop 
	mov eax, lineCount
	mov edx, OFFSET enter_prompt2
	call WriteString
	call WriteDec                  ;*extra credit* display line number
	mov edx, OFFSET enter_prompt3  ;*extra credit* display line number
	call WriteString               ;*extra credit* display line number
	mov edx, OFFSET enter_prompt
	call WriteString
	call ReadInt
	mov userNum, eax
	cmp userNum, minNum            ;compare entered number to -100
	jl  InputErr                   ;if number is <-100, jump to start
	cmp userNum, maxNum            ;compare entered number to -1
	jg  Calculate                  ;if number is >-1 (ie positive), jump to calculations 
	mov eax, 0                     ;zero out eax
	mov eax, userNum               ;put userNum in eax
	add eax, sum                   ;add running total to eax
	mov sum, eax                   ;store new running total in sum
	inc count
	jmp Input
;5) Calculate the average of numbers entered
Calculate:    
	cmp count, 0                   ;compare eax to 0 to see if any neg integers were entered
	je  Special			           ;jump to Special case if no neg integers were entered
	mov edx, 0                     ;need to clear edx to make room for division
	mov eax, sum
	cdq                            ;sign extending into EDX
	mov ebx, count       
	idiv ebx                       ;divide the sum by the count. idiv because of signed integers
	mov avg, eax                   ;store result in avg
	
;6) Display number of negative numbers entered (if applicable)
	call CRLF
	mov edx, OFFSET result_count
	call Writestring
	mov eax, count
	call WriteDec
	call CRLF
	jmp Display
;6a) if no negative numbers were entered, display a special message
Special:	
	mov edx, OFFSET result_special
	call WriteString
	call CRLF
	jmp Farewell
;6b) Display sum of negative numberes entered
Display:
	mov edx, OFFSET result_sum
	call WriteString
	mov eax, sum
	call WriteInt
	call CRLF
;6c) Display the average, rounding to nearest integer (-20.5 -> -20)
	mov edx, OFFSET result_avg
	call WriteString
	mov eax, avg
	call WriteInt
	Call CRLF
	Call CRLF
;6d) Display a parting message, with user's name, end program
Farewell:
	mov edx, OFFSET farewell_1
	call WriteString
	call CRLF
	mov edx, OFFSET farewell_2
	call WriteString
	mov edx, OFFSET userName
	call WriteString
	mov edx, OFFSET farewell_3
	call WriteString
	call CRLF
	call CRLF

	exit	; exit to operating system
main ENDP
; (insert additional procedures here)

END main
