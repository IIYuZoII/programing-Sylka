/**
 * @file list.с
 * @brief Файл з реалізацією функцій для механізму вводу/виведення
 *
 * @author Sylka Michael
 * @date 23-may-2022
 * @version 1.0
 */


#include "list.h"


void printer_scanner(struct mail *array, int k, int count) {
  for (int i = k; i < count; i++) {
    printf("Сообщение черновик? (0 - да, 1 - нет):\n");
    scanf("%d", &((array + i)->is_mail_note));

    printf("Тема сообщения:\n");
    scanf("%s", ((array + i)->msg_theme));

    printf("Текст сообщения (в данной версии программы ограничение в 150 символов)\n");
    read (1, (array + i)->msg_text, 151);

    printf("Имя отправителя:\n");
    scanf("%s", ((array + i)->sender.name));
    
    printf("Адрес почты отправителя:\n");
    scanf("%s", ((array + i)->sender.mail_name));
    
    printf("Имя получателя:\n");
    scanf("%s", ((array + i)->reciever.name));
    
    printf("Адрес почты получателя:\n");
    scanf("%s", ((array + i)->reciever.mail_name));
    
    printf("Формат текста:\n");
    scanf("%s", ((array + i)->format));

    printf("\n");
  }
}

void printer (struct mail *array, int count){
    int i = 0;
    while (i < count) {
    printf ("\nИндекс элемента: %d\nТип письма (черновик 0; чистовик 1):\n%d\n\nТема письма:\n%s\n\nПисьмо:\n%s\nИмя отправителя:\n%s\n\nПочта отправителя:\n%s\n\nИмя получателя:\n%s\n\nПочта получателя\n%s\n\nФормат:\n%s\n\n", 
            (array+ i)->index, 
            (array + i)->is_mail_note, 
            (array + i)->msg_theme,
            (array + i)->msg_text,
            (array + i)->sender.name,
            (array + i)->sender.mail_name,
            (array + i)->reciever.name,
            (array + i)->reciever.mail_name,
            (array + i)->format);
    i++;
  }
}
