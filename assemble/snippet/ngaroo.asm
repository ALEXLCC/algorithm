;
;  A---->a
;
section .data
	Snippet db "KANGAROO"
section .text
global _start
	_start:
		nop
		;all instructions will be put into blew
		mov ax,-42
		movsx ebx,ax
		mov eax,447
		mov ebx,1739
		mul ebx
		mov ebx,Snippet
		mov eax,8
	DoMore:	add byte [ebx],32
		dec eax
		inc ebx
		jnz DoMore
		;
		nop
	mov eax,4
	mov ebx,1
	mov ecx,Snippet
	mov edx,8
	int 80H
	mov eax,1
	mov ebx,0
	int 80H


