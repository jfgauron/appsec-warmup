// gcc keepass3.c -o keepass3 -fno-stack-protector -z execstack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int password_index = 0;
static const char* text = "\
Keepass3 is an in-memory password manager. \
It is super secure because\nit encrypts every \
password with a master key.\n";

long ask_int()
{
    long n;
    char buf[32];
    char *end;

    while (1) {
        fgets(buf, sizeof buf, stdin);
        n = strtol(buf, &end, 10);
        if (strlen(buf) > 1 && *end == '\n')
            break;
        printf("Invalid input, try again.\n> ");
    }

    return n;
}

void ask_str(char* result, size_t max_len)
{
    fgets(result, max_len, stdin);
    size_t len = strlen(result);
    if (len > 0 && result[len-1] == '\n')
        result[len-1] = '\0';
}

void xor_str(char* str, char* key, char* result) {
    size_t str_len = strlen(str);
    size_t key_len = strlen(key);
    int i;

    for (i = 0; i < str_len; i++) {
        result[i] = str[i] ^ key[i%key_len];
    }
}

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);

    char passwords[4][64];
    char master_key[64];

    printf("%s\n", text);
    printf("What is your master key?\n> ");
    while (1) {
        ask_str(master_key, 64);
        if (strlen(master_key) > 6) {
            break;
        }
        printf("Your master key is not strong enough. It needs to be longer than 6 characters.\n> ");
    }
    while(1) {
        long choice = -1;
        while (choice < 1 || choice > 3) {
            printf("\nChoose an option:\n");
            printf("1 - Store new password\n");
            printf("2 - Show password\n");
            printf("3 - Quit\n> ");
            choice = ask_int();
        }

        if (choice == 1) {
            char password[64];
            printf("What is your new password?\n> ");
            ask_str(password, 64);
            xor_str(password, master_key, passwords[password_index]);
            printf("Password #%d successfully added at %p.\n", password_index, &(passwords[password_index]));
            password_index += 1;
            continue;
        }

        if (choice == 2) {
            char key[64];
            char password[64];
            printf("Enter master key to decrypt password:\n> ");
            while(1) {
                ask_str(key, 64);
                if (!strncmp(key, master_key, 64))
                    break;
                printf("Wrong master key. Try again.\n> ");
            }
            printf("What is the # of the password you want?\n> ");
            choice = ask_int();
            xor_str(passwords[choice], key, password);
            printf("Password: %s\n", password);
            continue;
        }

        if (choice == 3) {
            break;
        }
    }
}