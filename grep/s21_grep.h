/**
 *
 * @file s21_grep.c
 * @author Rasuli Ramin (deltajed@student.21-school.ru)
 * @brief
 * @version 1.0
 * @date 2022-06-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef S21_CAT_GREP_GREP_S21_GREP_H_
#define S21_CAT_GREP_GREP_S21_GREP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define BUFF 8192

typedef struct {
  int e;  // Pattern.
  int i;  // Ignore uppercase vs. lowercase.
  int v;  // Invert match.
  int c;  // Output count of matching lines only.
  int l;  // Output matching files only.
  int n;  // Precede each matching line with a line number.
  int h;  // Output matching lines without preceding them by file names.
  int s;  // Suppress error messages about nonexistent or unreadable files.
  int f;  // Take regexes from a file.
  int o;  // Output the matched parts of a matching line.
} Flags;

enum {
  SUCCESS,
  FILE_DOES_NOT_EXIST,
  FLAG_DOES_NOT_EXIST,
  MALLOC_ERROR
};

/**
 * @brief            :
 * @param argc      --
 * @param argv      -- Получаем массив аргументов, для работы.
 */
void _grep(Flags *flags, char *file_name, char *pattern[], int count_file);

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

/**
 * @brief            : Количество файлов, для флага 'f'
 * @param file_name
 * @return count    -- возвращаем количество файлов.
 */
int _get_count_files(char *file_name[]);

int _get_args(int argc, char *argv[], char *file_name[], char *pattern[], Flags *flags);

int _check_flags_exist(char *argv);

/**
 * @brief
 * @param flags
 */
void _reset_flag_e_and_f(Flags *flags);

int _handle_flag_f(char *file_name, char *patterns[], int *index);

/**
 * @brief           :
 * @param linep
 * @param pattern
 * @param matches
 * @param flags
 * @return
 */
int _pattern_matching(const char *const linep, char *pattern[], char *matches[], const Flags *flags);

/**
 * @brief               : Печатаем название файла, если их больше 1 и нет флагов 'c' и 'h'
 * @param file_name
 * @param count_file
 * @param flags
 */
void _handle_header(char *file_name, int count_file, Flags *flags);

void _handle_flag_n(int count_line, Flags *flags);

void _handle_header_flag_c(Flags *flags, char *file_name, int count_file);

void _handle_flag_c(Flags *flags, int count_matched_lines);

void _handle_flag_l(Flags *flags, char *file_name, int count_matched_lines);
#endif  // S21_CAT_GREP_GREP_S21_GREP_H_
