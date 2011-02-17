OUTPUT_FORMAT(elf32-littlearm)
ENTRY(_startup)

SECTIONS {
	.vectors : {
		*(.vectors)
	} > vectors
	
	.text : {
		*(.text)
		
		. = ALIGN(4);
		
		*(.rodata)
		
		. = ALIGN(4);
		
		__text_end__ = .;
	} > flash
	
	.data : {
		__data_begin__ = .;
		
		*(.data)
		
		__data_end__ = .;
	} > ram AT>flash

	. = ALIGN(4);

	.bss : {
		__bss_begin__ = .;
		
		*(.bss)
		
		__bss_end__ = .;
	} > ram

	__stack_end__ = 0x20000000 + 0x2000;

	/DISCARD/ : {
		*(.comment)
		*(.ARM.attributes)
	}
}
