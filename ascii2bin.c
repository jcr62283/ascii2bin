/****************************************/
/* Program Name: ascii2bin              */
/* Author: Jericho Raz                  */
/* Date: 3/2/21                         */
/****************************************/
/* Description: checksum algorithm in C */
/* Validation Checks:                   */
/* Enhancements: None                   */
/****************************************/

#include "stdio.h"
#include "stdlib.h"

#define byte unsigned char
int read(int fildes, void* buf, size_t nbyte);

int main(int argc, char* argv[], char** envp)
{
    int offset = 30;
    int number = 0;

    byte ascii_value[1];

    int retval = read(0, &ascii_value, 1);

    while (retval == 1)
    {
        printf("%d\n", ascii_value[0]);

        if (ascii_value[0] == 10)
	{
	    break;
	}

        int digit = ascii_value[0] - offset;
        number = (number << 1) + digit;
        retval = read(0, &ascii_value, 1);
    }
        

    printf("%u\n", number);
    return 0;
}
