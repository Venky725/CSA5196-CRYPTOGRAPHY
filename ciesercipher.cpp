#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *message, int key) {
    while (*message != '\0') {
        if (isalpha(*message)) {
            char base = isupper(*message) ? 'A' : 'a';
            *message = (char)(((int)(*message - base + key) % 26) + base);
        }
        message++;
    }
}

int main() {
    char message[100];
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    // Iterate through keys 1 to 25
    for (int key = 1; key <= 25; key++) {
        char encryptedMessage[100];
        strcpy(encryptedMessage, message);
        encrypt(encryptedMessage, key);
        printf("Key %d: %s\n", key, encryptedMessage);
    }

    return 0;
}

