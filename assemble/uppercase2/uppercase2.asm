;
;uppercase1.asm
;
section .bss
	BUFFERLEN equ 1024
	Buff resb BUFFERLEN
section .data

section .text
	global _start
_start:
	nop
Read:
	mov eax,3	;sys_read call
	mov ebx,0	;input file
	mov ecx,Buff
	mov edx,BUFFERLEN
	int 80h
	mov esi,eax	;save return value
	cmp eax,0	;watch return value in sys_read
	je Exit		;EOF goto exit

	mov ecx,esi
	mov ebp,Buff
	dec ebp

	Scan:
	cmp byte [ebp+ecx],61h	;cmp to a
	jb Next			;less than a
	cmp byte [ebp+ecx],7Ah	;cmp to z
	ja Next	;more than z
	sub byte [ebp+ecx],20h
	
	Next:
		dec ecx
		jnz Scan

	Write:
		mov eax,4
		mov ebx,1
		mov ecx,Buff
		mov edx,esi
		int 80h		;sys_write call
		jmp Read	;continue
	Exit:
		mov eax,1	;sys_exit call
		mov ebx,0	;return value
		int 80h
