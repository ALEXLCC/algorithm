#cpuid.s	processor Vendor ID
.section .data
output:
	.ascii "the processor Vendor ID is 'xxxxxxxxxxxx'\n"
.section .text
.globl _start
_start:
	movl $0,%eax
	cpuid
movl $output,%edi
movl %ebx,28(%edi)
movl %edx,32(%edi)
movl %ecx,36(%edi)
movl $4,%eax	# system call 4  print
# eax system call value
# ebx file describe symbol
# ecx string head
# edx string length
movl $1,%ebx
movl $output,%ecx
movl $42,%edx
int $0x80
movl $1,%eax	# system call 1  exit
movl $0,%ebx
int $0x80
