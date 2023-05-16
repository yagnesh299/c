#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void encrypt(char *plaintext, int shift);
void decrypt(char *ciphertext, int shift);

int main()
{
    char plaintext[100];
    char ciphertext[100];
    int shift;

    printf("Enter the plaintext: ");
    fgets(plaintext, 100, stdin);

    printf("Enter the shift value: ");
    scanf("%d", &shift);

    encrypt(plaintext, shift);
    printf("Encrypted ciphertext: %s\n", plaintext);

    printf("Enter the ciphertext: ");
    scanf(" %[^\n]s", ciphertext);

    decrypt(ciphertext, shift);
    printf("Decrypted plaintext: %s\n", ciphertext);

    return 0;
}

void encrypt(char *plaintext, int shift)
{
    int i;

    for (i = 0; plaintext[i] != '\0'; i++)
    {
        if (isupper(plaintext[i]))
        {
            plaintext[i] = ((plaintext[i] - 'A' + shift) % 26) + 'A';
        }
        else if (islower(plaintext[i]))
        {
            plaintext[i] = ((plaintext[i] - 'a' + shift) % 26) + 'a';
        }
    }
}

void decrypt(char *ciphertext, int shift)
{
    int i;

    for (i = 0; ciphertext[i] != '\0'; i++)
    {
        if (isupper(ciphertext[i]))
        {
            ciphertext[i] = ((ciphertext[i] - 'A' - shift + 26) % 26) + 'A';
        }
        else if (islower(ciphertext[i]))
        {
            ciphertext[i] = ((ciphertext[i] - 'a' - shift + 26) % 26) + 'a';
        }
    }
}
