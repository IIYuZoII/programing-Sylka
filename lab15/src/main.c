/**
 * @mainpage
 * # Загальне завдання
 * **Створити** програму для роботи зі структурами даних та файлами
 *
 * @author Sylka Michael
 * @date 23-may-2022
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Точка входу програми
 *
 * @author Sylka Michael
 * @date 23-may-2022
 * @version 1.0
 */

#include "entity.h"
#include "list.h"


/**
 * @brief Головна функція 
 * 
 * Послідовність дій:
 * - Виділення пам'яті
 * - Взаємодія з користувачем та робота зі структурами на базі отриманих даних від користувача
 * - Звільнення пам'яті
 * @return int 0 при завершенні програми
 */
int main() {
  int k = 0;

  int count, count_of_added_elements, choice_for_delete, index_for_delete, choice;

  char *senderName = (char *)malloc(50 * sizeof(char));
  char *senderMailName = (char *)malloc(50 * sizeof(char));
  char *all_msgs = (char *)malloc(50 * sizeof(char));


  printf("Введите кол-во элементов: ");
  scanf("%d", &count);

  struct mail *array = (struct mail *)malloc((unsigned long)count * sizeof(struct mail));
  create_objects (array, count);


  printf("\nВведите данные элементов:\n\n");
  printer_scanner(array, k, count);


  printf ("\nТекущий список элементов:\n");
  printer (array, count);


  printf("\nВы хотите добавить элемнты?\n0 - Нет\n1 - Да\n");
  scanf ("%d", &choice);
  if (choice == 1){
    printf("\nВведите кол-во новых элементов: \n");
    scanf("%d", &count_of_added_elements);
    count +=  count_of_added_elements;

    if (count_of_added_elements > 0){
      array = (struct mail *)realloc(array, (unsigned long)count * sizeof(struct mail));
      create_objects (array, count);
    }

    k = count - count_of_added_elements;
    printer_scanner(array, k, count);

    printf ("\nТекущий список элементов после добавления новых:\n");
    printer (array, count);
  }


  if (count > 1){
    printf ("Вы хотите удалить элемент?\n0 - Нет\n1 - Да\n");
    scanf ("%d", &choice);
    if (choice == 1){
      printf ("Введите индекс удаляемого объекта: ");
      scanf ("%d", &index_for_delete);

      while (index_for_delete > count - 1){
        printf ("\nВведённый индекс больше чем максимальный: %d\nПопробуйте сноа: ", (count - 1));
        scanf ("%d", &index_for_delete);
      }

      delete_object (array, count, index_for_delete);
      count--;
      array = (struct mail *)realloc(array, (unsigned long)count * sizeof(struct mail));

      printf ("Список объектов после удаления элемента с индексом '%d'\n", index_for_delete);
      printer (array, count);
    }
  }
  

  
  if (count > 1){
    printf ("Вы хотите отсортировать элементы?\n0 - Нет\n1 - Да\n");
    scanf ("%d", &choice);
    if (choice == 1){
      printf ("\nВыберите за каким полем сортировать: \n1 - Имя отправителя \n2 - Почта отправителя \n3 - Имя получателя \n4 - Почта получателя\n");
      scanf ("%d", &choice);
      
      sorting (array, count, choice);

      printf ("Результат сортировки:\n");
      printer (array, count);
    }
  }


  if (count > 1){
    printf ("Вы хотите вывести все сообщения от конкретного пользователя?\n0 - Нет\n1 - Да\n");
    scanf ("%d", &choice);
    if (choice == 1){
      printf ("\nВведите имя отправителя:\n");
      scanf ("%s", senderName);
      printf ("\nВведите адрес почты:\n");
      scanf ("%s", senderMailName);

      msg_find (array, count, senderName, senderMailName, all_msgs);
    }
  }



  free (senderName);
  free (senderMailName);
  free (all_msgs);
  for (int i = 0; i < count; i++) {
    free((array + i)->msg_theme);
    free((array + i)->msg_text);
    free((array + i)->sender.name);
    free((array + i)->sender.mail_name);
    free((array + i)->reciever.name);
    free((array + i)->reciever.mail_name);
    free((array + i)->format);
  }
  free (array);

  return (0);
}