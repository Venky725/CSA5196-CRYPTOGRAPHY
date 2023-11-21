#include <stdio.h>
#include <string.h>

// Function to encrypt the plaintext using the one-time pad Vigenère cipher
void encrypt(char plaintext[], int key[], int n) {
    for (int i = 0; i < n; i++) {
        if (plaintext[i] != ' ') {
            // Encrypt only alphabetical characters
            plaintext[i] = (plaintext[i] - 'a' + key[i]) % 26 + 'a';
        }
    }
}

// Function to decrypt the ciphertext using the one-time pad Vigenère cipher
void decrypt(char ciphertext[], int key[], int n) {
    for (int i = 0; i < n; i++) {
        if (ciphertext[i] != ' ') {
            // Decrypt only alphabetical characters
            ciphertext[i] = (ciphertext[i] - 'a' - key[i] + 26) % 26 + 'a';
        }
    }
}

int main() {
    char plaintext[100];
    int key[100];
    int n;

    // Get user input for plaintext
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    // Remove newline character from the input
    plaintext[strcspn(plaintext, "\n")] = '\0';

    n = strlen(plaintext);

    // Get user input for key
    printf("Enter the key (space-separated integers): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &key[i]);
    }

    // Encrypt the plaintext
    encrypt(plaintext, key, n);

    // Print the encrypted ciphertext
    printf("Encrypted Ciphertext: %s\n", plaintext);

    // Decrypt the ciphertext to find the key
    char ciphertext[100];
    strcpy(ciphertext, plaintext); // Save the ciphertext before decryption

    decrypt(ciphertext, key, n);

    // Print the decrypted plaintext
    printf("Decrypted Plaintext: %s\n", ciphertext);

    return 0;
}

