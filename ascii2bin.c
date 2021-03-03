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
    int offset = 48;
    int number = 0;

    byte ascii_value[1];

    int retval = read(0, &ascii_value, 1);

    while (retval == 1)
    {
	byte readbyte = ascii_value[0];

	if (!(readbyte == 10 || readbyte == 48 || readbyte == 49))
	{
	    fprintf(stderr, "Error in input. Digit %d is not a binary digit.\n", readbyte - offset);
	    return 1;
	}

        if (readbyte == 10)
	{
	    break;
	}

        int digit = readbyte - offset;
        number = (number << 1) + digit;
        retval = read(0, &ascii_value, 1);
    }
        

    printf("%u\n", number);
    return 0;
}
