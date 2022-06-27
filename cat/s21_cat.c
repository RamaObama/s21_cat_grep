/**
 *
 * @file s21_cat.c
 * @author Rasuli Ramin (deltajed@student.21-school.ru)
 * @brief Cat is one of the most frequently used commands on Unix-like operating
 * systems. It has three related functions with regard to text files: displaying
 * them, combining copies of them and creating new ones.
 * @version 1.0
 * @date 2022-05-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "s21_cat.h"

int main(int argc, char *argv[]) {
    if (argc > 1)
        cat(argc, argv);
    else
        printf("cat: flags empty and file...");
    return 0;
}

int initFlags(Flags *flags) {
    flags->b = 0;
    flags->e = 0;
    flags->E = 0;
    flags->v = 0;
    flags->n = 0;
    flags->s = 0;
    flags->t = 0;
    flags->T = 0;
    return 1;
}

void cat(int argc, char *argv[]) {
    Flags flags;
    initFlags(&flags);

    int error = 0;
    int i = 1;
    for (; i < argc; ++i) {
        if (strspn(argv[i], "-") == 0) break;
        if (getFlags(argv[i], &flags) == 1) error = 1;
    }
    if (flags.b) flags.n = 0;
    if (!error && i == argc) {
        printf("cat: please input filename...");
    }
    for (; !error && i < argc; ++i) {
        FILE *file_name = fopen(argv[i], "r");
        if (file_name) {
            int start_line = 1;
            // count line for flags->b -- numbers only no-empty lines
            int count_empty_line = 1;
            // count line for flags->n -- number all output lines
            int count_all_line = 1;
            char previous_char = '\n';
            char next_char = ' ';
            char ch[1024] = {'\0'};

            while ((*ch = fgetc(file_name)) != EOF) {
                if (flags.s && handle_flag_s(previous_char, next_char, *ch)) continue;
                if (flags.n) start_line = handle_flag_n(start_line, &count_all_line, *ch);
                if (flags.b) handle_flag_b(previous_char, &count_empty_line, *ch);
                if (flags.E) handle_flag_E(*ch);
                if (flags.v) handle_flag_v(ch);
                next_char = previous_char;
                previous_char = *ch;
                if (flags.T && handle_flag_T(*ch)) continue;
                if (*ch == '\0')
                    fputc(*ch, stdout);
                else
                    fputs(ch, stdout);
                memset(ch, '\0', 1024);
            }
        } else {
            printf("cat: Can't open '%s': No such file or directory!\n", argv[i]);
        }
        fclose(file_name);
    }
    if (error)
        printf("cat: illegal option -- '%s'.\nTry 'man cat' for more information.",
               argv[i - 1]);
}

int handle_flag_b(char previous_char, int *count_empty_line, char ch) {
    if (previous_char == '\n' && ch != '\n')
        printf("%6d\t", (*count_empty_line)++);
    return ch == '\n';
}

int handle_flag_v(char *ch) {
    unsigned char tmp = *ch; // 124
    if ((tmp <= 8) || (tmp >= 11 && tmp <= 31) || (tmp >= 127 && tmp <= 159))
        strcpy(ch, special_symbol[tmp]);
    return tmp;
}

int handle_flag_E(char ch) {
    if (ch == '\n') printf("$");
    return ch == '\n';
}

int handle_flag_n(int start_line, int *count_all_line, char ch) {
    if (start_line) printf("%6d\t", (*count_all_line)++);
    return ch == '\n';
}

int handle_flag_s(char previous_char, char next_char, char ch) {
    return ch == '\n' && previous_char == '\n' && next_char == '\n';
}

int handle_flag_T(char ch) {
    int tab = 0;
    if (ch == '\t') tab = printf("^I");
    return tab;
}

int getFlags(char *argv, Flags *flags) {
    int error = 0;
    if (strlen(argv) == 1 || strlen(argv) != strspn(argv, "-bvEnsTet")) error = 1;
    if (!strcmp(argv, "--number")) {
        error = 0;
        flags->n = 1;
    }
    else if (!strcmp(argv, "--number-nonblank")) {
        error = 0;
        flags->b = 1;
    }
    else if (!strcmp(argv, "--squeeze-blank")) {
        error = 0;
        flags->s = 1;
    } else {
        if (strchr(argv, 'b')) flags->b = 1;
        if (strchr(argv, 'e')) {
            flags->v = 1;
            flags->E = 1;
        }
        if (strchr(argv, 'E')) flags->E = 1;
        if (strchr(argv, 'v')) flags->v = 1;
        if (strchr(argv, 'n')) flags->n = 1;
        if (strchr(argv, 's')) flags->s = 1;
        if (strchr(argv, 't')) {
            flags->v = 1;
            flags->T = 1;
        }
        if (strchr(argv, 'T')) flags->T = 1;
    }
    return error;
}
