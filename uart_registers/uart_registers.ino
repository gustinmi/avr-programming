/* Initialize USART.
 * Set the baud to 31250, 8 data bits, one stop bit.
 */

void init() {

	UBRRH = 0;
	UBRRL = (F_CPU/MIDI_BAUD/8)-1;
	UCSRA = (1<<U2X);
	UCSRB = (1<<RXEN);
	UCSRC = (3<<UCSZ0);

}

void takeData(){
	


	/* Poll input for MIDI bytes. */
	if ((UCSRA & (1<<RXC)) != 0) {

	    c = UDR;

	    if ((c & 0xf8) == 0xf8) {
			/* Real-time messages. */

			if (c == 0xf8) {
			    
			}
			else if (c == 0xfa) {
			    
			}
			else if (c == 0xfc || c == 0xff) {
			    
			}

	    }
	}


}

