#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

char func1(char val, char delta) {
    return val + delta;
}

char func2(char val, char delta) {
    return val - delta;
}

char func3(char val, char delta) {
    return val ^ delta;
}

char func4(char val, char delta) {
    val = func1(val, 5);
    val = func2(val, 10);
    return val;
}

int main(int argc, char** argv)
{
    char snum[5];
    int *funcs, *deltas;
    int depth;
    FILE *ef, *df;

    if (argc < 2) {
        printf("usage: ./make_challenge DEPTH\n");
        return EXIT_FAILURE;
    }

    depth = atoi(argv[1]);
    ef = fopen("encrypt.c", "w");
    df = fopen("decrypt.c", "w");
    funcs  = malloc(sizeof(int) * depth);
    deltas = malloc(sizeof(int) * depth);
    srand(time(NULL));

    fprintf(ef, "\
#include <stdio.h>\n\
#include <stdlib.h>\n\
\n\
char func1(char val, char delta) {\n\
    return val + delta;\n\
}\n\
\n\
char func2(char val, char delta) {\n\
    return val - delta;\n\
}\n\
\n\
char func3(char val, char delta) {\n\
    return val ^ delta;\n\
}\n\
\n\
");

    fprintf(df, "\
#include <stdio.h>\n\
#include <stdlib.h>\n\
\n\
char func1(char val, char delta) {\n\
    return val - delta;\n\
}\n\
\n\
char func2(char val, char delta) {\n\
    return val + delta;\n\
}\n\
\n\
char func3(char val, char delta) {\n\
    return val ^ delta;\n\
}\n\
\n\
");

    for (int i = 0; i < depth; i++) {
        snprintf(snum, sizeof(snum), "%d", i+4);
        fprintf(ef, "char func%s(char val, char delta) {\n", snum);
        fprintf(df, "char func%s(char val, char delta) {\n", snum);
        for (int j = 0; j < depth; j++) {
            deltas[j] = rand() % 255;
            funcs[j]  = 1 + (rand() % (i+3));
            snprintf(snum, sizeof(snum), "%d", funcs[j]);
            fprintf(ef, "\tval = func%s(val, %d);\n", snum, deltas[j]);
        }
        fprintf(ef, "\treturn val;\n}\n\n");

        for (int j = depth-1; j >= 0; j--) {
            snprintf(snum, sizeof(snum), "%d", funcs[j]);
            fprintf(df, "\tval = func%s(val, %d);\n", snum, deltas[j]);
        }
        fprintf(df, "\treturn val;\n}\n\n");

    }

    snprintf(snum, sizeof(snum), "%d", depth+3);
    fprintf(ef, "int main() {\n\tchar a = 0x41;\n\ta = func%s(a, 70);\n\tprintf(\"%%d\\n\",a);\n\treturn 1;\n}\n", snum);

    free(funcs);
    free(deltas);
    return EXIT_SUCCESS;
}