/* dynamic.c */

#include <stdio.h>
#include <stdlib.h> // exit() 사용하기 위함
#include <string.h> // 문자열 관련 라이브러리
#include <dlfcn.h>


void main()
{
    void *handle;
	int (*add) (int, int), (*subtract) (int, int), (*multiply) (int, int);
    double (*divide) (int, int);
	char *error;

	handle = dlopen("./code/libtest.so", RTLD_LAZY);
    
	if(!handle) {
		fputs (dlerror(), stderr);
		exit(1);
	}
	
    char* cal = (char*)malloc(10*sizeof(char)); // 글자 수
    int num1, num2; // 입력받을 숫자

    printf("무슨 연산을 할 것인가? (+, -, *, /) : ");
    scanf("%s", cal);

    printf("연산할 숫자 2개를 입력하시오 : ");
    scanf("%d %d", &num1, &num2);

    if(strcmp(cal, "+") == 0) {
        add = dlsym(handle, "add");

        if((error = dlerror()) != NULL) {
            fprintf(stderr, "%s", error);
            exit(1);
        }
        printf("add(%d,%d) = %d\n", num1, num2, (*add) (num1,num2));
    }else if(strcmp(cal, "-") == 0) {
        subtract = dlsym(handle, "subtract");

        if((error = dlerror()) != NULL) {
            fprintf(stderr, "%s", error);
            exit(1);
        }    
        printf("subtract(%d,%d) = %d\n", num1, num2, (*subtract) (num1,num2));
    }else if (strcmp(cal, "*") == 0) {
        multiply = dlsym(handle, "multiply");

        if((error = dlerror()) != NULL) {
            fprintf(stderr, "%s", error);
            exit(1);
        }
        printf("multiply(%d,%d) = %d\n", num1, num2, (*multiply) (num1,num2));
    } else if (strcmp(cal, "/") == 0) {
        divide = dlsym(handle, "divide");

        if((error = dlerror()) != NULL) {
            fprintf(stderr, "%s", error);
            exit(1);
        }
        printf("divide(%d, %d) = %lf\n", num1, num2, divide(num1,num2));
    }   
    
	dlclose(handle);
    
}