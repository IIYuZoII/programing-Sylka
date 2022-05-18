# Лабораторна робота №14. Структуровані типи даних

## 1 Вимоги

### 1.1 Розробник

* Силка Михайло Миколайович;
* студент групи КН-921Г;
* 18-тра-2022.

### 1.2 Загальне завдання

Розробити програму для роботи зі структурами даних 

### 1.3 Індивідуальне завдання

Створити структуру даних "Пошта"
• розробити функцію, яка читає дані (масив елементів) з файлу;
• розробити функцію, яка записує дані (масив елементів) у файл;
• розробити функцію, яка виводить масив елементів на екран.

## 2 Опис програми

### 2.1 Функціональне призначення

Програма призначена для опрацювання файлів з використанням структур даних

Результат зберігаєтся у файлі *assets/output.txt*

Результат виводится у консоль

### 2.2 Опис логічної структури

Програма ствоює об'єкти структури "Пошта" використовуючі вхідні дані у файлі *assets/input.txt*
та опрацьовує їх завдяки розробленим функціям

#### 2.2.1 Основна функція

```
int main()
```

*Призначення*: головна функція

*Опис роботи*:
 - відкриття файлів
 - ініціалізація об'єктів структур та масивів
 - виклики розроблених функцій
 - закриття файлів
 - звільнення пам'яті об'єктів структур та масивів

#### 2.2.2 Функція визначення кількості рядків

```
int get_count_of_lines_in_file(FILE *ptr)
```

*Призначення*: введення трикутника у файл

*Опис роботи*:
 - построчний перебір файлу до його кінця
 - при кожній ітерації збільшення лічильнику

#### 2.2.3 Функція форматування строки

```
void msg_format(struct mail *info_for_msg_f, char *res_line)
```

*Призначення*: форматування строки з даними об'єкта

*Опис роботи*:
 - конкатенація строк

#### 2.2.4 Функція визначення довжини повідомлення

```
void msg_lenght(struct mail *msg)
```

*Призначення*: визначення довжини повідомлення з об'єкту

*Опис роботи*:
 - визначення довжини за допомогою функції *strlen()*

#### 2.2.5 Функція пошуку повідомлення користувача

```
void msg_find(struct mail *msgs, int count_mails, char *sender,
              char *sender_mail, char *msg_line_res)
```

*Призначення*: пошук всіх повідомлень від конкретного користувача за його им'ям та адресою поштової скриньки

*Опис роботи*:
 - перебір всіх об'єктів та пошук тих в яких співпадає ім'я та адреса поштової скриньки
 з отриманими аргументами функції


#### 2.2.6 Функція визначення довжини всіх повідомлень

```
int all_msg_lenght(struct mail *msgs, int rows)
```

*Призначення*: визначення довжини всіх повідомлень

*Опис роботи*:
 - перебір всіх об'єктів та визначення довжини повідомлення в кожному з них
 - додавання кожної довжини до змінної

#### 2.2.7 Функція запису у файл

```
void write(FILE *fPtr, char *msg_formatted_line, char *msg_from_specific_user,
           char *specific_sender, char *specific_sender_mail, int c);
```
*Призначення*: запис інформації у файл

*Опис роботи*:
 - відкриття (або створення) файлу
 - запис отриманої інформації у якості аргументів у файл
 - закриття файлу

#### 2.2.8 Структура проекту

```
lab14
├── assets
│   ├── input.txt
│   └── output.txt
├── Doc
│   └── lab14.md
├── Doxyfile
├── Makefile
├── src
│   ├── lib.c
│   ├── lib.h
│   └── main.c
└── test
    └── test.c

```

## Варіант використання

Для демонстрації результатів задачі використовується:

 - вивід інформації у консоль

**Варіант використання**
 - підготувати файл с вхідними даними
 - запустити програму
 - подивитися результат у консолі
 - подивитися результат у файлы *output.txt* у папці *assets*

**Результат виконання програми у консолі:**

```
yuzo@yuzo-VirtualBox:~/programming/workTemp/hw_univers_programming/lab14/dist$ ./main.bin 
6
1
theme
text
sender
sendermail
reciever
recievermail
UTF-8
0
theme2
text2
sender2
sendermail2
reciever2
recievermail2
UTF-16
1
theme3
text3
sender3
sendermail3
reciever3
recievermail3
CP-1251
0
theme3
text_one
sender4
sendermail4
reciever4
recievermail4
UTF-8
0
theme3
text_two
sender4
sendermail4
reciever5
recievermail5
UTF-16
1
theme3
text_three
sender4
sendermail4
reciever6
recievermail6
UTF-16
Message formatted line is: 
sender3 reciever3 theme3 text3

Msg lenght: 4

All messages from specific user 'sender4' 'sendermail4': 
text_one
text_two
text_three


Lenght of all messages in file 'assets/input.txt': 40

```

**Результат виконання програми у файлі:**

```
Message formatted line is: 
sender3 reciever3 theme3 text3

All messages from specific user 'sender4' 'sendermail4': 
text_one
text_two
text_three


Lenght of all messages in file 'assets/input.txt': 40

```

**Вхідний файл "input.txt":**
```
1 theme text sender sendermail reciever recievermail UTF-8
0 theme2 text2 sender2 sendermail2 reciever2 recievermail2 UTF-16
1 theme3 text3 sender3 sendermail3 reciever3 recievermail3 CP-1251
0 theme3 text_one sender4 sendermail4 reciever4 recievermail4 UTF-8
0 theme3 text_two sender4 sendermail4 reciever5 recievermail5 UTF-16
1 theme3 text_three sender4 sendermail4 reciever6 recievermail6 UTF-16
```

## Висновки

При виконанні даної лабораторної роботи я познайомився та навчився
працювати зі структурами даних у мові програмування "С"