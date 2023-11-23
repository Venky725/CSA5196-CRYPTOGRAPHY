#include <stdio.h>
#include <stdlib.h>
#define MATRIX_SIZE 3 
void encryptHillCipher(int plaintext[MATRIX_SIZE], int key[MATRIX_SIZE][MATRIX_SIZE]) 
{
    int ciphertext[MATRIX_SIZE] = {0};
    
    for (int i = 0; i < MATRIX_SIZE; i++) 
	{
        for (int j = 0; j < MATRIX_SIZE; j++) 
		{
            ciphertext[i] += (key[j][i] * plaintext[j]);
        }    
        ciphertext[i] %= 26;
    }
    printf("Encrypted message: ");
    for (int i = 0; i < MATRIX_SIZE; i++) 
	{
        printf("%c", 'A' + ciphertext[i]);
    }
    printf("\n");
}
int main() 
{
    int plaintext[MATRIX_SIZE] = {15,0,24}; 
    int key[MATRIX_SIZE][MATRIX_SIZE] = {
        {17,17,5},
        {21,18,21},
		{2,2,19}
    };  
    printf("Plaintext: ");
    for (int i = 0; i < MATRIX_SIZE; i++) 
	{
    	
        printf("%c", 'A' + plaintext[i]);
    }
    printf("\n");
    encryptHillCipher(plaintext, key);
    return 0;
}
