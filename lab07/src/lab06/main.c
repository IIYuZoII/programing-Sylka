



int x_rank (int x);
void get_ntht_num (int x, int x_is, int* n_num, int* ten_num, int* hun_num, int* thous_num);
int get_ten_type (int n_num, int ten_num);





int main () {
    int x = 17;

    //Единица = 0
	//Десяток = 1
	//Сотня = 2
	//Тысяча = 3
	int x_is = x_rank(x);
	
	int ten_type = 0; //0 - Чистый; 1 - Чистый с цифрой; 2 - Неправильный
	
	//Переменные разрядов
	int thous_num = 0;
	int hun_num = 0;
	int ten_num = 0;
	int n_num = 0;
	
	//Кол-во пробелов
	int space_count = 0;
	
    get_ntht_num(x, x_is, &n_num, &ten_num, &hun_num, &thous_num);

	//Определение типа десятка
	// if (n_num > 0 && n_num < 10 && ten_num == 1){
	// 	ten_type = 2;
	// } else if (ten_num == 1 && n_num == 0){
	// 	ten_type = 0;
	// } else if (ten_num > 1 && n_num != 0){
	// 	ten_type = 1;
	// }
    if (x_is != 0){
        ten_type = get_ten_type(n_num, ten_num);
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
    return(0);
}

//Return: Единица = 0; Десяток = 1; Сотня = 2; Тысяча = 3
int x_rank (int x) {
    int x_is;
    if (x < 10000 && x >= 0){
    	if (x / 10 < 1){
    	    x_is = 0;
            //return (0);
    	} else if (x / 10 >= 1 && (x / 10) < 10) {
    	    x_is = 1;
            //return (1);
    	} else if (x / 10 >= 10 && x / 10 < 100){
    	    x_is = 2;
            //return (2);
    	} else if (x / 10 >= 100){
    	    x_is = 3;
            //return (3);
    	}
	}
    return (x_is);
}

//Разбивание числа на разряды
void get_ntht_num (int x, int x_is, int* n_num, int* ten_num, int* hun_num, int* thous_num) {
    if (x_is == 1){
    	*ten_num = x / 10;
    	*n_num = x % 10;
	} else if (x_is == 2){
    	*hun_num = x / 100;
	    *ten_num = (x / 10) % 10;
    	*n_num = x % 10;
	} else if (x_is == 3){
    	*thous_num = x / 1000;
    	*hun_num = (x / 100) % 10;
	    *ten_num = (x / 10) % 10;
    	*n_num = x % 10;
	} else {
		*n_num = x;
	}
}

//Определение типа десятка       МОЖНО УПРОСТИТЬ СДЕЛАВ ПРОВЕРКУ В ИФЕ (если число не единица, только тогда вызываем функцию)
int get_ten_type (int n_num, int ten_num){
    int ten_type; //0 - Чистый; 1 - Чистый с цифрой; 2 - Неправильный
    if (n_num > 0 && n_num < 10 && ten_num == 1){
		ten_type = 2;
	} else if (ten_num == 1 && n_num == 0){
		ten_type = 0;
	} else if (ten_num > 1 && n_num != 0){
		ten_type = 1;
	}
    return (ten_type);
}














