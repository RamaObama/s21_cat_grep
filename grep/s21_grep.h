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
 * TODO:
 */

#ifndef S21_CAT_GREP_GREP_S21_GREP_H_
#define S21_CAT_GREP_GREP_S21_GREP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF 1024

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
  OK = 0,
  FAIL = 1,
  FLAG_DOES_NOT_EXIST = 2,
  FAIL_DOES_NOT_EXIST = 3
};

int initFlags(Flags *flags);

int countFiles(char *file_names[]);

int getFlags(Flags *flags, int argc, char *argv[], char *file_names[], char *patterns[]);

int parserFlags(Flags *flags, int argc, char *argv[]);

void grep(int count);

#endif  // S21_CAT_GREP_GREP_S21_GREP_H_
