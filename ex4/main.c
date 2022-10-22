/* main.c */
#include <stdio.h>
#include "./code/staticlib.h"

void main()
{
    int num1, num2;
    printf("intput num 2 : ");
    scanf("%d %d", &num1, &num2);

    printf("add(%d,%d) = %d\n", num1, num2, (*add) (num1,num2));
    printf("subtract(%d,%d) = %d\n", num1, num2, (*subtract) (num1,num2));
    printf("multiply(%d,%d) = %d\n", num1, num2, (*multiply) (num1,num2));
    printf("divide(%d, %d) = %lf\n", num1, num2, divide(num1,num2));
}