/*
 * DissasemblyCprog.c
 *
 * Created: 15.10.2018 15:07:22
 * Author : gustin
 */ 

#include <avr/io.h>

int myFunc(int a){
	return a*a;
}

int main(void)
{
	int x = 1;
	int y = 2;
	int xx = 0, yy = 0, sum;
	
    /* Replace with your application code */
    
	xx = myFunc(x);
	yy = myFunc(y);
	sum = xx + yy;
	
	
	
	
	return 0;
}

