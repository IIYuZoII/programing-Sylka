/**
 * @mainpage
 * # Загальне завдання
 * **Створити** програму яка визначає кількість повторів елементів у масиві.
 * Використовувати показжики при роботi з масивами
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
#include <time.h>

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - створення масивів
 * - генерація даних для масиву
 * - визначення кількості повторів чисел за допомогою функції
 * {@link get_count}
 * - звільнення пам'яті
 * @return успішний код повернення з програми (0)
 */

int main() {
  int *arr = NULL;
  int *res = NULL;

  unsigned var_for_cut, i, size = 9;

  arr = (int *)malloc(size * sizeof(int));
  res = (int *)malloc(128);

  srand((unsigned)time(NULL));
  for (i = 0; i < size; i++) {
    *(arr + i) = (int)rand() % 100;
  }

  get_count(arr, size, res, &var_for_cut);

  res = (int *)realloc(res, var_for_cut * sizeof(int)); //Обрезка массива

  free(arr);
  free(res);

  return 0;
}