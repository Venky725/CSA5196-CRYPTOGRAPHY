#include <stdio.h>
#include <stdint.h>
void des_encrypt(uint64_t plainText, uint64_t key, uint64_t *cipherText);
void print_binary(uint64_t num);
int main() 
{
    uint64_t plainText, key, cipherText;
    printf("Enter the 28-bit plaintext: ");
    scanf("%llx", &plainText);
    plainText &= 0xFFFFFFFULL;

    printf("Enter the 64-bit encryption key: ");
    scanf("%llx", &key);
    des_encrypt(plainText, key, &cipherText);
    printf("\nPlaintext: ");
    print_binary(plainText);
    printf("\nKey: ");
    print_binary(key);
    printf("\nCiphertext: ");
    print_binary(cipherText);

    return 0;
}
void des_encrypt(uint64_t plainText, uint64_t key, uint64_t *cipherText) 
{
    *cipherText = plainText;
}
void print_binary(uint64_t num) 
{
    for (int i = 63; i >= 0; i--) 
	{
        uint64_t bit = (num >> i) & 1;
        printf("%llu", bit);
        if (i % 8 == 0)
            printf(" ");
    }
    printf("\n");
}
