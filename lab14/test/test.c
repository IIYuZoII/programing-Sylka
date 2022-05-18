/**
 * @file test.c
 * @brief Файл з тестами на реалізацію функцій визначення кількості строк у
 * файлі та довжині всіх текстів пошти
 *
 * @author Sylka Michael
 * @date 17-may-2022
 * @version 1.0
 */

#include "../src/lib.h"
#include <check.h>

/**
 * Верифікація роботи функції {@link int get_count_of_lines_in_file(FILE *ptr)}
 * на основі вхідних та очікуваних даних
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
START_TEST(test_get_count_of_lines_in_file)
{
	FILE *data_a = NULL;
	data_a = fopen("assets/input.txt", "r");

	int actual;
	int expected = 6;

	actual = get_count_of_lines_in_file(data_a);
	ck_assert_int_eq(actual, expected);
}
END_TEST

/**
 * Верифікація роботи функції {@link int all_msg_lenght(struct mail *msgs, int
 * rows)} на основі вхідних та очікуваних даних
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
START_TEST(test_all_msg_lenght)
{
	int data_b = 3;
	struct mail *array = (struct mail *)malloc((unsigned long)data_b * sizeof(struct mail));
	for (int i = 0; i < data_b; i++) {
		(array + i)->msg_text = (char *)malloc(sizeof(char) * 50);
		strcat(array->msg_text, "Lorum ipsum");
	}

	int actual;
	int expected = 50;

	actual = all_msg_lenght(array, data_b);
	ck_assert_int_eq(actual, expected);
}

/**
 * Точка входу модуля тестування.
 *
 * Запускає розроблені функції верифікації функцій визначення кількості строк у
 * файлі та довжині всіх текстів пошти
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
	TCase *tc_core = tcase_create("Lab-14");

	tcase_add_test(tc_core, test_get_count_of_lines_in_file);
	suite_add_tcase(s, tc_core);

	tcase_add_test(tc_core, test_all_msg_lenght);
	suite_add_tcase(s, tc_core);

	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? 0 : 1;
}
