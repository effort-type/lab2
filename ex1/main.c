/* main.c */
#include <stdio.h>
#include "./code/staticlib.h"

void main()
{
    printf("add(1, 2) = %d\n", add(1, 2));
    printf("subtract(1, 2) = %d\n", subtract(1, 2));
    printf("multiply(1, 2) = %d\n", multiply(1, 2));
    printf("divide(2, 1) = %lf\n", divide(2, 1));
}