;
;uppercase1.asm
;
section .bss
	Buff resb 1
section .data

section .text
	global _start
_start:
	nop
Read:
	mov eax,3	;sys_read call
	mov ebx,0	;input file
	mov ecx,Buff
	mov edx,1
	int 80h
	cmp eax,0	;watch return value in sys_read
	je Exit		;EOF goto exit

	cmp byte [Buff],61h	;cmp to a
	jb Write			;less than a
	cmp byte [Buff],7Ah	;cmp to z
	ja Write	;more than z
	sub byte [Buff],20h

	Write:
		mov eax,4
		mov ebx,1
		mov ecx,Buff
		mov edx,1
		int 80h		;sys_write call
		jmp Read	;continue
	Exit:
		mov eax,1	;sys_exit call
		mov ebx,0	;return value
		int 80h
