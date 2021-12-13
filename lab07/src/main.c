#include <stdio.h>
#include <stdlib.h>

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

//Функция для расчётов с использованием цикла while do
int cycle_while_do (x){
    int tf = 0;
    int count = 0;
    while (count < x){
	
	    if (count == 0){
	        if (x != 2 && x % 2 == 0){
	            tf = 1;
    		    break;
    	    } else {
           		count++;
	            continue;
	        }
    	}
	
    	if (count == 1){
    	    count++;
    	    continue;
    	}

	
    	if (x % count == 0){
    	    tf = 1;
    	    break;
    	}
        count++;
    }
    return (tf);
}

//Функция для расчётов с использованием цикла do while
int cycle_do (x){
    int tf = 0;
    int count = 0;

    do {   	
    	if (count == 0){
    	    if (x != 2 && x % 2 == 0){
    	        tf = 1;
    	        break;
    	    } else {
    	        count++;
    		continue;
    	    }
    	}

    	if (count == 1){
    	    count++;
    	    continue;
    	}

    	if (x % count == 0){
    	    tf = 1;
    	    break;
    	}

    	count++;
        
    } while (count <= (x-1));

    return (tf);
}

//Вывод результата в консоль
void pr (tf){
    if (tf == 1){
	printf ("%s\n", "Данное число не является простым (Определено при помощи цикла for)");
    } else {
	printf ("%s\n", "Данное число является простым (Определено при помощи цикла for)");
    }
}


int main (){


    int x = 72;

    int r = 0;
    r = rand()%100;

    int tf_for;
    tf_for = cycle_for(x);

    int tf_while;
    tf_while = cycle_while_do(x); 

    //Два вызова с рандомными аргументами
    int tf_do;
    tf_do = cycle_do(r);

    int sec_tf_for = cycle_for(rand()%100);

    //Вызов функции которая выводит результат в консоль
    pr(tf_for);



    return (0);
}