	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.intel_syntax noprefix
	.globl	_message
	.align	4, 0x90
_message:                               ## @message
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp2:
	.cfi_def_cfa_register rbp
	pop	rbp
	ret
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Hello, World!\n"

	.section	__DATA,__data
	.globl	_msg                    ## @msg
	.align	3
_msg:
	.quad	L_.str


.subsections_via_symbols
