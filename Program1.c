#include <stdio.h>
#include <string.h>

int main()
{
    int i, shift;
    char str[100];
    char x;

    printf("\nPlease choose one of the following options:\n");
    printf("Encryption (E) or Decryption (D)?\n");
    scanf(" %c", &x);

    printf("Enter the shift number: ");
    scanf("%d", &shift);

    getchar(); // Clear newline character from input buffer

    printf("\nEnter your message:\t");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline

    switch(x)
    {
    case 'E':
        for(i = 0; str[i] != '\0'; i++)
            str[i] = str[i] + shift;
        printf("*********************************");
        printf("\nEncrypted string: %s\n", str);
        break;

    case 'D':
        for(i = 0; str[i] != '\0'; i++)
            str[i] = str[i] - shift;
        printf("*********************************");
        printf("\nDecrypted string: %s\n", str);
        break;

    default:
        printf("\nInvalid option.\n");
    }

    return 0;
}
