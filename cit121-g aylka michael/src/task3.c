int div(int number) {
    int count = 1;

    if (number / 10 == 0)
    {
        count = 1;
    }
    else{
        while (number > 0)
        {
            number /= 10;
            count *= 10;
        }
    }

    return count;
}

double d(int f, int s) {
    return (f + (double)s/div(s));
}

int main() {

    int f = 123;
    int s = 321;

    double res = d(f, s);

    return 0;
}




