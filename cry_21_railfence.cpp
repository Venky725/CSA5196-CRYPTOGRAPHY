#include <stdio.h>
#include <string.h>

void encryptRailFence(char* message, int rails) 
{
    int messageLength = strlen(message);
    char encryptedMessage[messageLength];
    int railLength = 2 * (rails - 1);

    int index = 0;
    for (int i = 0; i < rails; i++) 
	{
        for (int j = i; j < messageLength; j += railLength) 
		{
            encryptedMessage[index++] = message[j];
            if (i != 0 && i != (rails - 1) && (j + railLength - 2 * i) < messageLength) 
			{
                encryptedMessage[index++] = message[j + railLength - 2 * i];
            }
        }
    }
    encryptedMessage[index] = '\0';
    printf("Encrypted message: %s\n", encryptedMessage);
}
void decryptRailFence(char* encryptedMessage, int rails) 
{
    int messageLength = strlen(encryptedMessage);
    char decryptedMessage[messageLength];
    int railLength = 2 * (rails - 1);

    int index = 0;
    for (int i = 0; i < rails; i++) 
	{
        for (int j = i; j < messageLength; j += railLength) 
		{
            decryptedMessage[j] = encryptedMessage[index++];

            if (i != 0 && i != (rails - 1) && (j + railLength - 2 * i) < messageLength) 
			{
                decryptedMessage[j + railLength - 2 * i] = encryptedMessage[index++];
            }
        }
    }
    decryptedMessage[index] = '\0';
    printf("Decrypted message: %s\n", decryptedMessage);
}
int main() {
    char message[] = "veneela";
    int rails=2;

    printf("Original message: %s\n", message);

    encryptRailFence(message, rails);
    decryptRailFence(message, rails);

    return 0;
}
