	.file	"inline.cc"
	.section	.ctors,"aw",@progbits
	.align 8
	.quad	_GLOBAL__I_main
	.section	.text._Z3maxii,"axG",@progbits,_Z3maxii,comdat
	.align 2
	.weak	_Z3maxii
	.type	_Z3maxii, @function
_Z3maxii:
.LFB1404:
	pushq	%rbp
.LCFI0:
	movq	%rsp, %rbp
.LCFI1:
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jge	.L2
	movl	-4(%rbp), %eax
	movl	%eax, -12(%rbp)
	jmp	.L4
.L2:
	movl	-8(%rbp), %eax
	movl	%eax, -12(%rbp)
.L4:
	movl	-12(%rbp), %eax
	leave
	ret
.LFE1404:
	.size	_Z3maxii, .-_Z3maxii
.globl __gxx_personality_v0
	.text
	.align 2
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1413:
	pushq	%rbp
.LCFI2:
	movq	%rsp, %rbp
.LCFI3:
	subq	$16, %rsp
.LCFI4:
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L10
	cmpl	$65535, -8(%rbp)
	jne	.L10
	movl	$_ZSt8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$0, %esi
	movl	$__tcf_0, %edi
	call	__cxa_atexit
.L10:
	leave
	ret
.LFE1413:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.align 2
	.type	_GLOBAL__I_main, @function
_GLOBAL__I_main:
.LFB1415:
	pushq	%rbp
.LCFI5:
	movq	%rsp, %rbp
.LCFI6:
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	leave
	ret
.LFE1415:
	.size	_GLOBAL__I_main, .-_GLOBAL__I_main
	.align 2
	.type	__tcf_0, @function
__tcf_0:
.LFB1414:
	pushq	%rbp
.LCFI7:
	movq	%rsp, %rbp
.LCFI8:
	subq	$16, %rsp
.LCFI9:
	movq	%rdi, -8(%rbp)
	movl	$_ZSt8__ioinit, %edi
	call	_ZNSt8ios_base4InitD1Ev
	leave
	ret
.LFE1414:
	.size	__tcf_0, .-__tcf_0
	.section	.rodata
.LC0:
	.string	"max:"
	.text
	.align 2
.globl main
	.type	main, @function
main:
.LFB1405:
	pushq	%rbp
.LCFI10:
	movq	%rsp, %rbp
.LCFI11:
	pushq	%rbx
.LCFI12:
	subq	$24, %rsp
.LCFI13:
	movl	$9, -16(%rbp)
	movl	$10, -12(%rbp)
	movl	-12(%rbp), %esi
	movl	-16(%rbp), %edi
	call	_Z3maxii
	movl	%eax, %ebx
	movl	$.LC0, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rdi
	movl	%ebx, %esi
	call	_ZNSolsEi
	movq	%rax, %rdi
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	call	_ZNSolsEPFRSoS_E
	movl	$0, %eax
	addq	$24, %rsp
	popq	%rbx
	leave
	ret
.LFE1405:
	.size	main, .-main
	.local	_ZSt8__ioinit
	.comm	_ZSt8__ioinit,1,1
	.weakref	_Z20__gthrw_pthread_oncePiPFvvE,pthread_once
	.weakref	_Z27__gthrw_pthread_getspecificj,pthread_getspecific
	.weakref	_Z27__gthrw_pthread_setspecificjPKv,pthread_setspecific
	.weakref	_Z22__gthrw_pthread_createPmPK14pthread_attr_tPFPvS3_ES3_,pthread_create
	.weakref	_Z22__gthrw_pthread_cancelm,pthread_cancel
	.weakref	_Z26__gthrw_pthread_mutex_lockP15pthread_mutex_t,pthread_mutex_lock
	.weakref	_Z29__gthrw_pthread_mutex_trylockP15pthread_mutex_t,pthread_mutex_trylock
	.weakref	_Z28__gthrw_pthread_mutex_unlockP15pthread_mutex_t,pthread_mutex_unlock
	.weakref	_Z26__gthrw_pthread_mutex_initP15pthread_mutex_tPK19pthread_mutexattr_t,pthread_mutex_init
	.weakref	_Z30__gthrw_pthread_cond_broadcastP14pthread_cond_t,pthread_cond_broadcast
	.weakref	_Z25__gthrw_pthread_cond_waitP14pthread_cond_tP15pthread_mutex_t,pthread_cond_wait
	.weakref	_Z26__gthrw_pthread_key_createPjPFvPvE,pthread_key_create
	.weakref	_Z26__gthrw_pthread_key_deletej,pthread_key_delete
	.weakref	_Z30__gthrw_pthread_mutexattr_initP19pthread_mutexattr_t,pthread_mutexattr_init
	.weakref	_Z33__gthrw_pthread_mutexattr_settypeP19pthread_mutexattr_ti,pthread_mutexattr_settype
	.weakref	_Z33__gthrw_pthread_mutexattr_destroyP19pthread_mutexattr_t,pthread_mutexattr_destroy
	.section	.eh_frame,"a",@progbits
.Lframe1:
	.long	.LECIE1-.LSCIE1
.LSCIE1:
	.long	0x0
	.byte	0x1
	.string	"zPR"
	.uleb128 0x1
	.sleb128 -8
	.byte	0x10
	.uleb128 0x6
	.byte	0x3
	.long	__gxx_personality_v0
	.byte	0x3
	.byte	0xc
	.uleb128 0x7
	.uleb128 0x8
	.byte	0x90
	.uleb128 0x1
	.align 8
.LECIE1:
.LSFDE1:
	.long	.LEFDE1-.LASFDE1
.LASFDE1:
	.long	.LASFDE1-.Lframe1
	.long	.LFB1404
	.long	.LFE1404-.LFB1404
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI0-.LFB1404
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI1-.LCFI0
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE1:
.LSFDE3:
	.long	.LEFDE3-.LASFDE3
.LASFDE3:
	.long	.LASFDE3-.Lframe1
	.long	.LFB1413
	.long	.LFE1413-.LFB1413
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI2-.LFB1413
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI3-.LCFI2
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE3:
.LSFDE5:
	.long	.LEFDE5-.LASFDE5
.LASFDE5:
	.long	.LASFDE5-.Lframe1
	.long	.LFB1415
	.long	.LFE1415-.LFB1415
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI5-.LFB1415
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI6-.LCFI5
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE5:
.LSFDE7:
	.long	.LEFDE7-.LASFDE7
.LASFDE7:
	.long	.LASFDE7-.Lframe1
	.long	.LFB1414
	.long	.LFE1414-.LFB1414
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI7-.LFB1414
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI8-.LCFI7
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE7:
.LSFDE9:
	.long	.LEFDE9-.LASFDE9
.LASFDE9:
	.long	.LASFDE9-.Lframe1
	.long	.LFB1405
	.long	.LFE1405-.LFB1405
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI10-.LFB1405
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI11-.LCFI10
	.byte	0xd
	.uleb128 0x6
	.byte	0x4
	.long	.LCFI13-.LCFI11
	.byte	0x83
	.uleb128 0x3
	.align 8
.LEFDE9:
	.ident	"GCC: (GNU) 4.1.2 20080704 (Red Hat 4.1.2-54)"
	.section	.note.GNU-stack,"",@progbits
