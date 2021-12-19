// Реалізувати функцію (та продемонструвати її роботу), що визначає, скільки серед заданої
// послідовності чисел таких пар, у котрих перше число менше наступного, використовуючи
// функцію

#include <stdlib.h>
#include <time.h> 

//Скелет функции
int get_count (int arr[], int len);


int main (int argc, char** argv){
    int len = 6;

    int arr[] = {5, 5, 5, 5, 5, 5};
    if(argc == 1){
        srand(time(NULL));
	for (int i = 0; i < len; i++){
	    arr[i] = rand()%100;
	}
    } else {
    	for (int i = 1; i < len + 1; i++){
    	    arr[i - 1] = (int)strtod(argv[i], 0);
    	}
    }
    
    int count = get_count(arr, len);

    return (0);

}

//Функция возвращает кол-во "неправильных" пар значений в массиве
int get_count (int arr[], int len){
    int temp_count = 0;

    //Перебор массива
    for (int i = 0; i < len-1; i++){
        if (arr[i] < arr[i+1] && i + 1 < len){
            temp_count++;
        }
    }
    return (temp_count);
}
