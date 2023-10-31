#include "uart.h"

#define UART0  *((volatile unsigned int*)((unsigned int*)0x101f1000)) 

void myfunc (unsigned char * str)
{

while (* str != '\0')
{

UART0 = (unsigned int)*str ;
str ++ ;

}


}

