/****************************************/
/* Program Name: ascii2bin              */
/* Author: Jericho Raz                  */
/* Date: 3/2/21                         */
/****************************************/
/* Description: checksum algorithm in C */
/* Validation Checks:                   */
/* Enhancements: None                   */
/****************************************/

#include stdio.h
#include stdlib.h

#define byte unsigned char

int main(int argc, char* argv[], char** envp)
{
    offset = 30;
    number = 0;

    int ascii_value = 0;

    int retval = read(0, &ascii_value, 1);

    while (retval == 1)
    {
        printf("%u\n", ascii_value);

        if (ascii_value == )
        digit = ascii_value - offset;
        number = (number << 1) + digit;
        retval = read(0, &ascii_value, 1);
    }
        

    printf("%u\n", number);
    return 0;
}