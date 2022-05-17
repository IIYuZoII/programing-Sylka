/**
 * @file lib.c
 * @brief Файл з реалізацією функції для визначення повторів у масиві та
 * виписування їх
 *
 * @author Sylka Michael
 * @date 17-may-2022
 * @version 1.0
 */

#include "lib.h"

void get_count(int *a, unsigned b, int *r, unsigned *c) {
  unsigned i, j;
  unsigned count_of_unique_numbers = 0, space_count = 0;
  int temp = 0;

  int *temp_arr = NULL;
  temp_arr = (int *)malloc(128);

  //Первичный перебор массива, выписывание всех цифр без их повторов
  for (i = 0; i < b; i++) {
    int my_bool = 0;           // 0 - True, 1 - False
    int switcher = 0;          // 0 -On 1 - Off
    for (j = i; j >= 0; j--) { //Перебор временного массива в обратную сторону
      //Для ситуации с нулями
      if (*(a + i) == 0 && switcher == 0) {
        switcher = 1;
        if (j == 0) {
          break;
        }
        continue;
      }
      if (*(a + i) != *(temp_arr + j)) {
        if (j == 0) {
          break;
        }
        continue;
      } else {
        my_bool = 1;
        break;
      }
    }
    if (my_bool == 0) { //Если цифра уникальная - записываем
      count_of_unique_numbers++;
      *(temp_arr + i - space_count) = *(a + i);
    } else {
      space_count++;
    }
  }

  //Повторный перебор массива + запись в нужном порядке
  for (i = 0; i < (count_of_unique_numbers * 2); i++) {
    if (i % 2 == 0) {
      *(r + i) = *(temp_arr + temp);
      temp++;
    } else {
      int count_of_same_numbers = 0;
      for (j = 0; j < b; j++) {
        if (*(a + j) == *(r + i - 1)) {
          count_of_same_numbers++;
        }
      }
      *(r + i) = count_of_same_numbers;
    }
  }

  *c = count_of_unique_numbers * 2;

  free(temp_arr);
}