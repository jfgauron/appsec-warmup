#include <stdio.h>
#include <stdlib.h>

int hello()
{
    struct {
        char name[32];
        int show_flag;
    } data;

    data.show_flag = 0;

    printf("What is your name?\n> ");
    gets(data.name);

    printf("Hello %s!\n", data.name);

    return data.show_flag;
}

int main()
{
    FILE* fp;
    char flag[64];
    int show_flag = 0;
    
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);

    show_flag = hello();
    if (show_flag == 0xcafebabe) {
        fp = popen("cat /flag", "r");
        while((fgets(flag, sizeof(flag), fp))) {
            printf("%s\n", flag);
        }
    }

    return EXIT_SUCCESS;
}