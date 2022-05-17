/**
 * @file lib.h
 * @brief Файл з описом функції для визначення транспонованої матриці
 *
 * @author Sylka Michael
 * @date 17-may-2022
 * @version 1.0
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/**
 * @brief Максимально допустиме значення строк та колонок матриці
 *
 */
#define MAX_RANGE_FOR_MATRIX 11

/**
 * @brief Мінімально допустиме значення строк та колонок матриці
 *
 */
#define MIN_RANGE_FOR_MATRIX 1

/**
 * @brief Функція зчитує дані з файлу
 *
 * @return int 0 при успішному виконанні або 1 при помилці зчитування
 */
int read_info_from_file();

/**
 * @brief функція для отримання від користувача розмірів матриці
 *
 * @param rows кількість строк
 * @param columns кількість колонок
 * @return int 0 при успішному отриманні данних або 1 при не вірних данних
 */
int printer_scanner(unsigned *rows, unsigned *columns);

/**
 * @brief функція для рандомного визначення числа та його знаку (+ чи -)
 *
 * @param max максимальна границя для рандому
 * @param min мінімальна границя для рандому
 * @param random_temp змінна для визначення знаку рандомно-згенерованого числа
 * @return повертає float число в діапазоні від {@link min @endlink } до {@link
 * max @endlink}
 */
float randomizer(float max, float min, int random_temp);

/**
 * @brief Визначення транспонованої матриці
 *
 * @param matrix згенерована матриця
 * @param matrix_transparent транспонована матриця
 * @param rows кількість строк матриці {@link matrix @endlink}
 * @param columns кількість колонок матриці {@link matrix @endlink}
 */
void get_matrix_transponent(float **matrix, float **matrix_transparent,
                            unsigned rows, unsigned columns);
