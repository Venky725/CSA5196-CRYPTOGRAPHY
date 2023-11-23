#include <stdio.h>
#include <stdint.h>
void reverseKeyGeneration(uint64_t* keys) 
{
    uint64_t temp;
    for (int i = 0; i < 8; i++) 
	{
        temp = keys[i];
        keys[i] = keys[15 - i];
        keys[15 - i] = temp;
    }
}
uint64_t desDecrypt(uint64_t ciphertext, uint64_t* keys)
{  
    uint64_t permutation = 0;
    for (int i = 0; i < 64; i++)
	{
        permutation |= ((ciphertext >> (63 - i)) & 0x01) << (63 - i);
    }
    for (int round = 0; round < 16; round++) 
	{
        uint64_t expansion = 0;
        for (int i = 0; i < 48; i++) 
		{
            expansion |= ((permutation >> (31 - i)) & 0x01) << (47 - i);
        }
        uint64_t roundKey = keys[round];
        uint64_t roundOutput = expansion ^ roundKey;
        permutation = roundOutput;
    }
    uint64_t plaintext = 0;
    for (int i = 0; i < 64; i++) 
	{
        plaintext |= ((permutation >> (63 - i)) & 0x01) << (63 - i);
    }
    return plaintext;
}
int main() 
{
    uint64_t ciphertext = 0x0123456789ABCDEF;
    uint64_t keys[16] = {
        0x0000000000000000,
        0x1111111111111111,
        0x2222222222222222,
        0x3333333333333333,
        0x4444444444444444,
        0x5555555555555555,
        0x6666666666666666,
        0x7777777777777777,
        0x8888888888888888,
        0x9999999999999999,
        0xAAAAAAAAAAAAAAAA,
        0xBBBBBBBBBBBBBBBB,
        0xCCCCCCCCCCCCCCCC,
        0xDDDDDDDDDDDDDDDD,
        0xEEEEEEEEEEEEEEEE,
        0xFFFFFFFFFFFFFFFF
    };
    reverseKeyGeneration(keys);
    uint64_t plaintext = desDecrypt(ciphertext, keys);
    printf("Decrypted plaintext: %016llx\n", plaintext);
    return 0;
}
