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

int main() {
  int error = 0;
  Flags flags;
  initFlags(&flags);
  return error;
}