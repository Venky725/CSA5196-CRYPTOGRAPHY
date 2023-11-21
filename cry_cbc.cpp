#include <stdio.h>
#include <string.h>
#include <openssl/des.h>
void encrypt_CBC_3DES(const char *input, const char *key, const char *iv, char *output) {
    DES_cblock desKey1, desKey2, desKey3, desIV;
    DES_key_schedule keySchedule1, keySchedule2, keySchedule3;

    // Set the keys and IV
    memcpy(desKey1, key, 8);
    memcpy(desKey2, key + 8, 8);
    memcpy(desKey3, key + 16, 8);
    memcpy(desIV, iv, 8);

    // Set up the key schedules
    DES_set_key_unchecked(&desKey1, &keySchedule1);
    DES_set_key_unchecked(&desKey2, &keySchedule2);
    DES_set_key_unchecked(&desKey3, &keySchedule3);

    // Encrypt in CBC mode
    DES_ede3_cbc_encrypt((const unsigned char *)input, (unsigned char *)output, strlen(input),
                         &keySchedule1, &keySchedule2, &keySchedule3, &desIV, DES_ENCRYPT);
}

int main() {
    const char *plaintext = "HelloCBC3DES";
    const char *key = "0123456789abcdef0123456789abcdef0123456789abcdef";
    const char *iv = "abcdefgh";

    char ciphertext[256];

    // Encrypt in CBC mode with 3DES
    encrypt_CBC_3DES(plaintext, key, iv, ciphertext);

    // Print the encrypted ciphertext
    printf("Encrypted Ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++) {
        printf("%02x", (unsigned char)ciphertext[i]);
    }
    printf("\n");

    return 0;
}

