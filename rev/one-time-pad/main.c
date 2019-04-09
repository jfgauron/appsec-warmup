#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decrypt(char* data, char* key, char* result)
{
    for (int i = 0; i < strlen(data); i++) {
        result[i] = data[i] ^ key[i % strlen(key)];
    }
}

int main()
{
    char flag[64];
    char* key = "TOP_SECRET";

    char target[] = {
        0x12, 0x3, 0x11, 0x18, 0x28, 0x21, 0x7b, 0x66, 0x70, 0x62, 0x35,
        0x2c, 0x33, 0x3d, 0x31, 0x72, 0x70, 0x67, 0x71, 0x30, 0x65, 0x2e,
        0x32, 0x67, 0x32, 0x70, 0x77, 0x60, 0x20, 0x63, 0x35, 0x76, 0x66,
        0x6a, 0x66, 0x75, 0x27, 0x2f
    }; 

    printf("What is the flag?\n");
    fgets(flag, sizeof(flag), stdin);
    decrypt(flag, key, flag);

    if (strncmp(flag, target, sizeof(target)) == 0) {
        printf("Correct!\n");
    } else {
        printf("Wrong.\n");
    }

    return EXIT_SUCCESS;
}