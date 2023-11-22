#include <stdio.h>
#include <string.h>

// Function to perform ECB encryption
void ecb_encrypt(const char* plaintext, const char* key, char* ciphertext, int len) {
    int block_size = 8; // Assuming a block size of 8 bytes

    for (int i = 0; i < len; i += block_size) {
        // Encrypt each block independently
        for (int j = 0; j < block_size; j++) {
            ciphertext[i + j] = plaintext[i + j] ^ key[j];
        }
    }
}

// Function to perform ECB decryption
void ecb_decrypt(const char* ciphertext, const char* key, char* plaintext, int len) {
    // Decryption is the same as encryption in ECB mode
    ecb_encrypt(ciphertext, key, plaintext, len);
}

int main() {
    // Get user input for plaintext
    printf("Enter the plaintext: ");
    char plaintext[100]; // Assuming a maximum length of 100 characters
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove the newline character

    // Get user input for key
    printf("Enter the key: ");
    char key[100]; // Assuming a maximum length of 100 characters
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove the newline character

    int len = strlen(plaintext);
    char ciphertext[len];

    // Encrypt the plaintext
    ecb_encrypt(plaintext, key, ciphertext, len);

    // Print the ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < len; i++) {
        printf("%02x ", (unsigned char)ciphertext[i]);
    }
    printf("\n");

    // Decrypt the ciphertext
    char decrypted_text[len];
    ecb_decrypt(ciphertext, key, decrypted_text, len);

    // Print the decrypted plaintext
    printf("Decrypted Text: %s\n", decrypted_text);

    return 0;
}

