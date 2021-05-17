#include <iostream>

int main(){
    //scanf("`format_specifier`", &val)

    int a;
    long b;
    char ch;
    float f;
    double d;
    scanf("%d %ld %c %f %lf", a, b, ch, f, d);

    printf("%d", a);
    printf("%ld", b);
    printf("%c", ch);
    printf("%f", f);
    printf("%lf", d);

    return 0;
}