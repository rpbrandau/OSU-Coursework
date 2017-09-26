TITLE Assignment5 - Random Numbers    (brandaur_assignment5.asm)

; Author: Riley Brandau
; Course / Project ID  CS271-400               Date: 11/21/16 (due 11/20/16, but used 2 grace days)
; Description: Asks user to enter a number in a range [10-200], program will
;              generate that many random numbers, sort them in descending order
;			   and calculate the median.

INCLUDE Irvine32.inc
; (insert constant definitions here)
MAX = 200     ;defining upper bound for input
MIN = 10	  ;defining lower bound for input
LO = 100	  ;defining lower bound for rand numbers
HI = 1000     ;defining upper bound for rand numbers. 1 more than max since randomrange takes n-1 for upper bound.

.data
; (insert variable definitions here)
;intro variables - used in INTRO PROC
intro_1 BYTE "Sorting Random Numbers",0
intro_2 BYTE "Programmed by: Riley Brandau",0

;program description variables - used in INTRO PROC
desc_1 BYTE "This program generates random numbers in the range [100 to 999].",0
desc_2 BYTE "It will then display the original list, sort the list, ",0
desc_3 BYTE "calculate the median value, and display the list in descending order.",0

;outro variables - used in OUTRO PROC
outro_1 BYTE "Terminating program.",0
outro_2 BYTE "Bye!",0

;user prompt variables - used in GETINFO PROC
userPrompt_1 BYTE "How many numbers do you want generated? [10 to 200]: ",0


;data validation variables - used in GETINFO PROC
errorPrompt BYTE "Integer outside of range.",0
userNum	DWORD ?  ;ends up serving as loop counter/#of elements in array

;results variables - used in MAIN PROC
resultPrompt_1 BYTE "Displaying unsorted random numbers: ",0
resultPrompt_2 BYTE "Median value: ",0
resultPrompt_3 BYTE "Displaying sorted list of random numbers: ",0
padding BYTE "   ",0

;calculate variables - USED IN RANDNUMS, DISPLAYLIST, DISPLAYMEDIAN, SORTLIST
list DWORD MAX DUP(?) ;create an array based on what user enters
termCount DWORD 0     ;counter for the number of terms on a printed line


.code
main PROC
; (insert executable instructions here)
;1) Display Program Name, Programmer's Name, and Program Description (INTRO)
	call Randomize ;seeding the random number generator
	call INTRO

;2) Get user's input (GetINFO) (calls VALIDATE)
;2.b) Validate user's input (VALIDATE)
	call GetINFO

;3) Generate random numbers & Fill array
;3.b) Display Unsorted array 
	push OFFSET list         ;passing list to RANDNUMS
	push userNum             ;passing userNum to RANDNUMS
	call RANDNUMS

	mov edx, OFFSET resultPrompt_1
	call WriteString
	call CRLF
	push OFFSET padding      ;passing padding to DISPLAYLIST
	push OFFSET list		 ;passing list to DISPLAYLIST
	push userNum             ;passing userNum to DISPLAYLIST
	call DISPLAYLIST
	call CRLF

;4) Sort the list
	push OFFSET list		 ;passing list to SORTLIST
	push userNum             ;passing userNum to SORTLIST
	call SORTLIST
;4.b) Calculate median
;4.c) Display median
	mov edx, OFFSET resultPrompt_2
	call WriteString
	push OFFSET list
	push userNum
	call DISPLAYMEDIAN
	call CRLF
	call CRLF
;4.d) Display sorted list
	mov edx, OFFSET resultPrompt_3
	call WriteString
	call CRLF
	push OFFSET padding		 ;passing padding to DISPLAYLIST
	push OFFSET list		 ;passing list to DISPLAYLIST
	push userNum			 ;passing userNum to DISPLAYLIST
	call DISPLAYLIST
	call CRLF
;5) Display farewell (OUTRO)
	call OUTRO

	exit	; exit to operating system
main ENDP
; (insert additional procedures here)
;There are eight procedures in this program:
;INTRO, GETINFO, VALIDATION, RANDNUMS, DISPLAYLIST, DISPLAYMEDIAN, SORTLIST, and OUTRO

