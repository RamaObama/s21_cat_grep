#include "s21_grep.h"

int main(int argc, char *argv[]) {
    if (argc > 2)
        _grep(argc, argv);
    else
        printf("grep: flags empty and file...");
    return 0;
}
// [_grep]
void _grep(int argc, char *argv[]) {
    Flags flags;
    _init_flags(&flags);

    int error = 0;
    int i = 1;
    for (; i < argc; i++) {
        if (strspn(argv[i], "-") == 0) {
            break;
            if (_get_flags(argv[i], &flags)) error = 1;
            // TODO: Потом добавить проверку, если есть какие-то флаги для паттернов.
        }
        if (_get_flags(argv[i], &flags) == 1) error = 1;
        _get_files(argc, argv, &flags);
    }
    // TODO: Если нет флага E и F. то что мы делаем?

    if (error)
        printf("usage: grep [-abcDEFGHhIiJLlmnOoqRSsUVvwxZ] [-A num] [-B num] [-C[num]]\n"
               "\t[-e pattern] [-f file] [--binary-files=value] [--color=when]\n"
               "\t[--context[=num]] [--directories=action] [--label] [--line-buffered]\n"
               "\t[--null] [pattern] [file ...]");
}
// [0]
int _init_flags(Flags *flags) {
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
// [1]
int _get_flags(char *argv, Flags *flags) {
    int error = 0;
    if (strlen(argv) == 1 || strlen(argv) != strspn(argv, "-eivclnhsfo")) error = 1;
    // TODO: Проверить парсинг с множественным флагом Е
    if (strchr(argv, 'e')) flags->e = 1;
    if (strchr(argv, 'i') && flags->e == 0 && flags->f == 0) flags->i = 1;
    if (strchr(argv, 'v') && flags->e == 0 && flags->f == 0) flags->v = 1;
    if (strchr(argv, 'c') && flags->e == 0 && flags->f == 0) flags->c = 1;
    if (strchr(argv, 'l') && flags->e == 0 && flags->f == 0) flags->l = 1;
    if (strchr(argv, 'n') && flags->e == 0 && flags->f == 0) flags->n = 1;
    if (strchr(argv, 'h') && flags->e == 0 && flags->f == 0) flags->h = 1;
    if (strchr(argv, 's') && flags->e == 0 && flags->f == 0) flags->s = 1;
    // TODO: Проверить парсинг с множественным флагом F
    if (strchr(argv, 'f')) flags->f = 1;
    if (strchr(argv, 'o') && flags->e == 0 && flags->f == 0) flags->o = 1;

    return error;
}

// [2]
void _get_files(int argc, char *argv[], Flags *flags) {
    int count_file = 0;

}

// [2] --> [3]

int _count_files(int argc, char *argv[], Flags *flags) {

    return 0;
}