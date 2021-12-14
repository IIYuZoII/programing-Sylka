int xx_count (year){

    int xx;

    if (year % 100 == 0){
        if (year / 100 % 10 != 0){
            xx = year / 100;
        } else {
            xx = year / 10;
        }

    } else {
        xx = (year - year % 100) / 100 + 1;
    }

    return (xx);
}


int main (){

    int year = 101;

    int xx = xx_count(year);

    return (0);
}