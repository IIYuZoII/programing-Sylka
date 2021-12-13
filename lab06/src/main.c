/* Перетворити число (максимальне значення якого - 9999) в рядок. (усі символи
 * нижнього регістру на виході). Наприклад,
 * • 123 – “one hundred twenty three”,
 * • 4311 – “four thousands three hundreds eleven”
 *
 *
 *  1) Узнать величину числа
 *  2) Разбить на разряды
 *  3) В зависимости от величины числа, наличия сотен, десятков, единиц, сделать поиск "границ" необходимых слов в строках при помощи разрядов числа
 *  4) В зависимости от величины числа, наличия сотен, десятков, единиц, записать в результирующую строку
 * 		полученные слова вытягивая их из соответствуещих строк ориентируясь по ранее полученным границам слов
 *	
 *
 */

#include <stdio.h>


int main (){
	
	int x = 97;

	//Единица = 0
	//Десяток = 1
	//Сотня = 2
	//Тысяча = 3
	int x_is = 0;
	
	int ten_type = 0; //0 - Чистый; 1 - Чистый с цифрой; 2 - Неправильный
	
	//Переменные разрядов
	int thous_num = 0;
	int hun_num = 0;
	int ten_num = 0;
	int n_num = 0;
	
	//Кол-во пробелов
	int space_count = 0;
	
	//Определение разрядности числа
	if (x < 10000 && x >= 0){
    	if (x / 10 < 1){
    	    x_is = 0;
    	} else if (x / 10 >= 1 && (x / 10) < 10) {
    	    x_is = 1;
    	} else if (x / 10 >= 10 && x / 10 < 100){
    	    x_is = 2;
    	} else if (x / 10 >= 100){
    	    x_is = 3;
    	}
	}
	
	//Разбивание числа на разряды
	if (x_is == 1){
    	ten_num = x / 10;
    	n_num = x % 10;
	} else if (x_is == 2){
    	hun_num = x / 100;
	    ten_num = (x / 10) % 10;
    	n_num = x % 10;
	} else if (x_is == 3){
    	thous_num = x / 1000;
    	hun_num = (x / 100) % 10;
	    ten_num = (x / 10) % 10;
    	n_num = x % 10;
	} else {
		n_num = x;
	}
	
	//Определение типа десятка
	if (n_num > 0 && n_num < 10 && ten_num == 1){
		ten_type = 2;
	} else if (ten_num == 1 && n_num == 0){
		ten_type = 0;
	} else if (ten_num > 1 && n_num != 0){
		ten_type = 1;
	}
	
	//Считаем кол-во пробелов //не совсем корректно пашет (если число 1121 то должно быть 5, а щас их)
	if (x_is == 1) {
		if (ten_type == 1) {
			space_count++;
		}
	} else if (x_is == 2){
		space_count++;
		if (ten_num != 0){
			space_count++;
			if (ten_type == 1){
				space_count++;
			}
		}
	} else if (x_is == 3){
		space_count++;
		if (hun_num != 0){
			space_count += 2;
		}
		if (ten_num != 0){
			space_count++;
			if (ten_type == 1){
				space_count++;
			}
		} else {
			if (n_num != 0){
				space_count++;
			}
		}
	}
    
	char array_num_words[]="one,two,three,four,five,six,seven,eight,nine\0"; //Строка для цифр
	char array_irregular_ten_words[]="eleven,twelve,thirteen,fourteen,fifteen,sixteen,seventeen,eighteen,nineteen\0"; //Строка для десятков (от 11 до 19 включительно)
	char array_clean_ten_words[]="ten,twenty,thirty,forty,fifty,sixty,seventy,eighty,ninety\0"; //Строка для "чистых" чисел
	char word_thous[]="thousand";
	char word_hun[]="hundred";
	
	//Переменные для строки с цифрами
	int temp_count_letters_num_words = 0; //Временный счётчик символов внутри слова
	int count_letters_num_words = 0; //Счётчик символов внутри слова (обнуляется если цикл идёт искать нужное слово дальше)
	int count_words_num_words = 0; //Счётчик слов
	int count_symbols_num_words = 0; //Счётчик кол-ва символов в строке
	
	//Переменные для строки с десятками (11-19)
	int temp_count_letters_irregular_ten_words= 0; //Временный счётчик символов внутри слова
	int count_letters_irregular_ten_words = 0; //Счётчик символов внутри слова
	int count_words_irregular_ten_words = 0; //Счётчик слов
	int count_symbols_irregular_ten_words = 0; //Счётчик кол-ва символов в строке
	
	//Переменные для строки с "чистыми" десятками (10, 20, 30, ..., 90)
	int temp_count_letters_clean_ten_words = 0; //Временный счётчик символов внутри слова
	int count_letters_clean_ten_words = 0; //Счётчик символов внутри слова
	int count_words_clean_ten_words = 0; //Счётчик слов
	int count_symbols_clean_ten_words = 0; //Счётчик кол-ва символов в строке
	
	//Переменные для числа сотни
	int temp_count_letters_num_hun_words = 0; //Временный счётчик символов внутри слова
	int count_letters_num_hun_words = 0; //Счётчик символов внутри слова
	int count_words_num_hun_words = 0; //Счётчик слов
	int count_symbols_num_hun_words = 0; //Счётчик кол-ва символов в строке
	
	//Переменные для числа тысячи
	int temp_count_letters_num_thous_words = 0; //Временный счётчик символов внутри слова
	int count_letters_num_thous_words = 0; //Счётчик символов внутри слова
	int count_words_num_thous_words = 0; //Счётчик слов
	int count_symbols_num_thous_words = 0; //Счётчик кол-ва символов в строке


	//Начало волшебства

    //Ищем границы слов в строках в зависимости от числа
	if (x_is == 1){ //Если число десяток
		if (ten_type == 2){ //Если десяток неправильный
			for (int i = 0; i < 200; i++){
				count_symbols_irregular_ten_words++;
				if (array_irregular_ten_words[i] != ',' && array_irregular_ten_words[i] != '\0'){
					temp_count_letters_irregular_ten_words++;
				} else {
					count_words_irregular_ten_words++;
					count_letters_irregular_ten_words = temp_count_letters_irregular_ten_words;
					temp_count_letters_irregular_ten_words = 0;
				}
				if (count_words_irregular_ten_words == n_num){
					break;
				}
				if (array_irregular_ten_words[i] == '\0'){
					break;
				}
			}
		} else if (ten_type == 0) { //Если десяток чистый и не имеет единиц (10, 20, 30, ..., 90)
			for (int i = 0; i < 100; i++){
				count_symbols_clean_ten_words++;
				if (array_clean_ten_words[i] != ',' && array_clean_ten_words[i] != '\0'){
					temp_count_letters_clean_ten_words++;
				} else {
					count_words_clean_ten_words++;
					count_letters_clean_ten_words = temp_count_letters_clean_ten_words;
					temp_count_letters_clean_ten_words = 0;
				}
				if (count_words_clean_ten_words == ten_num){
					break;
				}
				if (array_clean_ten_words[i] == '\0'){
					break;
				}
			}
		} else { //Если десяток чистый + цифры
			//Поиск границ чистых десятков
			for (int i = 0; i < 100; i++){ 
				count_symbols_clean_ten_words++;
				if (array_clean_ten_words[i] != ',' && array_clean_ten_words[i] != '\0'){
					temp_count_letters_clean_ten_words++;
				} else {
					count_words_clean_ten_words++;
					count_letters_clean_ten_words = temp_count_letters_clean_ten_words;
					temp_count_letters_clean_ten_words = 0;
				}
				if (count_words_clean_ten_words == ten_num){
					break;
				}
				if (array_clean_ten_words[i] == '\0'){
					break;
				}
			}
			//Поиск границ цифр
			for (int i = 0; i < 120; i++){		
				count_symbols_num_words++;
				
				if (array_num_words[i] != ',' && array_num_words[i] != '\0'){
					temp_count_letters_num_words++;
				} else {
					count_words_num_words++; 
					count_letters_num_words = temp_count_letters_num_words; 
					temp_count_letters_num_words = 0; 
				}
				if (count_words_num_words == n_num){
					break;
				}
				if (array_num_words[i] == '\0'){
					break;
				}	
			}
		}
	} else if (x_is == 2){ //Если число сотня 
		//Поиск границ сотни
		for (int i = 0; i < 120; i++){		
			count_symbols_num_hun_words++;

			if (array_num_words[i] != ',' && array_num_words[i] != '\0'){
				temp_count_letters_num_hun_words++;
			} else {
				count_words_num_hun_words++; 
				count_letters_num_hun_words = temp_count_letters_num_hun_words;
				temp_count_letters_num_hun_words = 0;
			}
			if (count_words_num_hun_words == hun_num){
				break;
			}
			if (array_num_words[i] == '\0'){
				break;
			}	
		}
		if (ten_num != 0){ //Если десяток есть
			if (ten_type == 0){ //Если десяток чистый без цифры
				for (int i = 0; i < 100; i++){
					count_symbols_clean_ten_words++;
					if (array_clean_ten_words[i] != ',' && array_clean_ten_words[i] != '\0'){
						temp_count_letters_clean_ten_words++;
					} else {
						count_words_clean_ten_words++;
						count_letters_clean_ten_words = temp_count_letters_clean_ten_words;
						temp_count_letters_clean_ten_words = 0;
					}
					if (count_words_clean_ten_words == ten_num){
						break;
					}
					if (array_clean_ten_words[i] == '\0'){
						break;
					}
				}
			} else if (ten_type == 1){ //Если десяток чистый с цифрой
				for (int i = 0; i < 100; i++){
					count_symbols_clean_ten_words++;
					if (array_clean_ten_words[i] != ',' && array_clean_ten_words[i] != '\0'){
						temp_count_letters_clean_ten_words++;
					} else {
						count_words_clean_ten_words++;
						count_letters_clean_ten_words = temp_count_letters_clean_ten_words;
						temp_count_letters_clean_ten_words = 0;
					}
					if (count_words_clean_ten_words == ten_num){
						break;
					}
					if (array_clean_ten_words[i] == '\0'){
						break;
					}
				}
				//Поиск границ цифр
				for (int i = 0; i < 120; i++){		
					count_symbols_num_words++;

					if (array_num_words[i] != ',' && array_num_words[i] != '\0'){
						temp_count_letters_num_words++;
					} else {
						count_words_num_words++; 
						count_letters_num_words = temp_count_letters_num_words; 
						temp_count_letters_num_words = 0; 
					}
					if (count_words_num_words == n_num){
						break;
					}
					if (array_num_words[i] == '\0'){
						break;
					}	
				}
			} else { //Если десяток неправильный
				for (int i = 0; i < 200; i++){
					count_symbols_irregular_ten_words++;
					if (array_irregular_ten_words[i] != ',' && array_irregular_ten_words[i] != '\0'){
						temp_count_letters_irregular_ten_words++;
					} else {
						count_words_irregular_ten_words++;
						count_letters_irregular_ten_words = temp_count_letters_irregular_ten_words;
						temp_count_letters_irregular_ten_words = 0;
					}
					if (count_words_irregular_ten_words == n_num){
						break;
					}
					if (array_irregular_ten_words[i] == '\0'){
						break;
					}
				}
			}
		} else if (ten_num == 0){ //Если десятка нет
			if (n_num != 0){ //Если цифа есть
				for (int i = 0; i < 120; i++){	
					count_symbols_num_words++;
					
					if (array_num_words[i] != ',' && array_num_words[i] != '\0'){
						temp_count_letters_num_words++;
					} else {
						count_words_num_words++; 
						count_letters_num_words = temp_count_letters_num_words; 
						temp_count_letters_num_words = 0; 
					}
					if (count_words_num_words == n_num){
						break;
					}
					if (array_num_words[i] == '\0'){
						break;
					}
				}
			}	
		}
	} else if (x_is == 3) { //Если число тысяча
		if (hun_num != 0){ //Если сотня есть ищем единицу сотни
			for (int i = 0; i < 120; i++){		
				count_symbols_num_hun_words++;
				if (array_num_words[i] != ',' && array_num_words[i] != '\0'){
					temp_count_letters_num_hun_words++;
				} else {
					count_words_num_hun_words++;
					count_letters_num_hun_words = temp_count_letters_num_hun_words;
					temp_count_letters_num_hun_words = 0; 
				}
				if (count_words_num_hun_words == hun_num){
					break;
				}
				if (array_num_words[i] == '\0'){
					break;
				}	
			}
		} 
		if (ten_num != 0) { //Если десяток есть
			if (ten_type == 0){ //Если десяток чистый без цифры
				for (int i = 0; i < 100; i++){
					count_symbols_clean_ten_words++;
					if (array_clean_ten_words[i] != ',' && array_clean_ten_words[i] != '\0'){
						temp_count_letters_clean_ten_words++;
					} else {
						count_words_clean_ten_words++;
						count_letters_clean_ten_words = temp_count_letters_clean_ten_words;
						temp_count_letters_clean_ten_words = 0;
					}
					if (count_words_clean_ten_words == ten_num){
						break;
					}
					if (array_clean_ten_words[i] == '\0'){
						break;
					}
				}
			} else if (ten_type == 1){ //Если десяток чистый с цифрой
				for (int i = 0; i < 100; i++){
					count_symbols_clean_ten_words++;
					if (array_clean_ten_words[i] != ',' && array_clean_ten_words[i] != '\0'){
						temp_count_letters_clean_ten_words++;
					} else {
						count_words_clean_ten_words++;
						count_letters_clean_ten_words = temp_count_letters_clean_ten_words;
						temp_count_letters_clean_ten_words = 0;
					}
					if (count_words_clean_ten_words == ten_num){
						break;
					}
					if (array_clean_ten_words[i] == '\0'){
						break;
					}
				}
				//Поиск границ цифр
				for (int i = 0; i < 120; i++){		
					count_symbols_num_words++;
					
					if (array_num_words[i] != ',' && array_num_words[i] != '\0'){
						temp_count_letters_num_words++;
					} else {
						count_words_num_words++;
						count_letters_num_words = temp_count_letters_num_words;
						temp_count_letters_num_words = 0;
					}					
					if (count_words_num_words == n_num){
						break;
					}					
					if (array_num_words[i] == '\0'){
						break;
					}	
				}	
			} else { //Если десяток неправильный
				for (int i = 0; i < 200; i++){
					count_symbols_irregular_ten_words++;
					if (array_irregular_ten_words[i] != ',' && array_irregular_ten_words[i] != '\0'){
						temp_count_letters_irregular_ten_words++;
					} else {
						count_words_irregular_ten_words++;
						count_letters_irregular_ten_words = temp_count_letters_irregular_ten_words;
						temp_count_letters_irregular_ten_words = 0;
					}
					if (count_words_irregular_ten_words == n_num){
						break;
					}
					if (array_irregular_ten_words[i] == '\0'){
						break;
					}
				}
			}
		} else if (ten_num == 0) { //Если десятка нету
			if (n_num != 0) { //Если цифра есть
				for (int i = 0; i < 120; i++){	
					
					count_symbols_num_words++;
					
					if (array_num_words[i] != ',' && array_num_words[i] != '\0'){
						temp_count_letters_num_words++;
					} else {
						count_words_num_words++; 
						count_letters_num_words = temp_count_letters_num_words; 
						temp_count_letters_num_words = 0; 
					}
					
					if (count_words_num_words == n_num){
						break;
					}
					
					if (array_num_words[i] == '\0'){
						break;
					}
				}
			}
		}
		//Поиск числа для тысячи
		for (int i = 0; i < 120; i++){		
		
			count_symbols_num_thous_words++;
		
			if (array_num_words[i] != ',' && array_num_words[i] != '\0'){
				temp_count_letters_num_thous_words++;
			} else {
				count_words_num_thous_words++; 
				count_letters_num_thous_words = temp_count_letters_num_thous_words; 
				temp_count_letters_num_thous_words = 0; 
			}
			if (count_words_num_thous_words == thous_num){
				break;
			}
			if (array_num_words[i] == '\0'){
				break;
			}	
		}
	} else { //Если число единица
		if (n_num != 0){
			for (int i = 0; i < 120; i++){	
				count_symbols_num_words++;
				
				if (array_num_words[i] != ',' && array_num_words[i] != '\0'){
					temp_count_letters_num_words++;
				} else {
					count_words_num_words++; 
					count_letters_num_words = temp_count_letters_num_words; 
					temp_count_letters_num_words = 0; 
				}
				if (count_words_num_words == n_num){
					break;
				}
				if (array_num_words[i] == '\0'){
					break;
				}
			}
		} 
	}
	
	//Переменная для учёта длинны слов thousand и hundred в результативного массива
	int temp_hun_or_thous = 0;
	if (x_is == 2){
		temp_hun_or_thous += 7;
	} else if (x_is == 3){
		if (hun_num != 0){
			temp_hun_or_thous += 8 + 7;
		} else {
			temp_hun_or_thous += 8;
		}
	}
	
	//Переменная для длинны результативного массива
	int len_m2 = space_count + count_letters_num_words + count_letters_irregular_ten_words + count_letters_clean_ten_words + count_letters_num_hun_words + count_letters_num_thous_words + temp_hun_or_thous;
	if (x_is == 0 && n_num == 0){
		len_m2 = 4;
	}
	
	//Результативный массив
	char m2[len_m2+1];
	
	//Переменная для индекса результативного массива 
	int temp = 0;
	
	//Переменные для поиска границ слова в строке единиц
	int temp_left_num_words = count_symbols_num_words - count_letters_num_words - 1;
	int temp_right_num_words = count_symbols_num_words - 1;
	
	//Переменные для поиска границ слова в строке неправильных десятков
	int temp_left_irregular_ten_words = count_symbols_irregular_ten_words - count_letters_irregular_ten_words - 1;
	int temp_right_irregular_ten_words = count_symbols_irregular_ten_words - 1;
	
	//Переменные для поиска границ слова в строке чистых десятков
	int temp_left_clean_ten_words = count_symbols_clean_ten_words - count_letters_clean_ten_words - 1;
	int temp_right_clean_ten_words = count_symbols_clean_ten_words - 1;
	
	//Переменные для поиска границ слова в строке единиц для сотни
	int temp_left_num_hun_words = count_symbols_num_hun_words - count_letters_num_hun_words - 1;
	int temp_right_num_hun_words = count_symbols_num_hun_words - 1;
	
	//Переменные для поиска границ слова в строке единиц для тысячи
	int temp_left_num_thous_words = count_symbols_num_thous_words - count_letters_num_thous_words - 1;
	int temp_right_num_thous_words = count_symbols_num_thous_words - 1;
	
	char space = ' ';
	char spec_symbol_end = '\0';
	char word_for_zero []= "zero";

	if (x_is == 0){ //Если число цифра
		if (n_num != 0){
			for (int i = temp_left_num_words; i < temp_right_num_words; i++){
				m2[temp] = array_num_words[i];
				temp++;
			}
		} else {
			for (int i = 0; i < 6; i++){
				m2[temp] = word_for_zero[i];
				temp++;
			}
		}
	} else if (x_is == 1){ //Если число десяток
		if (ten_type == 0){ //Если десяток чистый
			for (int i = temp_left_clean_ten_words; i < temp_right_clean_ten_words; i++){
				m2[temp] = array_clean_ten_words[i];
				temp++;
			}
		} else if (ten_type == 1) { //Если десяток чистый с цифрой
			for (int i = temp_left_clean_ten_words; i < temp_right_clean_ten_words; i++){
				m2[temp] = array_clean_ten_words[i];
				temp++;
			}
			m2[temp] = space;
			temp++;
			for (int i = temp_left_num_words; i < temp_right_num_words; i++){
				m2[temp] = array_num_words[i];
				temp++;
				if (temp + 1 == len_m2){
		 			m2[temp + 1] = spec_symbol_end;
			 	}
			}
		} else if (ten_type == 2) { //Если десяток неправильный
			for (int i = temp_left_irregular_ten_words; i < temp_right_irregular_ten_words; i++){
				m2[temp] = array_irregular_ten_words [i];
				if (temp + 1 == len_m2){
					m2[temp + 1] = spec_symbol_end;
				}
				temp++;
			}
		}
	} else if (x_is == 2){ //Если число сотня
		//Единица сотни
		for (int i = temp_left_num_hun_words; i < temp_right_num_hun_words; i++){
			m2[temp] = array_num_words[i];
			temp++;
		}
		m2[temp] = space;
		temp++;
		//Слово hundred
		for (int i = 0; i < 100; i++){
			if (word_hun[i] != '\0'){
				m2[temp] = word_hun[i];
				temp++;
			} else {
				break;
			}
		}
		if (ten_num != 0){ //Если есть десяток
			m2[temp] = space;
			temp++;
			if (ten_type == 0){ //Если десяток чистый
				for (int i = temp_left_clean_ten_words; i < temp_right_clean_ten_words; i++){
					m2[temp] = array_clean_ten_words[i];
					temp++;
				}
			} else if (ten_type == 1){ //Если десяток чистый с цифрой
				for (int i = temp_left_clean_ten_words; i < temp_right_clean_ten_words; i++){
					m2[temp] = array_clean_ten_words[i];
					temp++;
				}
				m2[temp] = space;
				temp++;
				for (int i = temp_left_num_words; i < temp_right_num_words; i++){
					m2[temp] = array_num_words[i];
					temp++;
					if (temp + 1 == len_m2){
		 				m2[temp + 1] = spec_symbol_end;
			 		}
				}
			} else if (ten_type == 2){ //Если десяток неправильный
				for (int i = temp_left_irregular_ten_words; i < temp_right_irregular_ten_words; i++){
					m2[temp] = array_irregular_ten_words [i];
					if (temp + 1 == len_m2){
						m2[temp + 1] = spec_symbol_end;
					}
					temp++;
				}
			}
		} else { //Если нету десятка но есть число
			if (n_num != 0){
				
				m2[temp] = space;
				temp++;
				
				for (int i = temp_left_num_words; i < temp_right_num_words; i++){
					m2[temp] = array_num_words[i];
					temp++;
					if (temp + 1 == len_m2){
		 				m2[temp + 1] = spec_symbol_end;
			 		}
				}
			}
		}
	} else if (x_is == 3){ //Если число тысяча
		for (int i = temp_left_num_thous_words; i < temp_right_num_thous_words; i++){
			m2[temp] = array_num_words[i];
			temp++;
		}
		m2[temp] = space;
		temp++;
		//Слово thousand
		for (int i = 0; i < 100; i++){
			if (word_thous[i] != '\0'){
				m2[temp] = word_thous[i];
				temp++;
			} else {
				break;
			}
		}
		if (hun_num != 0){ //Если есть сотня
			m2[temp] = space;
			temp++;
			for (int i = temp_left_num_hun_words; i < temp_right_num_hun_words; i++){
				m2[temp] = array_num_words[i];
				temp++;
			}
			m2[temp] = space;
			temp++;
			//Слово hundred
			for (int i = 0; i < 100; i++){
				if (word_hun[i] != '\0'){
					m2[temp] = word_hun[i];
					temp++;
				} else {
					break;
				}
			}
		} 
		if (ten_num != 0){ //Если есть десяток
			m2[temp] = space;
			temp++;
			if (ten_type == 0){ //Если десяток чистый
				for (int i = temp_left_clean_ten_words; i < temp_right_clean_ten_words; i++){
					m2[temp] = array_clean_ten_words[i];
					temp++;
				}
			} else if (ten_type == 1){ //Если десяток чистый с цифрой
				for (int i = temp_left_clean_ten_words; i < temp_right_clean_ten_words; i++){
					m2[temp] = array_clean_ten_words[i];
					temp++;
				}
				m2[temp] = space;
				temp++;
				for (int i = temp_left_num_words; i < temp_right_num_words; i++){
					m2[temp] = array_num_words[i];
					temp++;
					if (temp + 1 == len_m2){
		 				m2[temp + 1] = spec_symbol_end;
			 		}
				}
			} else if (ten_type == 2){ //Если десяток неправильный
				for (int i = temp_left_irregular_ten_words; i < temp_right_irregular_ten_words; i++){
					m2[temp] = array_irregular_ten_words [i];
					if (temp + 1 == len_m2){
						m2[temp + 1] = spec_symbol_end;
					}
					temp++;
				}
			}
		} else { //Если десятка нету
			if (n_num != 0){
				m2[temp] = space;
				temp++;
				for (int i = temp_left_num_words; i < temp_right_num_words; i++){
					m2[temp] = array_num_words[i];
					temp++;
					if (temp + 1 == len_m2){
		 				m2[temp + 1] = spec_symbol_end;
			 		}
				}
			} else if (n_num == 0) {
				if (temp == len_m2){
		 			m2[temp] = spec_symbol_end;
			 	}
			}
		}
	}

	printf ("\nСлово: ");
	printf ("%s\n", m2);
 
    return (0);
}
