// gcc main.c -o first_rop -fno-stack-protector -z execstack
#include <stdio.h>
#include <stdlib.h>

void hello()
{
    char name[128];

    printf("What is your name (%p)?\n> ", name);
    gets(name);

    printf("Hello %s!\n", name);
}

int main()
{
    FILE* fp;
    
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);

    hello();

    return EXIT_SUCCESS;
}