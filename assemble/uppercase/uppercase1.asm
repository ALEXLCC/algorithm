;uppercase.asm
;read sys_read 3

section .bss
	Buff resb 1

section .data

section .text
	global _start
_start:
	nop
Read:
	mov eax,3	;sys_read call
	mov ebx,0	;device describe 0 :standard input
	mov ecx,Buff	;buffer address to be read data
	mov edx,1		;read a data from the buffer
	int 80h
	cmp eax,0		;sys_read return value in eax
	je Exit			;0 means EOF jump to Exit

	cmp byte [Buff],61h	;compare to 'a'
	jb Write		;if less than 'a' ,not lower case
	cmp byte [Buff],7Ah	;compare to 'z'
	ja Write
	sub byte [Buff],20h

Write:
	mov eax,4	;sys_write call
	mov ebx,1	;specify the device 1: standard output
	mov ecx,Buff	;the addrss to write to
	mov edx,1	;the count to write
	int 80h		;call sys_write
	jmp Read	;return to loop

Exit:
	mov eax,1	;exit code
	mov ebx,0	;return value
	int 80h

