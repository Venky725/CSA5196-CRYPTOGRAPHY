#include <stdio.h>
#include <string.h>
#include <ctype.h>
void encryptMonoalphabetic(char message[], char key[]) 
{
    int i;
    char encryptedMessage[1000];

    for (i = 0; i < strlen(message); i++) 
	{
        char currentChar = message[i];

        if (isupper(currentChar)) 
		{
            encryptedMessage[i] = key[currentChar - 'A'];
        }
        else if (islower(currentChar)) 
		{
            encryptedMessage[i] = tolower(key[currentChar - 'a']);
        }     
        else 
		{
            encryptedMessage[i] = currentChar;
        }
    }
    encryptedMessage[i] = '\0';
    printf("Encrypted message: %s\n", encryptedMessage);
}
int main() 
{
    char message[1000];
    char key[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA"; 
   
    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);
 
    if (strlen(message) > 0 && message[strlen(message) - 1] == '\n') 
	{
        message[strlen(message) - 1] = '\0';
    }  
    encryptMonoalphabetic(message, key);
    return 0;
}
