#include <stdio.h>
#include <string.h>
#include <ctype.h>
void vigenereCipher(char* key, char* message) 
{
    int keyLen = strlen(key);
    int msgLen = strlen(message);
    char encryptedMsg[msgLen];

    for (int i = 0, j = 0; i < msgLen; i++) 
	{
        char c = message[i];

        if (isalpha(c)) 
		{
            char base = isupper(c) ? 'A' : 'a';
            int ki = tolower(key[j % keyLen]) - 'a';
            int mi = tolower(c) - base;
            int ci = (mi + ki) % 26;
            encryptedMsg[i] = ci + base;
            j++;
        } else {
            encryptedMsg[i] = c;
        }
    }
    encryptedMsg[msgLen] = '\0';
    printf("Encrypted message: %s\n", encryptedMsg);
}
int main() 
{
    char key[100];
    char message[100];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the message: ");
    scanf(" %[^\n]s", message);

    vigenereCipher(key, message);

    return 0;
}
