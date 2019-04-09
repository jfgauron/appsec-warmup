// ./make_flag FLAG{d33354b82767aaf5b87ae48f724049cf}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* data, char* result)
{
    int k = 0;

    for (int i = 0; i < strlen(data); i++) {
        result[k++] = data[i];
        for (int j = 0; j < data[i]; j++) {
            result[k++] = (rand() % 255) & 0xff;
        }
    }
}

int main(int argc, char** argv)
{
    char* result;
    int size = 1;

    if (argc < 2) {
        printf("usage: ./make_flag FLAG");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < strlen(argv[1]); i++) {
        size += argv[1][i] + 1;
    }



    result = malloc(size);
    encrypt(argv[1], result);

    printf("char flag[] = {0x%x", result[0] & 0xff);
    for (int i = 1; i < size; i++) {
        printf(", 0x%x", result[i] & 0xff);
    }
    printf("};");


    free(result);
    return EXIT_SUCCESS;
}