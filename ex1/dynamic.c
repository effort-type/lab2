/* dynamic.c */

#include <stdio.h>
#include <stdlib.h> // exit() 사용하기 위함
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
	
	add = dlsym(handle, "add");

	if((error = dlerror()) != NULL) {
		fprintf(stderr, "%s", error);
		exit(1);
	}

	subtract = dlsym(handle, "subtract");

	if((error = dlerror()) != NULL) {
		fprintf(stderr, "%s", error);
		exit(1);
	}

    multiply = dlsym(handle, "multiply");

	if((error = dlerror()) != NULL) {
		fprintf(stderr, "%s", error);
		exit(1);
	}

    divide = dlsym(handle, "divide");

	if((error = dlerror()) != NULL) {
		fprintf(stderr, "%s", error);
		exit(1);
	}

	printf("add(1,2) = %d\n", (*add) (1,2));
	printf("subtract(1,2) = %d\n", (*subtract) (1,2));
    printf("multiply(1,2) = %d\n", (*multiply) (1,2));
    printf("divide(2, 1) = %lf\n", divide(2, 1));
	dlclose(handle);
    
}