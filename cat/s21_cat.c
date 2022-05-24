/**
 *
 * @file s21_cat.c
 * @author Rasuli Ramin (deltajed@student.21-school.ru)
 * @brief Cat is one of the most frequently used commands on Unix-like operating
 * systems. It has three related functions with regard to text files: displaying
 * them, combining copies of them and creating new ones.
 * @version 0.1
 * @date 2022-05-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "s21_cat.h"

/**
 * @brief иницилизируем флаги с первоначальными значениями 0
 * @param flags
 * @return
 */
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
/**
 * @brief Получаем флаги и даем вес что ли если такой флаг существует если нет то ошибка
 *
 * @param flags
 * @param c
 * @return
 */
int getFlags(Flags *flags, char c) {
  int error = 0;
  switch (c) {
    case 'b': flags->b = 1;
      break;
    case 'e': flags->e = 1;
      break;
    case 'E': flags->E = 1;
      break;
    case 'v': flags->v = 1;
      break;
    case 'n': flags->n = 1;
      break;
    case 's': flags->s = 1;
      break;
    case 't': flags->t = 1;
      break;
    case 'T': flags->T = 1;
      break;
    default:printf("cat: invalid option -- '%c'.\nTry 'cat --help' for more information.", c);
      error = 1;
      break;
  }
  return error;
}
/**
 * @brief Получаем структуру флагов и строку с флагами "-s/-sv"
 *
 * @param flags
 * @param str
 * @return
 */
int parserFlags(Flags *flags, char *str) {
  int error = 0;
  // Пропускаем "-"
  ++str;
  while (*str != '\0') {
    if (getFlags(flags, *str)) {
      error = 1;
      break;
    }
    ++str;
  }
  return error;
}
/**
 *
 * @param flags -- структура флагов
 * @param file_name -- имя файла
 * @param dis
 * @param shift сдвиг
 * @return
 */
int getFile(Flags *flags, char *file_name, int dis, int *shift) {
  if (flags->b) flags->n = 0;
  if (flags->e || flags->t) flags->v = 1;
  char temp;
  FILE *file;
  file = fopen(file_name, "r");
  if (file == NULL)
    printf("cat: Can't open '%s': No such file or directory!\n", file_name);
  else
    printf("OK!");
  
  return dis;
}

int main(int args, char *argv[]) {
  int error = 0;
  Flags flags;
  initFlags(&flags);
  for (int i = 1; i < args; i++) {
    if (argv[i][0] == '-') {
      // Тут мы будем проверять флаги которые спарсили.
      if (parserFlags(&flags, argv[i])) {
        error = 1;
        break;
      }
    }
  }
  if (!error) {
    int dis = 1, shift = 1;
    for (int i = 1; i < args; i++) {
      if (argv[i][0] != '-') {
        dis = getFile(&flags, argv[i], dis, &shift);
      }
    }
  }
  return 0;
}