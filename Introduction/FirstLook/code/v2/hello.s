	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.intel_syntax noprefix
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
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
	sub	rsp, 16
	mov	dword ptr [rbp - 4], edi
	mov	qword ptr [rbp - 16], rsi
	call	_message
	xor	eax, eax
	add	rsp, 16
	pop	rbp
	ret
	.cfi_endproc


.subsections_via_symbols
