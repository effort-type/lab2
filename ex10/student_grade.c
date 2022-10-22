/*
    문제 : 학생 수를 입력받은 다음, 학생의 이름, 중간, 기말 점수를 기록하는 구조체를
           학생 수만큼 동적으로 할당받아서, 이를 트리 구조체로 활용하여 트리 탐색을
           할 수 있는 프로그램을 작성하시오.
    
    파일 이름 : student_grade.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>

typedef struct
{
    char* name; // 이름
    int mid; // 중간 점수
    int end; // 기말 점수
} STUDENT;

STUDENT* nodetable;
STUDENT* root = NULL; // 루트 노드

int compare(const void *cp1, const void *cp2)
{
    return strcmp(((STUDENT *)cp1)->name, ((STUDENT *)cp2) ->name);
}

void print_node(const void *nodeptr, VISIT order, int level)
{
    if(order == preorder || order == leaf)
        printf("이름 = %-20s, 중간 점수 = %3d, 기말 점수 = %3d\n", (*(STUDENT **)nodeptr)->name, (*(STUDENT **)nodeptr)->mid, (*(STUDENT **)nodeptr)->end);
}

void main()
{
    int student_num = 0; // 학생 수

    printf("학생 수를 입력하세요 : ");
    scanf("%d", &student_num);

    char *name = (char *)malloc(sizeof(char) * 20);
    nodetable = (STUDENT*)malloc(sizeof(STUDENT) * student_num);
    
    STUDENT *nodeptr = nodetable;
    STUDENT **ret;

    for(int i = 0; i < student_num; i++) {

        printf("학생 정보 입력(이름, 중간, 기말) : ");
        scanf("%s %d %d", name, &nodeptr->mid, &nodeptr->end);
        nodeptr->name = name;

        // 트리에 넣기
        ret = (STUDENT **) tsearch((void*) nodeptr, (void**) &root, compare);

        if(*ret == nodeptr){
            printf("학생 추가 완료\n");
            name += strlen(name) + 1;
            nodeptr++;
        }
    }

    twalk((void*) root, print_node);
    
}