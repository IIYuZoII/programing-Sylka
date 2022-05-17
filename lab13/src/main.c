/**
 * @mainpage
 * # Загальне завдання
 * **Створити** програму яка вписує у файл трикутник за заданими значеннями в
 * іншому файлі.
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
 * Головна функція
 *
 * Послідновність дій:
 *  - відкриття файлу з даними
 *  - зчитування даних з файлу з даними
 *  - закриття файлу з даними
 *  - відкриття або створення вихідного файлу
 *  - виклик функції {@link int write_to_file(FILE *f, int rows, int columns,
 * char *s)} для запису трикутника у вихідний файл
 *  - закриття вихідного файлу
 * @return int 0 при завершенні програми
 */
int main()
{
	int rows, columns;

	char path[20] = "../assets/input.txt";
	char path2[] = "../assets/output.txt";
	char *symbol = (char *)malloc(1 * sizeof(char));

	FILE *fPtr;
	FILE *fPtrOutFile;

	fPtr = fopen(path, "r");
	//   fseek(fPtr, 0, SEEK_END);
	//   long buff_size = ftell(fPtr);
	//   fseek(fPtr, 0, SEEK_SET);

	fscanf(fPtr, "%d%d%s", &rows, &columns, symbol);
	fclose(fPtr);

	fPtrOutFile = fopen(path2, "w");

	int a = write_to_file(fPtrOutFile, rows, columns, symbol);
	if (a == 1) {
		printf("Closing program...\n\n");
	}

	free(symbol);
	fclose(fPtrOutFile);

	return (0);
}