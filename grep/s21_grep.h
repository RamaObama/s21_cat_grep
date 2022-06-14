/**
 *
 * @file s21_grep.c
 * @author Rasuli Ramin (deltajed@student.21-school.ru)
 * @brief
 * @version 0.1
 * @date 2022-06-07
 *
 * @copyright Copyright (c) 2022
 *
 */

/*
 * TODO: implementation flag >> a
 * TODO: 1. Парсер
 */

#ifndef S21_CAT_GREP_GREP_S21_GREP_H_
#define S21_CAT_GREP_GREP_S21_GREP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>

#define BUFF 1024

typedef struct {
  int e;  // Pattern.
  int i;  // Ignore uppercase vs. lowercase.
  int v;  // Invert match.3
  int c;  // Output count of matching lines only.
  int l;  // Output matching files only.
  int n;  // Precede each matching line with a line number.
  int h;  // Output matching lines without preceding them by file names.
  int s;  // Suppress error messages about nonexistent or unreadable files.
  int f;  // Take regexes from a file.
  int o;  // Output the matched parts of a matching line.
} Flags;

void _grep(int argc, char *argv[]);

int _init_flags(Flags *flags);

/**
 * @brief            : Требуется реализовать инициализацию флагов, которые будут определенны после знака '-'
 * @param argv      -- Переданный массив флагов.
 * @param flags      -- стркутра допустимых флагов, которые будут получать true(1) если были переданы.
 *                     через argv
 * @return error    -- возврщаем ошибку, если argv - был получен не допустимый флаг.
 */
int _get_flags(char *argv, Flags *flags);

/** [1]
 * @brief            : Требуется реализоват получение файла, для дальнейшей работы с файлом.
 * @param argc
 * @param argv
 * @param flags
 */
void _get_files(int argc, char *argv[], Flags *flags);



#endif  // S21_CAT_GREP_GREP_S21_GREP_H_
