; eatsyscall.asm
;author lijinya
;version: 1.0
;date 2014/7/4
;nasm -f elf -g -F stabs eatsyscall.sam
;describetion: a simple assembly program.
section .data	;include inittialized data
eatmsg: db "Eat at Joe's!",10
EatLen: equ $-eatmsg
section .bss
section .text
global _start

_start:
	nop
	mov eax,4	;specify the sys_write call
	mov ebx,1	;file describition systembol 1 standard output
	mov ecx,eatmsg	;convert show message offset address
	mov edx,EatLen	;
	int 80h			;system call , convert text to standard output
	mov eax,1		;exit system call
	mov ebx,0		;return value
	int 80h			;terminate the program

