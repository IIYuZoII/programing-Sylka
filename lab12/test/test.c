/**
 * @file test.c
 * @brief Файл з тестом на реалізацію функції визначення транспонованої матриці
 *
 * @author Sylka Michael
 * @date 17-may-2022
 * @version 1.0
 */

#include "../src/lib.h"
#include <check.h>

/**
 * Верифікація роботи функції {@link find_count_words_in_line}
 * на основі вхідних та очікуваних даних
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
START_TEST(test_find_count_words_in_line) {
  char data_a[] = "PFkfeew wepfkw oewofjewf wefwiepfn 113r1 pwinfw pwiefn   "
                  ",,,, qwdq ...  wpefj 1 2 !# *";
  int expected = 8;
  int actual = find_count_words_in_line(data_a);
  ck_assert_int_eq(actual, expected);
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
int main(void) {
  Suite *s = suite_create("Programing");
  TCase *tc_core = tcase_create("Lab-12");

  tcase_add_test(tc_core, test_find_count_words_in_line);
  suite_add_tcase(s, tc_core);

  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}
