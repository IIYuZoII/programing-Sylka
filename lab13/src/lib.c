/**
 * @file lib.c
 * @brief Файл з реалізацією функції для введення трикутнику у файл
 *
 * @author Sylka Michael
 * @date 17-may-2022
 * @version 1.0
 */

#include "lib.h"

int write_to_file(FILE *f, int rows, int columns, char *s)
{
	int i, j, t = 1, k, tf = 0, space;
	if (rows >= columns || rows == 1) {
		printf("\nIncorrect data, please open program again and write correct data "
		       "(rows < columns & rows > 1)\n");
		return (1);
	}

	if (columns - rows < 2) {
		rows--;
		tf = 1;
	}

	for (i = 1; i <= rows; i++) {
		k = 0;
		for (space = 1; space < columns - i; space++) {
			printf("  ");
			fprintf(f, "  ");
		}

		while (k < t) {
			printf("%c ", *s);
			fprintf(f, "%c ", *s);
			k++;
		}
		t += 2;
		printf("\n");
		fprintf(f, "\n");
	}
	if (t < columns || tf == 1) {
		printf("Program can't write full triangle\n");
		fprintf(f, "Program can't write full triangle");
	} else {
		printf("Completed\n");
	}

	return (0);
}
