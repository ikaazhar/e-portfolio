TITLE lab2
; Author: Group 1
; Date: 18 May 2024


include irvine32.inc

.data

.code
main proc
; Code Snippet 2 (DIV  BL)
	MOV DX, 0; Clear DX to form the 16 - bit dividend in DX : AX
	MOV AX, 803h; Load the dividend(8003h) into AX
	MOV BX, 10h; Load the divisor(10h) into BX
	DIV BX; Divide DX : AX by BX, whereby AX = quotient & DX = remainder
	call DumpRegs
	exit
main endp
END main