;-------------------------------------------------------------------------------------
;INTRO PROC
;Displays all of the introductory information: Program Name, Programmer, Description
;Receives: nothing
;Returns: nothing
;-------------------------------------------------------------------------------------
INTRO PROC
	mov	edx, OFFSET intro_1
	call WriteString
	call CRLF
	mov	edx, OFFSET intro_2
	call WriteString
	call CRLF
	call CRLF
	mov edx, OFFSET desc_1
	call WriteString
	call CRLF
	mov edx, OFFSET desc_2
	call WriteString
	call CRLF
	mov edx, OFFSET desc_3
	call WriteString
	call CRLF
	call CRLF
	ret
INTRO ENDP


;-------------------------------------------------------------------------------------
;OUTRO PROC
;Displays all of the parting information: Program Termination & goodbye
;Receives: nothing
;Returns: nothing
;-------------------------------------------------------------------------------------
OUTRO PROC
	mov edx, OFFSET outro_1
	call WriteString
	call CRLF
	mov edx, OFFSET outro_2
	call WriteString
	call CRLF
	call CRLF
	ret
OUTRO ENDP


;-------------------------------------------------------------------------------------
;GETINFO PROC
;Prompts the user for input, then calls VALIDATION to check that the number entered
; is valid.
;Receives: nothing
;Returns: nothing
;-------------------------------------------------------------------------------------
GETINFO PROC
	mov edx, OFFSET userPrompt_1
	call WriteString
	call VALIDATION
	call CRLF
	ret
GETINFO ENDP


;-------------------------------------------------------------------------------------
;VALIDATION PROC
;Validates the user's input by comparing it to MIN & MAX constants.
;If outside of range, asks user to input another value.
;Receives: nothing
;Returns: nothing
;-------------------------------------------------------------------------------------
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

;-------------------------------------------------------------------------------------
;RANDNUMS PROC
;Generates random numbers then fills an array with them.
;Receives: [ebp+8] - userNum (loop count)
;          [ebp+12] - offset of list (array)
;
;Returns: array filled with numbers
;-------------------------------------------------------------------------------------
RANDNUMS PROC
	push ebp
	mov	 ebp, esp
	pushad
	mov esi, [ebp+12] ;move list's offset into EBP
	mov ecx, [ebp+8]  ;move userNum (loop count) into ecx
	mov eax, 0
Fill:
	mov eax, HI       ;load eax w/ upper bound for random range
	call RandomRange  ;should create a random number between 0 & 999
	mov ebx, eax	  ;mov the random number into the randNum variable
	cmp ebx, LO  	  ;if rand num is < 100, add LO, otherwise continue
	jl LTLO
	jmp Cont
LTLO: 
	add ebx, LO
Cont:
	mov [esi], ebx      ;store the random number in the array
	add esi, TYPE DWORD ;adding 2 bytes to progress to next array element
	loop Fill
Fin:
	popad
	pop ebp
	ret 12
RANDNUMS ENDP

;-------------------------------------------------------------------------------------
;DISPLAYLIST PROC
;Loops through array and writes it to the screen
;Receives: [ebp+8] - loop counter (userNum variable)
;          [ebp+12] - Offset of list (array)
;          [ebp+16] - Offset of padding (used for spaces)
;Returns: nothing
;-------------------------------------------------------------------------------------
DISPLAYLIST PROC
	push ebp
	mov ebp, esp
	pushad
	mov ebx, 0		   ;using ebx to keep track of terms
	mov edx, [ebp+16]  ;padding
	mov esi, [ebp+12]  ;array offset of list
	mov ecx, [ebp+8]   ;loop counter (userNum)
Disp:
	mov eax, [esi]     ;move array value into eax
	call WriteDec      ;write the value
	add ebx, 1		   ;increase term count by 1
	call WriteString   ;add padding
	cmp ebx, 10        ;compare term count to 10
	jl Cont			   ;if less than 10, continue printing terms on same line
	call CRLF		   ;otherwise make a new line
	mov ebx, 0         ;and reset term count to 0
