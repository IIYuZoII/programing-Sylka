/**
 * @file lib.h
 * @brief Файл з описом функцій для роботи зі структурами та файлами
 *
 * @author Sylka Michael
 * @date 18-may-2022
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	int is_mail_note; // 0 - True; 1 - False
	char *msg_theme;
	char *msg_text;

	struct people sender;
	struct people reciever;

	char *format;
};

/**
 * @brief Функція для визначення кількості рядків у заданому файлі
 *
 * @param ptr показжик на файл
 * @return int кількість рядків у файлі
 */
int get_count_of_lines_in_file(FILE *ptr);

/**
 * @brief Функція для форматування повідомлення
 *
 * @param info_for_msg_f об'єкт структури "Пошта"
 * @param res_line вихідна результуюча строка
 */
void msg_format(struct mail *info_for_msg_f, char *res_line);

/**
 * @brief Функція визначення довжини повідомлення
 *
 * @param msg об'єкт структурі "Пошта"
 */
void msg_lenght(struct mail *msg);

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
 * @brief Функція визначення довжини всіх повідомлень
 *
 * @param msgs об'єкт структури "Пошта"
 * @param rows кількість рядків (= кількості повідомлень)
 * @return int довжина всіх повідомлень
 */
int all_msg_lenght(struct mail *msgs, int rows);

/**
 * @brief Функція запису у файл
 *
 * @param fPtr показжик на файл
 * @param msg_formatted_line відформатована строка
 * @param msg_from_specific_user усі повідомлення від конкретної людини
 * @param specific_sender ім'я конкретної людини
 * @param specific_sender_mail адреса поштової скриньки конкретної людини
 * @param c довжина всіх повідомлень
 */
void write(FILE *fPtr, char *msg_formatted_line, char *msg_from_specific_user, char *specific_sender, char *specific_sender_mail, int c);