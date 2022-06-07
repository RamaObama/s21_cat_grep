#include "s21_grep.h"

int main(int argc, char *argv[]) {
    Flags flags;
    initFlags(&flags);
    int error = OK;
    char *file_names[BUFF] = {NULL};
    char *patterns[BUFF] = {NULL};

    if (getFlags(&flags, argc, argv, file_names, patterns))
        error = OK;
    else
        error = FAIL;

    return error;
}

int initFlags(Flags *flags) {
    flags->e = 0;
    flags->i = 0;
    flags->v = 0;
    flags->c = 0;
    flags->l = 0;
    flags->n = 0;
    flags->h = 0;
    flags->s = 0;
    flags->f = 0;
    flags->o = 0;
    return 0;
}

int getFlags(Flags *flags, int argc, char *argv[], char *file_names[], char *patterns[]) {
    int error = OK;
    int file = 0;
    int pattern = 0;

    for (int i = 0; i < argc; i++) {
        if (parserFlags(flags, argc, &argv[argc])) {

        }
    }

    return error;
}

int parserFlags(Flags *flags, int argc, char *argv[]) {
    int error = OK;
    if (*argv[0] == '-') {
        for (int i = 1; *argv[i]; i++) {
            if (strcmp(argv[i], "e"))
                flags->e = 1;
            if (strcmp(argv[i], "i"))
                flags->i = 1;
            if (strcmp(argv[i], "v"))
                flags->v = 1;
            if (strcmp(argv[i], "c"))
                flags->c = 1;
            if (strcmp(argv[i], "l"))
                flags->l = 1;
        }
    } else {
        error = FAIL;
    }
    return error;
}
