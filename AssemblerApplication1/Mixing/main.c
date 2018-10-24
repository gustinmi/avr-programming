
#include <avr/io.h>

/* macro with assembler */

/*
				 
Special registers
				 
__SREG__ Status register at address 0x3F
__SP_H__ Stack pointer high byte at address 0x3E
__SP_L__ Stack pointer low byte at address 0x3D
__tmp_reg__ Register r0, used for temporary storage
__zero_reg__ Register r1, always zero

Register r0 may be freely used by your assembler code and need not be restored at the
				 
*/

uint16_t delay_count = 4000;

/* how to use c variables in assembler code */
void delay(uint8_t ms)
{
	uint16_t cnt;
	asm volatile (
		"\n"
		"L_dl1%=:" "\n\t"
		"mov %A0, %A2" "\n\t"
		"mov %B0, %B2" "\n"
		"L_dl2%=:" "\n\t"
		"sbiw %A0, 1" "\n\t"
		"brne L_dl2%=" "\n\t"
		"dec %1" "\n\t"
		"brne L_dl1%=" "\n\t"
		: "=&w" (cnt)
		: "r" (ms), "r" (delay_count)
	);
}




int main(void)
{
	int value;
	int sum, x, y;
	
	
	x=0;
	y=1;
	sum = x+y;
	
	long z = 16000000L;
	
	/*
	
	asm(code : output operand list : input operand list [: clobber list]);
	
	The assembler instructions, defined as a single string constant:	    "in %0, %1"
	A list of output operands, separated by commas. Our example uses just "=r" (value)
	A comma separated list of input operands. Again our example uses one operand only: "I" (_SFR_IO_ADDR(PORTD))
	clobber: However, if you are using registers, which had not been passed as operands, you need to inform the
	compiler about this.
	
	%0 refers to "=r" (value) and
	%1 refers to "I" (_SFR_IO_ADDR(PORTD)).
	
	*/
	
	// executing assembler code and assign it to variable
	asm("in %0, %1" : "=r" (value) : "I" (_SFR_IO_ADDR(PORTD)) );
	
	// nsimple statement   no outputs, no inputs, preserve ::
	asm volatile("cli"::);
	
	asm volatile("nop\n\t"
				"nop\n\t"
				"nop\n\t"
				"nop\n\t"
	::);
	
	delay(1000);
	
	/*
	
	#define loop_until_bit_is_clear(port,bit) \
	__asm__ __volatile__ ( \
	"L_%=: " "sbic %0, %1" "\n\t" \
	"rjmp L_%=" \
	: 
	: "I" (_SFR_IO_ADDR(port)),
	"I" (bit)
	)
	
	*/

	//indication to compiler, to hold local variables in registers.	
	
	register unsigned char counter asm("r3");
	
	// operate on this register
	asm volatile("clr r3");
	
	
    /* Replace with your application code */
    while (1) 
    {
		   value++;
    }
}

