/**
 * @file entity.h
 * @brief Файл з описом функцій для роботи зі структурами
 *
 * @author Sylka Michael
 * @date 23-may-2022
 * @version 1.0
 */
#ifndef entity



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * @brief Структура "Людина"
 *
 */
struct people {
  char *name;
  char *mail_name;
};

/**
 * @brief Структура "Пошта"
 *
 */
struct mail {
  int index;

  int is_mail_note; // 0 - True; 1 - False
  char *msg_theme;
  char *msg_text;

  struct people sender;
  struct people reciever;

  char *format;
};


/**
 * @brief Функція виділення пам'яті для об'єктів
 * 
 * @param array массив структур
 * @param count кількість об'єктів
 */
void create_objects (struct mail *array, int count);


/**
 * @brief Фунція видалення об'єкту за індексом
 * 
 * @param array массив структур
 * @param count кількість об'єктів
 * @param index_for_delete індекс видаляємого об'єктів
 */
void delete_object (struct mail *array, int count, int index_for_delete);


/**
 * @brief Функція пошуку всіх повідомлень від конкретної людини
 *
 * @param msgs об'єкт структури "Пошта"
 * @param count_mails кількість рядків (= кількості повідомлень)
 * @param sender ім'я відправника
 * @param sender_mail адреса поштової скриньки відправника
 * @param msg_line_res результуюча строка з усіма повідомленнями, кожне
 * повідомлення з нового рядку
 */
void msg_find(struct mail *msgs, int count_mails, char *sender, char *sender_mail, char *msg_line_res);


/**
 * @brief Функція сортування об'єктів
 * 
 * @param array массив структур
 * @param count кількість об'єктів
 * @param choise вибір поля користувача
 */
void sorting (struct mail *array, int count, int choise);

/**
 * @brief Під функція для сортування
 *  
 */
void sorting_machine (struct mail *array, int j);



#define entity

#endif