// ./make_flag FLAG{d8456accbb7354d1ab8a542e7a96550d} TOP_SECRET
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* data, char* key, char* result)
{
    for (int i = 0; i < strlen(data); i++) {
        result[i] = data[i] ^ key[i % strlen(key)];
    }
}

int main(int argc, char** argv)
{
    char* result;
    int size = 1;

    if (argc < 3) {
        printf("usage: ./make_flag FLAG KEY");
        return EXIT_FAILURE;
    }

    result = malloc(strlen(argv[1]));
    encrypt(argv[1], argv[2], result);

    printf("char flag[] = {0x%x", result[0] & 0xff);
    for (int i = 1; i < strlen(argv[1]); i++) {
        printf(", 0x%x", result[i] & 0xff);
    }
    printf("};");


    free(result);
    return EXIT_SUCCESS;
}