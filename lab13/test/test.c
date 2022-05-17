/**
 * @file test.c
 * @brief Файл з тестом на реалізацію функції для запису трикутника у файл
 *
 * @author Sylka Michael
 * @date 17-may-2022
 * @version 1.0
 */

#include "../src/lib.h"
#include <check.h>

/**
 * Верифікація роботи функції {@link int write_to_file(FILE *f, int rows, int
 * columns, char *s)} на основі вхідних та очікуваних даних
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
START_TEST(test_write_to_file)
{
	FILE *fpt = NULL;
	char c[1];
	int data_a[] = { 1, 4, 3 };
	int data_b = 3;

	int actual;
	int expected = 1;
	for (int i = 0; i < 3; i++) {
		actual = write_to_file(fpt, data_a[i], data_b, &c[0]);
		ck_assert_int_eq(actual, expected);
	}
}
END_TEST

/**
 * Точка входу модуля тестування.
 *
 * Запускає розроблену функцію верифікації функції визначення кількості слів у
 * строчці
 *
 * По завершенню тестів виводиться на екран резуміюча інформація про стан
 * проходження тестів.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
int main(void)
{
	Suite *s = suite_create("Programing");
	TCase *tc_core = tcase_create("Lab-13");

	tcase_add_test(tc_core, test_write_to_file);
	suite_add_tcase(s, tc_core);

	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? 0 : 1;
}
