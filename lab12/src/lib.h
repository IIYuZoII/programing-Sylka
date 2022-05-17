/**
 * @file lib.h
 * @brief Файл з описом функції для визначення кількості слів у строчці
 *
 * @author Sylka Michael
 * @date 17-may-2022
 * @version 1.0
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Функція для визначення кількості слів у строчці
 *
 * @param str строка зчитана з файлу
 * @return int кількість слів
 */
int find_count_words_in_line(char *str);