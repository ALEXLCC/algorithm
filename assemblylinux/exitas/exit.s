#just exit
#input no
#output no
#variable :
#	%eax save system call code
#	%ebx save return status
.section .data
#any instruction start with dot(.) will not be translated to machine instruction.
.section .text
.global _start
_start:
	movl $1,%eax
	movl $0,%ebx
int $0x80

