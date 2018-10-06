#include "ex1.h"

/********************************************************************************************
 * The is_little_endian function.
 * This function determines whether our computer works by little endian or big endian.
 * The function uses a char pointer that points to the first cell of an int number.
 * If it works by little endian - the function returns 1, else if it works by big endian -
 * the function returns 0.
 *
 *******************************************************************************************/

int is_little_endian(){
    //Defining an int number.
    int number =0x0001;
    //We set a char pointer to the number we've set.
    char *c = (char*)&number;
    //That means that the char pointer holds a value of '1', which means that the computer
    // saves the MSB in a high address (thus the LSB in a low address) - little
    // endian system. The number 1 should be in *c.
    if ((*c)==0x01){
        return  1;
    }
        //The char pointer holds a value of '0'- that means our computer works by big
        // endian system - it saves the MSB in a low address (thus the LSB in high address).
        // c* should hold a 0 number.
    else {
        return 0;
    }
}

/********************************************************************************************
 * The merge_bytes function.
 * This function gets 2 unsigned long, and returns a new word that is built from the bytes of
 * the first long, expet the LSB- that is switched with the other long's LSB.
 *******************************************************************************************/

unsigned long merge_bytes(unsigned long x, unsigned long y){
    //Defining 2 pointer for each long.
    char* px = (char*)&x;
    char *py = (char*)&y;
    //If the computer works by little endian system:
    if (is_little_endian()){
        //Switch between the LSBs, that are saved in a low address - the first place that the
        //pointer points to.
        *(px)=*(py);
        //If the compute works by big endian system:
    } else {
        int size = sizeof(unsigned long)-1;
        //Switch between the LSBs, that are saved in a high address - the last place that the
        //pointer points to.
        *(px+size)=*(py+size);
    }
    return x;
}

/********************************************************************************************
 * The put-byte function.
 * This function gets an unsigned long, an unsigned char, and and int that symbolizes the
 * i's byte of the unsigned long (0 for LSB). The function replaces the i's byte of the
 * unsigned long with the unsigned char, depending if the computer works by big endians or
 * little endians system.
 *******************************************************************************************/
unsigned long put_byte(unsigned long x, unsigned char b, int i){
    //Defining a char* pointer to point on the unsigned long.
    char* px = (char*)&x;
    //If the computer works by little endian, than the LSB is saved in a low address, that
    //means that px points directly on the LSB of the unsigned long.
    if (is_little_endian()){
        //Promote the pointer by the i number.
        *(px+i)=b;
        //If the computer works by big endian, than the LSB is saved in a high address, that
        //means that in order to get to the LSB- we need to get to the last byte.
    } else {
        //Defining an int that specifies the word's size.
        int size = sizeof(unsigned long)-1;
        //Promote the pointer by the i number.
        *(px+(size-i)) = b;
    }
    return x;
}
