/*
    lab2 실습 5번 문제
    파일 이름 : perror_use.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void m_perror(const char *str)
{
    fprintf(stderr, "%s : %s\n", str, strerror(errno));
}

void main(int argc, char *argv[])
{
    FILE *f;

    if(argc < 2) {
        printf("Usage: perror_use file_name\n");
        exit(1);
    }

    if((f = fopen(argv[1], "r")) == NULL) {
        m_perror("fopen");
        exit(1);
    }

    printf("Open a file \"%s\".\n", argv[1]);

    fclose(f);
}