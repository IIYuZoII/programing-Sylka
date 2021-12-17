#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Скелет функции
int cycle_for (int x);


int main (int argc, char** argv){


    int x;

    int tf;
    //x = rand()%100;

	if (argc == 1){
		srand(time(NULL));
		x = rand()%100;
		tf = cycle_for(x);
	} else {
		tf = cycle_for((int)strtod(argv[1], 0));
	}
    //tf = cycle_for(x);


    //int sec_tf_for = cycle_for(rand()%100);

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
