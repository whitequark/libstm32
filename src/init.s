.cpu cortex-m3
.syntax unified
.thumb

.section .vectors, "xa", %progbits
.globl __vector_table
.type __vector_table, %function
__vector_table:
	.word __stack_end__ /* initial SP value */
	.word _startup      /* next instruction in Thumb mode, fetch from flash */

.text
.globl _startup
.type  _startup, %function
_startup:
	bl main

0:	b 0b /* halt */
