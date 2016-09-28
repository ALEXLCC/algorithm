#sizetest3.s A simple program  to view the executable size
.section .text
.section .data
	.fill 10000
.globl _start
_start:
	movl $1,%eax
	movl $0,%ebx
int $0x80
