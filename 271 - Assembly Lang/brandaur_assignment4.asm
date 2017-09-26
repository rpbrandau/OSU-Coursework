TITLE Assignment4 - Composite Numbers     (brandaur_assignment4.asm)

; Author: Riley Brandau
; Course / Project ID  CS271-400               Date: 11/2/16 (due 11/6/16)
; Description: Asks user to enter a number in a range [1-400], program will
;               display composite numbers up to the specified number.

INCLUDE Irvine32.inc
; (insert constant definitions here)
MAX = 400     ;defining upper bound
MIN = 1       ;defining lower bound

.data
; (insert variable definitions here)
;intro variables
intro_1 BYTE "Composite Numbers",0
intro_2 BYTE "Programmed by: Riley Brandau",0

;outro variables
outro_1 BYTE "The problem of distingushing prime numbers",0
outro_2 BYTE "from composite numbers and of resolving the",0
outro_3 BYTE "latter into their prime factors is known to be",0
outro_4 BYTE "one of the most important and useful in arithmetic.",0
outro_5 BYTE " - Carl Friedrich Gauss",0
outro_6 BYTE "Bye!",0
;user prompt variables
userPrompt_1 BYTE "Please enter an integer in the range of 1 to 400 ",0
userPrompt_2 BYTE "And I will display all of the composites.",0

;data validation variables
errorPrompt BYTE "Integer outside of range.",0
userNum	DWORD ?  ;ends up serving as loop counter

;results variables
resultPrompt BYTE "Displaying list of composites up to ",0
padding BYTE "   ",0

;calculate variables
termCount DWORD 0 ;counter for the number of terms on a printed line
accumulator DWORD 1 ;variable to increase per loop


.code
main PROC
; (insert executable instructions here)
;1) Display Program & Programmer's Name (INTRO)
	call INTRO

;2) Get user's input (GetINFO) (calls VALIDATE)
;2.b) Validate user's input (VALIDATE)
	call GetINFO

;3) Display composite numbers (RESULTS) (calls CALCULATE)
;3.b) Calculate composites (CALCULATE)
	call RESULTS

;4) Display farewell (OUTRO)
	call OUTRO

	exit	; exit to operating system
main ENDP
; (insert additional procedures here)
;There are six procedures in this program:
;INTRO, GetInfo, VALIDATION, RESULTS, CALCULATE, and OUTRO

;This procedure displays the introduction information
INTRO PROC
	mov	edx, OFFSET intro_1
	call WriteString
	call CRLF
	mov	edx, OFFSET intro_2
	call WriteString
	call CRLF
	ret
INTRO ENDP

;This procedure displays the farewell information
OUTRO PROC
	mov edx, OFFSET outro_1
	call WriteString
	call CRLF
	mov edx, OFFSET outro_2
	call WriteString
	call CRLF
	mov edx, OFFSET outro_3
	call WriteString
	call CRLF
	mov edx, OFFSET outro_4
	call WriteString
	call CRLF
	mov edx, OFFSET outro_5
	call WriteString
	call CRLF
	call CRLF
	mov edx, OFFSET outro_6
	call WriteString
	call CRLF
	call CRLF
	ret
OUTRO ENDP

;Displays user prompt then calls VALIDATION to check user's entered number
GetINFO PROC
	mov edx, OFFSET userPrompt_1
	call WriteString
	call CRLF
	mov edx, OFFSET userPrompt_2
	call VALIDATION
	ret
GetINFO ENDP

;Reads the user's int and compares it to the upper and lower bounds.
;Issues an error if out of bounds.
VALIDATION PROC
	jmp INPUT
ERROR:
	mov edx, OFFSET errorPrompt
	call WriteString
	call CRLF
	mov edx, OFFSET userPrompt_1
	call WriteString
INPUT:
	call ReadInt
	mov userNum, eax
	cmp userNum, MIN
	jl ERROR
	cmp userNum, MAX
	jg ERROR
	ret
VALIDATION ENDP

;Displays the result prompt then calls the Calculate procedure
RESULTS PROC
	mov edx, OFFSET resultPrompt
	call WriteString
	mov eax, userNum
	call WriteDec
	call CRLF
	call CRLF
	call CALCULATE
	ret
RESULTS ENDP

;this calculates all of the composite numbers by first comparing the accumulator,
;which increases by 1 each loop, to known primes up to 20 (20*20 = 400)
;If it is a known prime, it skips the division steps. If it is not a known prime,
;the acumulator is divided by known primes. If the remainder = 0, it is composite.
;I'm sure there is a more elegant way to write this procedure...
CALCULATE PROC
	mov ecx, userNum  ;loads loop counter.
Start:
Prime:
	mov eax, accumulator
	cmp eax, 2
	je	Finish
	cmp eax, 3
	je	Finish
	cmp	eax, 5
	je	Finish
	cmp	eax, 7
	je	Finish
	cmp eax, 11
	je	Finish
	cmp eax, 13
	je	Finish
	cmp	eax, 17
	je	Finish
P2:
	mov eax, accumulator
	mov edx, 0
	mov ebx, 2
	div ebx
	cmp edx, 0
	je	Output
P3:
	mov eax, accumulator
	mov edx, 0
	mov ebx, 3
	div ebx
	cmp edx, 0
	je	Output
P5:
	mov eax, accumulator
	mov edx, 0
	mov ebx, 5
	div ebx
	cmp edx, 0
	je	Output
P7:
	mov eax, accumulator
	mov edx, 0
	mov ebx, 7
	div ebx
	cmp edx, 0
	je	Output
P11:
	mov eax, accumulator
	mov edx, 0
	mov ebx, 11
	div ebx
	cmp edx, 0
	je	Output
	jmp P13
Halfway:
	jmp Start
P13:
	mov eax, accumulator
	mov edx, 0
	mov ebx, 13
	div ebx
	cmp edx, 0
	je Output
P17:
	mov eax, accumulator
	mov edx, 0
	mov ebx, 17
	div ebx
	cmp edx, 0
	je	Output
	jmp	Finish

Output:
	mov eax, accumulator
	call WriteDec
	mov	edx, OFFSET padding
	call WriteString
	inc termCount
	cmp termCount, 10
	je LineBreak
	jmp Finish

LineBreak:
	call CRLF
	mov termCount, 0

Finish:
	inc accumulator
	;11/6/16 - After looking at the rubric, I see that using Loop is required.
	;I implemented it, but needed to have it loop to a label "halfway"
	;as the distance to start was too great. I commented out my make-shift
	;loop.
	loop Halfway
	;11/2/16 - I started out using the "loop call", but the distance is too far
	;so I created my own loop by decrimenting ecx, comparing it to 0
	;and if it was greater than 0, jumping to the start.
	;I've also read that LOOP is slower? 
	;dec ecx
	;cmp ecx, 0
	;jg	Start
	call CRLF
	call CRLF
	ret
CALCULATE ENDP


END main
