	.file	"dijkstras.c"
	.text
	.def	printf;	.scl	3;	.type	32;	.endef
	.seh_proc	printf
printf:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rbx, %r8
	movq	32(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfprintf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.globl	minDistance
	.def	minDistance;	.scl	2;	.type	32;	.endef
	.seh_proc	minDistance
minDistance:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	$2147483647, -4(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L4
.L6:
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	.L5
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L5
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, -8(%rbp)
.L5:
	addl	$1, -12(%rbp)
.L4:
	cmpl	$5, -12(%rbp)
	jle	.L6
	movl	-8(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "Vertex\11\11Distance from Source\12\0"
.LC1:
	.ascii "%d\11\11%d\12\0"
	.text
	.globl	printDistances
	.def	printDistances;	.scl	2;	.type	32;	.endef
	.seh_proc	printDistances
printDistances:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$0, -4(%rbp)
	jmp	.L9
.L10:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-4(%rbp), %eax
	movl	%edx, %r8d
	movl	%eax, %edx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	printf
	addl	$1, -4(%rbp)
.L9:
	cmpl	$5, -4(%rbp)
	jle	.L10
	nop
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	dijkstra
	.def	dijkstra;	.scl	2;	.type	32;	.endef
	.seh_proc	dijkstra
dijkstra:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$96, %rsp
	.seh_stackalloc	96
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L12
.L13:
	movl	-4(%rbp), %eax
	cltq
	movl	$2147483647, -48(%rbp,%rax,4)
	movl	-4(%rbp), %eax
	cltq
	movb	$0, -54(%rbp,%rax)
	addl	$1, -4(%rbp)
.L12:
	cmpl	$5, -4(%rbp)
	jle	.L13
	movl	24(%rbp), %eax
	cltq
	movl	$0, -48(%rbp,%rax,4)
	movl	$0, -8(%rbp)
	jmp	.L14
.L18:
	leaq	-54(%rbp), %rdx
	leaq	-48(%rbp), %rax
	movq	%rax, %rcx
	call	minDistance
	movl	%eax, -16(%rbp)
	movl	-16(%rbp), %eax
	cltq
	movb	$1, -54(%rbp,%rax)
	movl	$0, -12(%rbp)
	jmp	.L15
.L17:
	movl	-12(%rbp), %eax
	cltq
	movzbl	-54(%rbp,%rax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	.L16
	movl	-16(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rax, %rdx
	movl	-12(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %eax
	testl	%eax, %eax
	je	.L16
	movl	-16(%rbp), %eax
	cltq
	movl	-48(%rbp,%rax,4), %eax
	cmpl	$2147483647, %eax
	je	.L16
	movl	-16(%rbp), %eax
	cltq
	movl	-48(%rbp,%rax,4), %ecx
	movl	-16(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rax, %rdx
	movl	-12(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %eax
	leal	(%rcx,%rax), %edx
	movl	-12(%rbp), %eax
	cltq
	movl	-48(%rbp,%rax,4), %eax
	cmpl	%eax, %edx
	jge	.L16
	movl	-16(%rbp), %eax
	cltq
	movl	-48(%rbp,%rax,4), %ecx
	movl	-16(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$3, %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rax, %rdx
	movl	-12(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %eax
	leal	(%rcx,%rax), %edx
	movl	-12(%rbp), %eax
	cltq
	movl	%edx, -48(%rbp,%rax,4)
.L16:
	addl	$1, -12(%rbp)
.L15:
	cmpl	$5, -12(%rbp)
	jle	.L17
	addl	$1, -8(%rbp)
.L14:
	cmpl	$4, -8(%rbp)
	jle	.L18
	leaq	-48(%rbp), %rax
	movq	%rax, %rcx
	call	printDistances
	nop
	addq	$96, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$192, %rsp
	.seh_stackalloc	192
	.seh_endprologue
	call	__main
	movl	$0, -160(%rbp)
	movl	$4, -156(%rbp)
	movl	$0, -152(%rbp)
	movl	$0, -148(%rbp)
	movl	$0, -144(%rbp)
	movl	$0, -140(%rbp)
	movl	$4, -136(%rbp)
	movl	$0, -132(%rbp)
	movl	$8, -128(%rbp)
	movl	$0, -124(%rbp)
	movl	$0, -120(%rbp)
	movl	$0, -116(%rbp)
	movl	$0, -112(%rbp)
	movl	$8, -108(%rbp)
	movl	$0, -104(%rbp)
	movl	$7, -100(%rbp)
	movl	$0, -96(%rbp)
	movl	$4, -92(%rbp)
	movl	$0, -88(%rbp)
	movl	$0, -84(%rbp)
	movl	$7, -80(%rbp)
	movl	$0, -76(%rbp)
	movl	$9, -72(%rbp)
	movl	$14, -68(%rbp)
	movl	$0, -64(%rbp)
	movl	$0, -60(%rbp)
	movl	$0, -56(%rbp)
	movl	$9, -52(%rbp)
	movl	$0, -48(%rbp)
	movl	$10, -44(%rbp)
	movl	$0, -40(%rbp)
	movl	$0, -36(%rbp)
	movl	$4, -32(%rbp)
	movl	$14, -28(%rbp)
	movl	$10, -24(%rbp)
	movl	$0, -20(%rbp)
	movl	$0, -4(%rbp)
	movl	-4(%rbp), %edx
	leaq	-160(%rbp), %rax
	movq	%rax, %rcx
	call	dijkstra
	movl	$0, %eax
	addq	$192, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 11.2.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
