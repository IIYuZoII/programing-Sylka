/**
 * @mainpage
 * # Загальне завдання
 * **Створити** програму яка визначає транспоновану матрицю.
 *
 * @author Sylka Michael
 * @date 17-may-2022
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Точка входу програми
 *
 * @author Sylka Michael
 * @date 17-may-2022
 * @version 1.0
 */

#include "lib.h"

/**
 * @brief Головна функція
 *
 * Послідовність дій:
 * - виклик функції для зчитування данних про автора з файлу
 * - виклик функції для отримання данних про матрицю від користувача
 * - ініціалізація масиву-матриці
 * - виклик функції для визначення транспонованої матриці
 * - звільнення пам'яті динамічних масивів
 *
 * @return int 0 при закінченні роботи програми
 */
int main() {
  unsigned rows = 0;
  unsigned columns = 0;
  unsigned i, j;

  float **matrix = NULL;
  float **matrix_transparent = NULL;

  float max = 1000, min = -1000;
  int random_temp = 0;

  if (read_info_from_file() == 1) {
    return (0);
  }

  if (printer_scanner(&rows, &columns) == 1) {
    return (0);
  }

  srand((unsigned)time(NULL));
  // Initialize matrixs
  matrix = (float **)malloc(rows * sizeof(float *));
  for (i = 0; i < rows; i++) {
    *(matrix + i) = (float *)malloc(columns * sizeof(float));
    for (j = 0; j < columns; j++) {
      random_temp =
          rand() % 2; // 0 - число будет положительное, 1 - отрицательное
      *(*(matrix + i) + j) = randomizer(max, min, random_temp);
    }
  }

  matrix_transparent = (float **)malloc(columns * sizeof(float *));
  for (i = 0; i < columns; i++) {
    *(matrix_transparent + i) = (float *)malloc(rows * sizeof(float));
  }

  get_matrix_transponent(matrix, matrix_transparent, rows, columns);

  // Free memory
  for (i = 0; i < rows; i++) {
    free(*(matrix + i));
  }
  free(matrix);

  for (i = 0; i < columns; i++) {
    free(*(matrix_transparent + i));
  }
  free(matrix_transparent);

  return (0);
}