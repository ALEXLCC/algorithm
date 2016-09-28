#destinate find the maximum number in a series of data\
#
#	%edi  save the current data index
#	%ebx the current maximum
#	%eax current data
#	data_items include data,end by zero(0)
#
.section .data
data_items:
	.long 3,67,34,222,45,75,54,34,44,33,22,11,66,0
.section .text
_start:
	movl $0,%edi						#mov 0 to index register
	movl data_items(,%edi,4), %eax  	#load the first section of the data
	movl %eax,%ebx						#the first as the maximum

	start_loop:
		cmpl $0,%eax
		je   loop_exit
		incl %edi						#load the next one
		movl data_items(,%edi,4), %eax	#
		cmpl %ebx,%eax					#compare
		jle	start_loop
		movl %eax,%ebx
		jmp start_loop
	loop_exit:
	#%ebx store the exit code ,already store the maximum
		movl $1,%eax
		int $0x80
