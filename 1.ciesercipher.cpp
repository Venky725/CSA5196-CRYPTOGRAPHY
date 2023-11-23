#include<stdio.h>
#include<ctype.h>
#define ALPHABET_SIZE 26
void caesarCipher(char message[], int key)
{
	
	int i=0;
	char ch;
	while(message[i]!='\0')
	{
    	ch=message[i];
    	if(isalpha(ch))
		{
    		char base=islower(ch)?'a':'A';
    		message[i]=(ch-base+key)%
			ALPHABET_SIZE+base;
		} 
		   i++;
    }
}

int main() {
    char message[100];
    int key, i;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the key value (1-25): ");
    scanf("%d", &key);

    
    caesarCipher(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}
