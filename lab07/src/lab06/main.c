#include <stdlib.h>
#include <time.h> 

int x_rank (int x);
void get_ntht_num (int x, int x_is, int* n_num, int* ten_num, int* hun_num, int* thous_num);
int get_ten_type (int n_num, int ten_num);


int main (int argc, char** argv) {
    int x;

	//Проверка наличия аргумента от пользователя и дальнейшее определение переменной Х
	if (argc == 1){
        srand (time(NULL));
        x = (int)random() % 10000;
    } else {
        x = (int)strtod(argv[1], 0);
    }

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
	
    get_ntht_num(x, x_is, &n_num, &ten_num, &hun_num, &thous_num);

    if (x_is != 0){
        ten_type = get_ten_type(n_num, ten_num);
    }

    char array_num_words[][10]={"one","two","three","four","five","six","seven","eight","nine"}; //Строка для цифр
	char array_irregular_ten_words[][10]={"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"}; //Строка для десятков (от 11 до 19 включительно)
	char array_clean_ten_words[][10]={"ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"}; //Строка для "чистых" чисел
	char word_thous[]="thousand";
	char word_hun[]="hundred";

	int temp = 0;
	char m2[50];

	if (thous_num != 0){
		for (int i = thous_num - 1; i < thous_num; i++){
    	    for (int j = 0; j < 10; j++){
       		    if (array_num_words[i][j] == '\0'){
					m2[temp] = '\0';					
            	    break;
            	}
            	m2[temp] = array_num_words[i][j];
            	temp++;
        	}
    	}

		m2[temp] = ' ';
		temp++;

		for (int i = 0; i < 9; i++){
			m2[temp] = word_thous[i];
			temp++;
		}
	}

	if (hun_num != 0){
		if (x_is == 3){
			m2[temp - 1] = ' ';
		}
		for (int i = hun_num - 1; i < hun_num; i++){
			for (int j = 0; j < 10; j++){
       		    if (array_num_words[i][j] == '\0'){
					m2[temp] = '\0';					
            	    break;
            	}
            	m2[temp] = array_num_words[i][j];
            	temp++;
        	}
		}
		
		m2[temp] = ' ';
		temp++;

		for (int i = 0; i < 9; i++){
			m2[temp] = word_hun[i];
			temp++;
		}
	}

	if (ten_num != 0){
		if (x_is > 1){
			m2[temp - 2] = ' ';
			temp--;
		}
		if (ten_type == 0){
			for (int i = ten_num - 1; i < ten_num; i++){
				for (int j = 0; j < 10; j++){
       			    if (array_clean_ten_words[i][j] == '\0'){
						m2[temp] = '\0';					
    	        	    break;
   		         	}
     		       	m2[temp] = array_clean_ten_words[i][j];
        	    	temp++;
        		}
			}
		} else if (ten_type == 1){
			for (int i = ten_num - 1; i < ten_num; i++){
				for (int j = 0; j < 10; j++){
       			    if (array_clean_ten_words[i][j] == '\0'){
						m2[temp] = '\0';					
    	        	    break;
   		         	}
     		       	m2[temp] = array_clean_ten_words[i][j];
        	    	temp++;
        		}
			}

			m2[temp] = ' ';
			temp++;

			for (int i = n_num - 1; i < n_num; i++){
				for (int j = 0; j < 10; j++){
       			    if (array_num_words[i][j] == '\0'){
						m2[temp] = '\0';					
    	        	    break;
   		         	}
     		       	m2[temp] = array_num_words[i][j];
        	    	temp++;
        		}
			}
		} else {
			for (int i = n_num - 1; i < n_num; i++){
				for (int j = 0; j < 10; j++){
       			    if (array_irregular_ten_words[i][j] == '\0'){
						m2[temp] = '\0';					
    	        	    break;
   		         	}
     		       	m2[temp] = array_irregular_ten_words[i][j];
        	    	temp++;
        		}
			}
		}
	}
	
	if (x_is == 0 && x != 0) {
		for (int i = n_num - 1; i < n_num; i++){
			for (int j = 0; j < 10; j++){
    		    if (array_num_words[i][j] == '\0'){
					m2[temp] = '\0';					
    	      	    break;
   		     	}
    	       	m2[temp] = array_num_words[i][j];
    	    	temp++;
    		}
		}
	} else if (x_is == 0 && x == 0){
		char z[] = "zero";
		for (int i = 0; i < 4; i++){
			m2[temp] = z[i];
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

//Определение типа десятка
int get_ten_type (int n_num, int ten_num){
    int ten_type; //0 - Чистый; 1 - Чистый с цифрой; 2 - Неправильный
    if (n_num > 0 && n_num < 10 && ten_num == 1){
		ten_type = 2;
	} else if (ten_num != 0 && n_num == 0){
		ten_type = 0;
	} else if (ten_num > 1 && n_num != 0){
		ten_type = 1;
	}
    return (ten_type);
}



