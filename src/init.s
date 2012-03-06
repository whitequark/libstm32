.cpu cortex-m3
.syntax unified
.thumb

.text
.globl _startup
.type  _startup, %function
_startup:
	/* Load .data into RAM */
	ldr	r1, =__text_end__
	ldr	r2, =__data_begin__
	ldr	r3, =__data_end__

0:
	ldr	r0, [r1], #4
	str	r0, [r2], #4

	cmp	r3, r2
	bhi	0b

	/* Clear BSS */
	eor	r0, r0
	ldr	r2, =__bss_begin__
	ldr	r3, =__bss_end__

0:
	str	r0, [r2], #4

	cmp	r3, r2
	bhi	0b

	/* Jump to C code */
	bl main

	/* Halt */
0:	b 0b

.globl __aeabi_unwind_cpp_pr0
.type __aeabi_unwind_cpp_pr0, %function
__aeabi_unwind_cpp_pr0:
	bx lr
