/**
 * @mainpage
 * # Загальне завдання
 * **Створити** програму для роботи зі структурами даних та файлами
 *
 * @author Sylka Michael
 * @date 18-may-2022
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Точка входу програми
 *
 * @author Sylka Michael
 * @date 18-may-2022
 * @version 1.0
 */

#include "lib.h"

/**
 * Головна функція
 *
 * Послідовність дій:
 * - відкриття файлів
 * - ініціалізація об'єктів структур та масивів
 * - виклики розроблених функцій
 * - закриття файлів
 * - звільнення пам'яті об'єктів структур та масивів
 *
 * @return int 0 при завершенні програми
 */
int main()
{
	int i;
	//Работа с файлами
	FILE *fpInput = fopen("../assets/input.txt", "r");
	FILE *fpOutput = NULL;

	//Кол-во объектов
	int count = get_count_of_lines_in_file(fpInput);

	//Выделение памяти для массивов
	char *buff = (char *)malloc(200 * sizeof(char));
	char *msg_formatted_line = (char *)malloc(200 * sizeof(char));
	char *msg_from_specific_user = (char *)malloc(500 * sizeof(char));
	char *specific_sender = (char *)malloc(50 * sizeof(char));
	char *specific_sender_mail = (char *)malloc(50 * sizeof(char));

	int specific_sender_number = 3;

	//Выделение памяти для структуры
	struct mail *array = (struct mail *)malloc((unsigned long)count * sizeof(struct mail));
	for (i = 0; i < count; i++) {
		(array + i)->msg_text = (char *)malloc(sizeof(char) * 50);
		(array + i)->msg_theme = (char *)malloc(sizeof(char) * 50);
		(array + i)->format = (char *)malloc(sizeof(char) * 50);
		(array + i)->sender.name = (char *)malloc(sizeof(char) * 50);
		(array + i)->sender.mail_name = (char *)malloc(sizeof(char) * 50);
		(array + i)->reciever.name = (char *)malloc(sizeof(char) * 50);
		(array + i)->reciever.mail_name = (char *)malloc(sizeof(char) * 50);
	}

	//Заполнение объекта array данными из файла input.txt
	i = 0;
	while (i < count) {
		fgets(buff, 201, fpInput);

		sscanf(buff, "%d %s %s %s %s %s %s %s", &(array + i)->is_mail_note, (array + i)->msg_theme, (array + i)->msg_text,
		       (array + i)->sender.name, (array + i)->sender.mail_name, (array + i)->reciever.name, (array + i)->reciever.mail_name,
		       (array + i)->format);

		printf("%d\n%s\n", (array + i)->is_mail_note, (array + i)->msg_theme);
		printf("%s\n%s\n%s\n%s\n%s\n%s\n", (array + i)->msg_text, (array + i)->sender.name, (array + i)->sender.mail_name,
		       (array + i)->reciever.name, (array + i)->reciever.mail_name, (array + i)->format);
		i++;
	}

	//Форматирование струткуры в строку
	msg_format((array + 2), msg_formatted_line);

	//Длинна текста сообщения
	msg_lenght(array);

	//Поиск всех сообщений от конкретного юзера
	strcat(specific_sender, (array + specific_sender_number)->sender.name);
	strcat(specific_sender_mail, (array + specific_sender_number)->sender.mail_name);

	//Поиск всех сообщений
	msg_find(array, count, specific_sender, specific_sender_mail, msg_from_specific_user);

	//Длинна всех сообщений
	int c = all_msg_lenght(array, count);

	write(fpInput, msg_formatted_line, msg_from_specific_user, specific_sender, specific_sender_mail, c);

	//Закрытие файлов
	fclose(fpInput);

	//Освобождение памяти массивов
	free(buff);
	free(msg_formatted_line);
	free(msg_from_specific_user);
	free(specific_sender);
	free(specific_sender_mail);

	//Освобождение памяти массива объектов структур
	for (i = 0; i < count; i++) {
		free((array + i)->msg_theme);
		free((array + i)->msg_text);
		free((array + i)->sender.name);
		free((array + i)->sender.mail_name);
		free((array + i)->reciever.name);
		free((array + i)->reciever.mail_name);
		free((array + i)->format);
	}
	free(array);

	return 0;
}