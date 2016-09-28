#####################################
#	purpose show how the function work
#	this program will calculate 2^3+5^2
#
#	main program all data will store in the register
#	so the data section will be null
.section .data
.section .text
.globl _start
_start:
	pushl $3
	pushl $2
	call power
	addl $8,%esp				#the stack pointer move backword
	pushl %eax					#store the answer before call the next function

	pushl $2
	pushl $5
	call power
	addl $8,%esp
	popl %ebx

	addl %eax,%ebx

	movl $1,%eax				#exit command code			%ebx exit code
	int $0x80


#	calculate the power
#	the first argument base number
#	the second argument power
#	output:give as the   return value
#	notice:the power must larger than 1
#	variable:
#		%ebx store the base
#		%ecx,store the power
#		%eax tempory store

.type power,@function
power:
	pushl %ebp				#store the base address
	movl %esp,%ebp			#set the base address as stack base pointer
	subl $4,%esp			#for native store keep room
	movl 8(%ebp),%ebx		#push the first argument to %eax
	movl 12(%ebp),%ecx

	movl %ebx,-4(%ebp)		#store the current result

power_loop_start:
	cmpl $1,%ecx
	je end_power
	movl -4(%ebp),%eax		#move the current result to %eax
	imull %ebx,%eax		#store the current result
	movl %eax,-4(%ebp)

	decl %ecx
	jmp power_loop_start
	
end_power:
	movl -4(%ebp),%eax
	movl %ebp,%esp
	popl %ebp
	ret


