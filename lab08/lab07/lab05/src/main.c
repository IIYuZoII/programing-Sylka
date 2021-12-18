/**
 * @mainpage
 * # Загальне завдання
 * **Створити** функцію, яка буде визначати яке число: просте, чи нi
 *
 * @author sylkaMichael
 * @date 18-dec-2021
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Головний виконуючий файл в програмі
 *
 * @author sylkaMichael
 * @date 18-dec-2021
 * @version 1.0
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Return 0 або 1 в залежностi від типу числа
 *
 * Функція визначає тип числа (просте чи ні)
 * @param x число для перевірки
 * @return тип числа (0 - просте, 1 - не просте)
 */
int cycle_for (int x);

/**
 * Головна функція.
 *
 * Послідовність дій:\n
 * 1) Перевіка чи є аргумент з командної строки, якщо немає, то запис в {@link x} випадкового числа, else запис в {@link x} аргументу\n
 * 2) Визов функції {@link cycle_for} та запис в змінну передаваючи в функцію {link x}
 * @return успішний код повернення з програми (0)
 */
int main (int argc, char** argv){


    int x;
    int tf; // 0 - True;  1 - False
    
	if (argc == 1){
		srand(time(NULL));
		x = rand()%100;
		tf = cycle_for(x);
	} else {
		tf = cycle_for((int)strtod(argv[1], 0));
	}


    

    //Вызов функции которая выводит результат в консоль
    printf("%d", tf);



    return (0);
}


//Функция для расчётов с использованием цикла for
int cycle_for (x){
    int tf = 0;

    if (x != 0){
        for (int i = 0; i < x; i++){
            if (i == 0){
        		if (x != 2 && x % 2 == 0){
        	     tf = 1;
        	        break;
     		    } else {
        		    continue;
    	    	}	
            }

	        if (i == 1){
	            continue;
	        }

	        if (x % i == 0){
        		tf = 1;
        		break;
	        }
	    }
    }
    return (tf);   
}
