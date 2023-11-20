#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

void prepareKey(char *key, char keyTable[SIZE][SIZE]) {
    int k, flag = 0, *dicty;
    dicty = (int *)calloc(26, sizeof(int));
    for (k = 0; k < strlen(key); k++) {
        if (key[k] != 'j')
            dicty[key[k] - 97] = 2;
    }
    dicty['j' - 97] = 1;

    k = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            while (dicty[k] != 0)
                k++;
            keyTable[i][j] = key[k];
            dicty[k] = 1;
            k++;
        }
    }
}

void generateTable(char keyTable[SIZE][SIZE]) {
    char key[SIZE * SIZE];
    printf("Enter the key: ");
    scanf("%s", key);

    int k, flag = 0, *dicty;
    dicty = (int *)calloc(26, sizeof(int));
    for (k = 0; k < strlen(key); k++) {
        if (key[k] != 'j')
            dicty[key[k] - 97] = 1;
    }
    dicty['j' - 97] = 2;

    k = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (dicty[key[k] - 97] == 1) {
                keyTable[i][j] = key[k];
                dicty[key[k] - 97] = 2;
                k++;
            } else {
                for (int x = 0; x < 26; x++) {
                    if (dicty[x] == 0) {
                        keyTable[i][j] = x + 97;
                        dicty[x] = 2;
                        break;
                    }
                }
            }
        }
    }
    free(dicty);
}
void search(char keyTable[SIZE][SIZE], char a, char b, int arr[4]) {
    if (a == 'j')
        a = 'i';
    else if (b == 'j')
        b = 'i';
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (keyTable[i][j] == a) {
                arr[0] = i;
                arr[1] = j;
            } else if (keyTable[i][j] == b) {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

void encrypt(char keyTable[SIZE][SIZE], char *message) {
    int i, a[4];
    for (i = 0; i < strlen(message); i += 2) {
        search(keyTable, message[i], message[i + 1], a);
        if (a[0] == a[2]) {
            message[i] = keyTable[a[0]][(a[1] + 1) % SIZE];
            message[i + 1] = keyTable[a[0]][(a[3] + 1) % SIZE];
        } else if (a[1] == a[3]) {
            message[i] = keyTable[(a[0] + 1) % SIZE][a[1]];
            message[i + 1] = keyTable[(a[2] + 1) % SIZE][a[1]];
        } else {
            message[i] = keyTable[a[0]][a[3]];
            message[i + 1] = keyTable[a[2]][a[1]];
        }
    }
}

int main() {
    char keyTable[SIZE][SIZE];
    generateTable(keyTable);

    printf("\nKey Table:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", keyTable[i][j]);
        }
        printf("\n");
    }

    char message[100];
    printf("\nEnter the message to encrypt: ");
    scanf("%s", message);

    // Make the message of even length
    int len = strlen(message);
    if (len % 2 != 0) {
        message[len] = 'z';
        message[len + 1] = '\0';
    }

    encrypt(keyTable, message);

    printf("\nEncrypted message: %s\n", message);

    return 0;
}

