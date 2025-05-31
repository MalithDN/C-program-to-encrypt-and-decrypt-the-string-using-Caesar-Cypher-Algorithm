#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 26 //Define Alphabet Size (defalt value 26)

//create function for Circular queue logic with modular arithmetic for alphabet wrap-around.
char Circular_Queue_rotate(char charecter, int shift_value, int encrypt_message) {
    char base = isupper(charecter) ? 'A' : 'a';
    if (encrypt_message)
        return (char)(base + (charecter - base + shift_value + SIZE) % SIZE);  //process Encrypt message.
    else
        return (char)(base + (charecter - base - shift_value + SIZE) % SIZE); //process Decrypt message.
}


