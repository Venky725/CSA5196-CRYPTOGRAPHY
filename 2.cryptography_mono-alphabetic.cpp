#include <stdio.h>
#include <ctype.h>

void encrypt(char *message, char *cipherMap) {
    while (*message != '\0') {
        if (isalpha(*message)) {
            char base = isupper(*message) ? 'A' : 'a';
            *message = cipherMap[*message - base];
        }
        message++;
    }
}

int main() {
    char message[100];
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    char cipherMap[] = "ZYXWVUTSRQPONMLKJIHGFEDCBAzyxwvutsrqponmlkjihgfedcba";

    encrypt(message, cipherMap);

    printf("Encrypted message: %s", message);

    return 0;
}

