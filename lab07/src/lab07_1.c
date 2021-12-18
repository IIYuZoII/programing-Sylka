// Реалізувати функцію (та продемонструвати її роботу), що визначає, скільки серед заданої
// послідовності чисел таких пар, у котрих перше число менше наступного, використовуючи
// функцію



//Скелет функции
int get_count (int arr[], int len);


int main (){
    int len = 6;

    int arr[] = {6, 5, 4, 3, 2, 1};
    int count = get_count(arr, len);   

    return (0);

}

//Функция возвращает кол-во "неправильных" пар значений в массиве
int get_count (int arr[], int len){
    int temp_count = 0;

    //Перебор массива
    for (int i = 0; i < len; i++){
        if (arr[i] > arr[i+1]){
            temp_count++;
        }
    }
    return (temp_count);
}