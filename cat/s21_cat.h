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

#ifndef S21_CAT_GREP_CAT_S21_CAT_H_
#define S21_CAT_GREP_CAT_S21_CAT_H_

#include <stdio.h>

typedef struct {
  int b;  // Нумеровать строки, как и при указании опции -n, но пустые строки не нумеруются.
  int e;  // Выдавать в конце каждой строки символ $ (перед символом новой строки).
  int E;  // Тоже самое, но без -v
  int v;  // Выдавать непечатные символы. Управляющие символы ASCII.
  int n;  // Выдовать порядковый номер строки каждой строки.
  int s;  // Не выдавать сообщений о не существующих файлах.
  int t;  // Выдавать символы табуляции как ^I, а символы прогона страницы - как ^L.
  int T;  // Тоже самое, но без -v
} Flags;

int initFlags(Flags *flags);

#endif //S21_CAT_GREP_CAT_S21_CAT_H_
