	.file	"tsmutrix.c"
	.text
.globl TransposeSMatrix
	.type	TransposeSMatrix, @function
TransposeSMatrix:
.LFB2:
	pushq	%rbp
.LCFI0:
	movq	%rsp, %rbp
.LCFI1:
	movq	%rdi, -24(%rbp)
	movl	16(%rbp), %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	movl	16(%rbp), %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	movl	16(%rbp), %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	testl	%eax, %eax
	je	.L11
	movl	$1, -4(%rbp)
	jmp	.L4
.L5:
	movl	$1, -12(%rbp)
	jmp	.L6
.L7:
	movl	-12(%rbp), %eax
	movslq	%eax,%rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movl	20(%rax,%rbp), %eax
	cmpl	-4(%rbp), %eax
	jne	.L8
	movl	-8(%rbp), %ecx
	movl	-12(%rbp), %eax
	movslq	%eax,%rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movl	20(%rax,%rbp), %esi
	movq	-24(%rbp), %rdi
	movslq	%ecx,%rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movl	%esi, (%rax,%rdi)
	movl	-8(%rbp), %ecx
	movl	-12(%rbp), %eax
	movslq	%eax,%rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movl	16(%rax,%rbp), %esi
	movq	-24(%rbp), %rdi
	movslq	%ecx,%rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	addq	%rdi, %rax
	addq	$4, %rax
	movl	%esi, (%rax)
	movl	-8(%rbp), %ecx
	movl	-12(%rbp), %eax
	movslq	%eax,%rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movl	24(%rax,%rbp), %esi
	movq	-24(%rbp), %rdi
	movslq	%ecx,%rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	addq	%rdi, %rax
	addq	$8, %rax
	movl	%esi, (%rax)
	addl	$1, -8(%rbp)
.L8:
	addl	$1, -12(%rbp)
.L6:
	movl	16(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jg	.L7
	addl	$1, -4(%rbp)
.L4:
	movl	16(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jge	.L5
.L11:
	leave
	ret
.LFE2:
	.size	TransposeSMatrix, .-TransposeSMatrix
	.section	.rodata
.LC0:
	.string	"item: %d,%d,%d\n"
	.text
.globl show
	.type	show, @function
show:
.LFB3:
	pushq	%rbp
.LCFI2:
	movq	%rsp, %rbp
.LCFI3:
	subq	$32, %rsp
.LCFI4:
	movq	%rdi, -24(%rbp)
	movl	$1, -4(%rbp)
	jmp	.L13
.L14:
	movl	-4(%rbp), %eax
	movq	-24(%rbp), %rcx
	movslq	%eax,%rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	addq	%rcx, %rax
	addq	$8, %rax
	movl	(%rax), %r8d
	movl	-4(%rbp), %eax
	movq	-24(%rbp), %rcx
	movslq	%eax,%rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	addq	%rcx, %rax
	addq	$4, %rax
	movl	(%rax), %edi
	movl	-4(%rbp), %eax
	movq	-24(%rbp), %rcx
	movslq	%eax,%rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movl	(%rax,%rcx), %esi
	movl	%r8d, %ecx
	movl	%edi, %edx
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -4(%rbp)
.L13:
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	cmpl	-4(%rbp), %eax
	jge	.L14
	leave
	ret
.LFE3:
	.size	show, .-show
