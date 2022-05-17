/**
 * @file lib.h
 * @brief Файл з описом функції для введення трикутнику у файл
 *
 * @author Sylka Michael
 * @date 17-may-2022
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Функція для визначення кількості слів у строчці
 *
 * @param f вказівник на файл output.txt
 * @param rows кількість строк (висота трикутника)
 * @param columns кількість колонок (ширина трикутника)
 * @param s символ заповнювач
 * @return int 0 при успішному завершенні або 1 при не вірних данних висоти
 * {@link rows} або ширини {@link columns} трикутника
 */
int write_to_file(FILE *f, int rows, int columns, char *s);