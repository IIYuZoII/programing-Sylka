/**
 * @file test.c
 * @brief Файл з тестом на реалізацію функції виділення пам'яті для об'єктів
 *
 * @author Sylka Michael
 * @date 23-may-2022
 * @version 1.0
 */


#include "../src/entity.h"
#include <check.h>


/**
 * @brief Верифікація роботи функції виділення пам'яті для об'єктів
 * на основі вхідних та очікуваних даних
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
 
START_TEST(test_create_objects) {
  int data_b = 3;
  int actual;
  int expected = 0;
  struct mail *data_a = (struct mail *)malloc((unsigned long)data_b * sizeof(struct mail));

  create_objects (data_a, data_b);

  for (int i = 0; i < data_b; i++){
      if ((data_a + i)->format == NULL){
          actual = 1;
      } else {
          actual = 0;
      }

      ck_assert_int_eq(actual, expected);
  }

  free (data_a);
}
END_TEST


/**
 * Точка входу модуля тестування.
 *
 * Запускає розроблені функції верифікації функції створення об'єктів
 *
 * По завершенню тестів виводиться на екран резуміюча інформація про стан
 * проходження тестів.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
int main(void) {
  Suite *s = suite_create("Programing");
  TCase *tc_core = tcase_create("Lab-15");

  tcase_add_test(tc_core, test_create_objects);
  suite_add_tcase(s, tc_core);



  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}
