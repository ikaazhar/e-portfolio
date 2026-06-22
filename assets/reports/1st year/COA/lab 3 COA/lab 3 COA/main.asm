; TITLE lab1
; Author: Group 1
; Date: 10 April 2023

include Irvine32.inc

.data
menu BYTE "Welcome to Simple Math Activities: ", 0dh, 0ah, 0
menu1 BYTE "Main menu : ", 0dh, 0ah, 0
menu2 BYTE "1. To calculate Perimeter Hexagon (Loop and ADD instructions)", 0dh, 0ah, 0
menu3 BYTE "2. To calculate SUM (unsign int) index [Odd or Even] in an Array Hello[6] ", 0dh, 0ah, 0
menuOp BYTE "Select Your Input :", 0
stryn BYTE "Press 'y' to Main Menu or 'n' to Exit the benchmark: ", 0
charIn BYTE ?
charY db 'y'
op1 dword 1
op2 dword 2
strbye BYTE "Thank you ... BYE!!", 0dh, 0ah, 0

message1 BYTE "Calculate SUM (unsign int) index (Odd or Even) in array Hello[6]", 0dh, 0ah, 0dh, 0ah, 0
message2 BYTE "Integer input: ", 0
message3 BYTE "Result Sum Hello[index]: ", 0
message4 BYTE "Sum Hello[even] index location: ", 0
message5 BYTE "Sum Hello[odd] index location: ", 0
promptBad BYTE "Invalid input, please enter again", 0
Hello dword 6 dup(0)
sum_even dword 0
sum_odd dword 0

sideHex1 DWORD ?
sideHex2 DWORD ?
Perimeter_hexagon1 DWORD ?
Perimeter_hexagon2 DWORD ?
TotalPerimeter DWORD ?
title1 BYTE "Calculate Perimeter 2-Hexagon (LOOP and ADD instructions): ", 0
prompt1 BYTE "Input Hexagon 1 (side length): ", 0
prompt2 BYTE "Input Hexagon 2 (side length): ", 0
perimeter BYTE "Result of Perimeter Hexagon 1 and 2: ", 0
result_str BYTE "Total Perimeter Hexagon 1 and 2: ", 0


.code

	main proc

startProg :
	call Clrscr
	mov edx, offset menu
	call WriteString
	mov edx, offset menu1
	call WriteString
	mov edx, offset menu2
	call WriteString
	mov edx, offset menu3
	call WriteString
	mov edx, offset menuOp
	call WriteString
	call ReadDec
	CMP eax, 1
	JE periHex_loopAdd
	CMP eax, 2
	JE calSum_oddeven
	
periHex_loopAdd:
		mov edx, OFFSET title1
		call WriteString
		call Crlf
		call Crlf
		mov edx, OFFSET prompt1
		call WriteString
		call ReadDec
		jnc input1
		input1 :
		mov sideHex1, eax

		mov ecx, 5
		L1 :
		add eax, sideHex1
		loop L1
		mov Perimeter_hexagon1, eax


		mov edx, OFFSET prompt2
		call WriteString
		call ReadDec
		jnc input2
		input2 :
		mov sideHex2, eax


		mov ecx, 5
		L2 :
		add eax, sideHex2
		loop L2
		mov Perimeter_hexagon2, eax


		call Crlf
		mov edx, OFFSET perimeter
		call WriteString
		call Crlf
		mov eax, Perimeter_hexagon1
		call WriteDec
		call Crlf
		mov eax, Perimeter_hexagon2
		call WriteDec
		call Crlf

		mov eax, Perimeter_hexagon1
		add eax, Perimeter_hexagon2
		mov TotalPerimeter, eax

		call Crlf
		mov edx, OFFSET result_str
		call WriteString
		mov eax, TotalPerimeter
		call WriteDec
		call Crlf
		JMP RedoMenu

calSum_oddeven:
		mov edx, offset message1
		call WriteString
		call crlf
		call crlf
		; read input Age Students
		mov ECX, 6
		mov EBX, 0
		loop_Number:
			mov edx, offset message2
			call WriteString
			call ReadDec
			jnc goodInOption
			mov edx, OFFSET promptBad
			call WriteString
			jmp loop_Number; go input again
			goodInOption :
				mov Hello[EBX], eax; store good value
				add EBX, 4
				loop loop_Number
			; to add array
			mov ECX, 3
			mov EBX, 0
			mov eax, 0
		loopAdd:
			mov eax, Hello[EBX]
			add sum_even, eax; store result even
			add EBX, 4
			mov eax, Hello[EBX]
			add sum_odd, eax
			add EBX, 4
			loop loopAdd
		; display result
		call crlf
		mov edx, offset message3
		call WriteString
		call crlf
		mov edx, offset message4
		call WriteString
		mov eax, sum_even
		call WriteDec
		call crlf
		mov edx, offset message5
		call WriteString
		mov eax, sum_odd
		call WriteDec
		call crlf

 RedoMenu:
		; ask either to continue ('y') or Exit program('n')
		mov edx, OFFSET stryn
		call WriteString
		call ReadChar
		mov charIn, AL
		call WriteChar
		call Crlf
		call Crlf
		mov BL, charY
		cmp BL, charIn
		JE startProg

		mov edx, OFFSET strbye
		call WriteString

exit

main ENDP

END main
