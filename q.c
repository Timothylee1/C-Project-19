/*!
@file       q.c
@author     Timothy Lee (timothykexin.lee@digipen.edu.sg)
@course     RSE 1201
@section    Laboratory 11
@Laboratory Practice working with 2D arrays of structures
@date       26/11/2021
@brief      This file contains definition of a function that takes in the address of an 
            object of any type, its size, with the number of hexadeicmal digits per line 
            of output, and prints out to the console with a layout similar to that of a hex 
            editor interface. It displays the object in the right format to the output 
            stream.

*//*________________________________________________________________________________________*/
#include <stdio.h>
#include "q.h"

/*!
@brief  This function takes in the address of an object of any type, its size, with the 
        number of hexadeicmal digits per line of output, and prints out to the console with
        a layout similar to that of a hex editor interface. It displays the object in the 
        right format to the output stream.

@param  ptr is a void const pointer
        size, span, k, l, range are of data type size_t
        p is a const char pointer 
        
@return nothing
*//*_______________________________________________________________________________________*/
void print_data(const void* ptr, size_t size, size_t span) {
    //ptr is pointer to an array of base element
    //size is size(including null) of the array -> total count of elements in the array
    //span is number of bytes printed per line
    //with the fixed number of elements in the array, there will be a given number of elements
    //per row. given the number of elements per columns and total number of elements,
    //you will then be able to calculate the number of range required.
    //print hexadecimal data byte-by-byte always with 2 hexadecimal digits per byte
    //print ASCII data byte-by-byte always with 1 character per byte
    //0x41, 0x61, 0x4161 --> 41 61 61 41 (HEX) | A a a A (ASCII)
    //unsigned short int value 0x4161
    //char upper, char lower
    size_t k, l;
    const char *p = ptr;                                //have p point to base element of p

    for (k = 0; k < size; k++) {                        //Less than total num of elements

        printf("%x ", *(p+k));                          //%x to print hex without the 0x; prints each element 
        if ((k+1) % 4 == 0)                             //+1 cuz start with 0
            printf("  ");                               //divider between each set
        
        if ((k+1) % span == 0) {                        //checks if there are span number of elements printed
        
            printf("|");                                //divider of hex and ascii
        
            size_t range = (k + 1);                     //number of ele to print
            for(l= ((k+1) - span); l < range; l++) {      

            if (l % 4 == 0)
                printf("  ");
                
            printf(" %c", *(p+l));
            }
        }
    if ( (k+1) % span == 0)
        printf("\n");
    }
}
