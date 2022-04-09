	.file	"mono.c"
	.text
	.section	.rodata
.LC0:
	.string	"monolitico"
.LC1:
	.string	"fat=%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
.L2:
	endbr64
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
.L3:
	endbr64
	movl	$5, -8(%rbp)
.L4:
	endbr64
	movl	$1, -4(%rbp)
.L5:
	movl	-4(%rbp), %eax
	imull	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
.L6:
	endbr64
	subl	$1, -8(%rbp)
.L7:
	endbr64
	cmpl	$1, -8(%rbp)
	jle	.L12
	jmp	.L5
.L12:
	nop
.L9:
	endbr64
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L10:
	endbr64
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
