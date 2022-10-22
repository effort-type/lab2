/*
    lab2 6번 문제
    파일 이름 : assert_use.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void my_assert(int exp)
{
    // 참일 경우에는 실행하면 안되고, 참이 아닐 경우에는 실행해야하기때문에 not
    if(!exp) {
        // assert() 함수는 결과에 파일명, 함수명, 호출된 줄 수 정보 출력함
        // __FILE__ : 파일명
        // __func__ : 함수명
        // __LINE__ : 줄 수
         
        printf("%s %s %d\n", __FILE__, __func__, __LINE__);
        exit(1);
    }
}

void foo(int num)
{
    my_assert(((num >= 0) && (num <= 100)));
    printf("foo num = %d\n", num);
}


void main(int argc, char *argv[])
{
    int num;

    if(argc < 2) {
        fprintf(stderr, "Usage: assert_test aNumber\n(0 <= aNumber <= 100)=n");
        exit(1);
    }

    num = atoi(argv[1]);
    foo(num);
}