Cont:
	add esi, TYPE DWORD ;point to next element in array
	loop Disp
Fin:
	call CRLF
	popad			   ;restore registers
	pop ebp            
	ret 12			   ;clean up the stack
DISPLAYLIST ENDP



;-------------------------------------------------------------------------------------
;SORTLIST PROC
;Sorts the list in descending order (High to Low)
;Receives: [ebp+8] - loop counter (userNum variable)
;          [ebp+12] - Offset of list (array variable)
;Note: Had help from example in book on pg 375
;Returns: sorted array
;-------------------------------------------------------------------------------------
SORTLIST PROC
	push ebp
	mov ebp, esp
	pushad
	mov ecx, [ebp+8]  ;loop counter (userNum)
	dec ecx 		  ;array elements - 1
Outer:
	push ecx		  ;store outer loop counter
	mov esi, [ebp+12] ;load offset of list
Inner:
	mov eax, [esi]        ;load first value into eax
	cmp [esi+4], eax      ;compare next values
	jl Cont               
	xchg eax, [esi+4]     ;if val1 < val2, swap
	mov [esi], eax
Cont:
	add esi, TYPE DWORD ;advance to next value
	loop Inner
	
	pop ecx             ;restore outer loop count
	loop Outer          ;continue with outer loop
	
	popad
	pop ebp
	ret 8
SORTLIST ENDP

;-------------------------------------------------------------------------------------
;DISPLAYMEDIAN PROC
;Calculates and displays the median value of the sorted array
;Receives: [ebp+8] - length of array (userNum variable)
;          [ebp+12] - Offset of list (array variable)
;Returns: nothing
;-------------------------------------------------------------------------------------
DISPLAYMEDIAN PROC
	push ebp
	mov ebp, esp
	pushad
	mov esi, [ebp+12] ;array offset of list
	mov eax, [ebp+8]  ;length of array
	mov edx, 0        ;clear edx for division
	mov ecx, 2        ;load 2 into ecx
	div ecx			  ;determining if odd or even
	cmp edx, 0        ;if edx has a remainder, array length was odd
	jz  E
O:                    ;ODD label
	mov eax, [ebp+8]  ;reload array length
	dec eax			  ;n-1 for array access
	mov ecx, 2        ;load 2 for division
	mov edx, 0        ;clear edx for division
	div ecx			  ;eax contains array index of median
	mov ecx, 4        ;4 represents 4 bytes for address calculation
	mul ecx           ;multiply by DWORD to get the address
	mov eax, [esi+eax] ;eax should contain the address
	call WriteDec	  ;display the median value
	call CRLF
	jmp Fin
E:                    ;EVEN label
	mov eax, [ebp+8]  ;load eax w/ array index
	mov ecx, 2        ;load 2 for division
	mov edx, 0        ;clear edx for division
	div ecx			  ;eax contains n/2 index now
	mov ecx, 4        ;4 represents 4 bytes for address calculation
	mul ecx           ;get the address of n/2 index           
	mov ebx, eax      ;ebx contains n/2 address
	mov eax, [ebp+8]  ;reload eax w/ array length
	dec eax           ;setting eax up for (n-1)/2 index
	mov ecx, 2        ;load 2 for division
	mov edx, 0        ;clear edx for division
	div ecx           ;eax contains (n-1)/2 index now
	mov ecx, 4        ;4 represents 4 bytes for address calculation
	mul ecx           ;eax contains (n-1)/2 address
	mov eax, [esi+eax] ;eax contains (n-1)/2 index array value
	mov ebx, [esi+ebx] ;ebx contains (n/2) index array value
	add eax, ebx	  ;add values (n-1)/2 and (n/2) values together
	mov ecx, 2        ;load 2 for division
	mov edx, 0        ;clear edx for division
	div ecx
	call WriteDec     ;eax has the median value ((n-1)/2)+(n/2))/2
	call CRLF
Fin:
	popad
	pop ebp
	ret 8
DISPLAYMEDIAN ENDP


END main
