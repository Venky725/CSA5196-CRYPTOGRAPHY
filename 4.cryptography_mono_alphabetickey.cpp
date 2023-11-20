#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encrypt(char *message, char *key) {
    int keyLen = strlen(key);
    int messageLen = strlen(message);

    for (int i = 0; i < messageLen; i++) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            int shift = tolower(key[i % keyLen]) - 'a';

            // Apply monoalphabetic substitution
            message[i] = (char)(((tolower(message[i]) - base + shift) % 26) + base);
        }
    }
}

int main() {
    char message[100];
    char key[100];

    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);

    // Ensure the key and message are of the same length
    int keyLen = strlen(key);
    int messageLen = strlen(message);

    if (keyLen > messageLen) {
        printf("Error: Key length is longer than the message length.\n");
        return 1;
    }

    // Encrypt the message using polyalphabetic substitution
    encrypt(message, key);

    printf("Encrypted message: %s", message);

    return 0;
}

