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

int main() {
    char message[200];
    int shift_value, i;
    char choice;

    printf("Choose (E)ncrypt or (D)ecrypt: ");// user choose E/D
    scanf(" %c", &choice);

    printf("Enter shift key (Any interger): "); //user enter shift key
    scanf("%d", &shift_value);

    getchar(); //clear leftover newline
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; //remove newline

}
