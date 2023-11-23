#include <stdio.h>
#include <string.h>
void ecb_encrypt(const char* plaintext, const char* key, char* ciphertext, int len) 
{
    int block_size = 8; 
    for (int i = 0; i < len; i += block_size) 
	{
        for (int j = 0; j < block_size; j++) 
		{
            ciphertext[i + j] = plaintext[i + j] ^ key[j];
        }
    }
}
void ecb_decrypt(const char* ciphertext, const char* key, char* plaintext, int len) 
{
    ecb_encrypt(ciphertext, key, plaintext, len);
}
int main() 
{
    printf("Enter the plaintext: ");
    char plaintext[100]; 
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 

    printf("Enter the key: ");
    char key[100]; 
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 

    int len = strlen(plaintext);
    char ciphertext[len];

    ecb_encrypt(plaintext, key, ciphertext, len);

    
    printf("Ciphertext: ");
    for (int i = 0; i < len; i++) 
	{
        printf("%02x ", (unsigned char)ciphertext[i]);
    }
    printf("\n");

    char decrypted_text[len];
    ecb_decrypt(ciphertext, key, decrypted_text, len);

    printf("Decrypted Text: %s\n", decrypted_text);

    return 0;
}
