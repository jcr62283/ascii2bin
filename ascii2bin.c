/*
 * Program Name: ascii2bin
 * Author: Jericho Raz
 * Date: 3/2/21
 * Description: Converts ASCII strings of binary numbers into binary
 * Validation Checks:
 *  - Input only consists of 1, 0, \n
 * Enhancements: None
 */

#include "stdio.h"
#include "stdlib.h"

#define byte unsigned char

int read(int fildes, void* buf, size_t nbyte);

int main(int argc, char* argv[], char** envp)
{
    int offset = 0x30;  /* ASCII Value of '0' is 48 = 30 in hex */
    int number = 0;

    byte ascii_value[1];

    int retval = read(0, &ascii_value, 1);

    /* Keep reading bits until NL or EOF */
    while (retval == 1 && ascii_value[0] != 0x0A)
    {
        byte readbyte = ascii_value[0];
        int digit = readbyte - offset;

        /* Exit program if number entered is not in binary */
        if (!(digit != 0 || digit != 1))
        {
            fprintf(stderr, "Error in input. Digit %d is not a binary digit.\n", digit);
            return 1;
        }

        /* Calculate new number based on new bit */
        number = (number << 1) + digit;
        retval = read(0, &ascii_value, 1);
    }


    printf("%u\n", number);
    return 0;
}