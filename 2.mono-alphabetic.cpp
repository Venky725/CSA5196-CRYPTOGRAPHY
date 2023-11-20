#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to perform monoalphabetic substitution encryption
void monoalphabeticEncrypt(char text[], const char key[]) {
    int i;

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = key[text[i] - base];
        }
    }
}

// Function to perform monoalphabetic substitution decryption
void monoalphabeticDecrypt(char text[], const char key[]) {
    int i, j;

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            for (j = 0; j < ALPHABET_SIZE; j++) {
                if (key[j] == text[i]) {
                    text[i] = j + base;
                    break;
                }
            }
        }
    }
}

int main() {
    char plaintext[100];
    const char key[ALPHABET_SIZE + 1] = "XPMGTDHLYONZBWEARKJUFSCIQV"; // Example key

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Encrypting the plaintext
    monoalphabeticEncrypt(plaintext, key);
    printf("Encrypted text: %s\n", plaintext);

    // Decrypting the encrypted text
    monoalphabeticDecrypt(plaintext, key);
    printf("Decrypted text: %s\n", plaintext);

    return 0;
}
