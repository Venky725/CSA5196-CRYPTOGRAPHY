
#include <stdio.h>
#include <stdint.h>

// Function to generate subkeys
void generateSubkeys(uint64_t key, uint64_t* subkeys) {
    uint8_t pc1[56] = {
        57, 49, 41, 33, 25, 17, 9,
        1,  58, 50, 42, 34, 26, 18,
        10, 2,  59, 51, 43, 35, 27,
        19, 11, 3,  60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15,
        7,  62, 54, 46, 38, 30, 22,
        14, 6,  61, 53, 45, 37, 29,
        21, 13, 5,  28, 20, 12, 4
    };

    uint8_t pc2[48] = {
        14, 17, 11, 24, 1,  5,
        3,  28, 15, 6,  21, 10,
        23, 19, 12, 4,  26, 8,
        16, 7,  27, 20, 13, 2,
        41, 52, 31, 37, 47, 55,
        30, 40, 51, 45, 33, 48,
        44, 49, 39, 56, 34, 53,
        46, 42, 50, 36, 29, 32
    };

    // Apply PC-1 permutation to the key
    uint64_t permutedKey = 0;
    for (int i = 0; i < 56; i++) {
        permutedKey <<= 1;
        permutedKey |= (key >> (64 - pc1[i])) & 0x1;
    }

    // Split the permuted key into two 28-bit halves
    uint32_t leftHalf = (uint32_t)(permutedKey >> 28);
    uint32_t rightHalf = (uint32_t)(permutedKey & 0xFFFFFFF);

    // Generate 16 subkeys
    for (int round = 0; round < 16; round++) {
        // Circular left shift the halves
        int shift = (round < 2 || round == 8 || round == 15) ? 1 : 2;
        leftHalf = (leftHalf << shift) | (leftHalf >> (28 - shift));
        rightHalf = (rightHalf << shift) | (rightHalf >> (28 - shift));

        // Combine the halves
        uint64_t combinedHalf = ((uint64_t)leftHalf << 28) | rightHalf;

        // Apply PC-2 permutation to generate the subkey
        uint64_t subkey = 0;
        for (int i = 0; i < 48; i++) {
            subkey <<= 1;
            subkey |= (combinedHalf >> (56 - pc2[i])) & 0x1;
        }

        subkeys[round] = subkey;
    }
}

int main() {
    uint64_t initialKey = 0x0123456789ABCDEF;  // Replace with your desired initial key

    uint64_t subkeys[16];
    generateSubkeys(initialKey, subkeys);

    printf("Generated Subkeys:\n");
    for (int i = 0; i < 16; i++) {
        printf("Subkey %2d: 0x%012lX\n", i+1, subkeys[i]);
    }

    return 0;
}
