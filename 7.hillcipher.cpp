#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to decrypt a message using a given key
void decrypt(char ciphertext[], int key) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char original = tolower(ciphertext[i]);
            char decrypted = 'a' + (original - 'a' - key + ALPHABET_SIZE) % ALPHABET_SIZE;
            printf("%c", islower(ciphertext[i]) ? decrypted : toupper(decrypted));
        } else {
            // If the character is not an alphabet letter, print it unchanged
            printf("%c", ciphertext[i]);
        }
    }
}

// Function to calculate the frequency of each letter in a given text
void calculateFrequency(char text[], int frequency[]) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            frequency[tolower(text[i]) - 'a']++;
        }
    }
}

// Function to perform a letter frequency attack on an additive cipher
void letterFrequencyAttack(char ciphertext[], int topN) {
    int key, i, j;
    int frequency[ALPHABET_SIZE] = {0};

    // Calculate the frequency of letters in the ciphertext
    calculateFrequency(ciphertext, frequency);

    // Print the frequencies
    printf("Letter frequencies in the ciphertext:\n");
    for (i = 0; i < ALPHABET_SIZE; i++) {
        printf("%c: %d\n", 'a' + i, frequency[i]);
    }

    // Perform the letter frequency attack for each possible key
    printf("\nPossible plaintexts (in rough order of likelihood):\n");
    for (i = 0; i < ALPHABET_SIZE; i++) {
        key = i;
        printf("\nKey %d:\n", key);

        // Decrypt the ciphertext using the current key
        decrypt(ciphertext, key);
        
        // Calculate the frequency of letters in the decrypted text
        calculateFrequency(ciphertext, frequency);

        // Sort the letters by frequency
        for (j = 0; j < topN; j++) {
            int maxIndex = 0;
            for (int k = 1; k < ALPHABET_SIZE; k++) {
                if (frequency[k] > frequency[maxIndex]) {
                    maxIndex = k;
                }
            }

            // Print the topN most likely letters
            printf("  %c: %d\n", 'a' + maxIndex, frequency[maxIndex]);

            // Set the frequency of the selected letter to 0 to find the next maximum
            frequency[maxIndex] = 0;
        }
    }
}

int main() {
    char ciphertext[1000];
    int topN;

    // Input ciphertext message
    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);

    // Input the number of top possible plaintexts to display
    printf("Enter the number of top possible plaintexts to display: ");
    scanf("%d", &topN);

    // Perform letter frequency attack
    letterFrequencyAttack(ciphertext, topN);

    return 0;
}

