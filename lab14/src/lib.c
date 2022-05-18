/**
 * @file lib.c
 * @brief Файл з реалізацією функцій для роботи зі структурами та файлами
 *
 * @author Sylka Michael
 * @date 18-may-2022
 * @version 1.0
 */

#include "lib.h"

int get_count_of_lines_in_file(FILE *fPtr)
{
	int count = 0;

	int buffer_size = 200;
	char buffer[200];

	while ((fgets(buffer, buffer_size, fPtr)) != NULL) {
		count++;
	}

	fseek(fPtr, 0, SEEK_SET);

	printf("%d\n", count);
	return (count);
}

void msg_format(struct mail *info_for_msg_f, char *res_line)
{
	char space[] = " ";

	strcat(res_line, info_for_msg_f->sender.name);
	strcat(res_line, space);
	strcat(res_line, info_for_msg_f->reciever.name);
	strcat(res_line, space);
	strcat(res_line, info_for_msg_f->msg_theme);
	strcat(res_line, space);
	strcat(res_line, info_for_msg_f->msg_text);

	printf("Message formatted line is: \n%s\n\n", res_line);
}

void msg_lenght(struct mail *msg)
{
	size_t msg_len;
	msg_len = strlen(msg->msg_text);
	printf("Msg lenght: %lu\n\n", msg_len);
}

void msg_find(struct mail *msgs, int count_mails, char *sender, char *sender_mail, char *msg_line_res)
{
	int res, res2;
	char space[] = "\n";

	for (int i = 0; i < count_mails; i++) {
		res2 = strcmp((msgs + i)->sender.name, sender);
		res = strcmp((msgs + i)->sender.mail_name, sender_mail);
		if (res == 0 && res2 == 0) {
			strcat(msg_line_res, (msgs + i)->msg_text);
			strcat(msg_line_res, space);
		}
	}
	printf("All messages from specific user '%s' '%s': \n%s\n\n", sender, sender_mail, msg_line_res);
}

int all_msg_lenght(struct mail *msgs, int rows)
{
	int count = 0;
	for (int i = 0; i < rows; i++) {
		count += strlen((msgs + i)->msg_text);
	}
	printf("Lenght of all messages in file 'assets/input.txt': %d\n", count);
	return (count);
}

void write(FILE *fPtr, char *msg_formatted_line, char *msg_from_specific_user, char *specific_sender, char *specific_sender_mail, int c)
{
	fPtr = fopen("../assets/output.txt", "w");

	fprintf(fPtr, "Message formatted line is: \n%s\n\n", msg_formatted_line);
	fprintf(fPtr, "All messages from specific user '%s' '%s': \n%s\n\n", specific_sender, specific_sender_mail, msg_from_specific_user);
	fprintf(fPtr, "Lenght of all messages in file 'assets/input.txt': %d", c);

	fclose(fPtr);
}