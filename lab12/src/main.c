/**
 * @mainpage
 * # Загальне завдання
 * **Створити** програму яка визначає кількість слів у файлі.
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
 * @brief буфер для ініціалізації масиву
 *
 */
#define BUFFER_SIZE 1000

/**
 * Головна функція
 *
 * Послідовність дій:
 * - ініціалізація масивів
 * - зчитування строки з файлу
 * - виклик функції {@link int find_count_words_in_line(char *str)}
 * - виведеня результату у консоль
 * - звільнення пам'яті
 *
 * @return int 0 при завершенні програми
 */
int main() {
  FILE *fPtr;

  char *path = (char *)malloc(100 * sizeof(char));
  char *buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));

  int number_of_words = 0;

  printf("Enter path of source file: ");
  scanf("%s", path);

  //Открытие файла
  fPtr = fopen(path, "r");

  //Если файл не удалось открыть
  if (fPtr == NULL) {
    printf("\nUnable to open file.\n");
    free(path);
    free(buffer);
    return (0);
  }

  //Перебор файла построчно
  while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL) {
    number_of_words += find_count_words_in_line(buffer);
  }

  printf("\nNumber of words in file '%s': \n%d\n", path, number_of_words);

  free(path);
  free(buffer);

  return (0);
}