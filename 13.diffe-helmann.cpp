#include <stdio.h>
#include <math.h>
int power(int base, int exponent, int modulus) 
{
    int result = 1;
    base = base % modulus;

    while (exponent > 0) 
	{
        if (exponent % 2 == 1)
            result = (result * base) % modulus;

        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}
int diffieHellman(int prime, int primitiveRoot, int privateKey) 
{
    return power(primitiveRoot, privateKey, prime);
}
int main() 
{
    int prime, primitiveRoot, privateKeyA, privateKeyB;
    int publicKeyA, publicKeyB, sharedKeyA, sharedKeyB;

    printf("Enter prime number: ");
    scanf("%d", &prime);

    printf("Enter primitive root: ");
    scanf("%d", &primitiveRoot);

    printf("Enter private key for user A: ");
    scanf("%d", &privateKeyA);

    printf("Enter private key for user B: ");
    scanf("%d", &privateKeyB);

    publicKeyA = diffieHellman(prime, primitiveRoot, privateKeyA);
    publicKeyB = diffieHellman(prime, primitiveRoot, privateKeyB);

    sharedKeyA = diffieHellman(prime, publicKeyB, privateKeyA);
    sharedKeyB = diffieHellman(prime, publicKeyA, privateKeyB);

    printf("\nPublic key of user A: %d", publicKeyA);
    printf("\nPublic key of user B: %d", publicKeyB);

    printf("\n\nShared key for user A: %d", sharedKeyA);
    printf("\nShared key for user B: %d", sharedKeyB);

    return 0;
}
