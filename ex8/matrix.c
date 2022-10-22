/*
    문제 : 두 행렬의 크기를 입력받아서 필요한 만큼의 메모리를 동적으로 할당하여 행렬의 내용을 저장하고
           두 행렬을 더하는 프로그램을 작성하시오
    
    파일 이름 : matrix.c
*/

#include <stdio.h>
#include <stdlib.h>

void matrixSum(int row, int column, int** matrix1, int** matrix2)
{
    int result[row][column];

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }    

    printf("-----------matrix Sum-----------\n");
    for(int i = 0; i < row; i++) {
        
        for(int j = 0; j < column; j++) {
            printf("%5d", result[i][j]);    
        }
        printf("\n");
    }
}

static int num = 0;
void printMatrix(int** matrix, int column, int row)
{
    printf("-----------matrix%d-----------\n", num+1);
    for(int i = 0; i < row; i++) {
        
        for(int j = 0; j < column; j++) {
            printf("%5d", matrix[i][j]);    
        }
        printf("\n");
    }    
    num++;
}

void main()
{
    int row; // 행
    int column; // 열
    
    printf("행과 열을 입력하세요 (row, column) : ");
    scanf("%d %d", &row, &column);

    int **matrix1;
    int **matrix2;

    // matrix1 동적 메모리 할당 (2차원 배열)
    matrix1 = (int **) malloc (sizeof(int*) * row);

    // matrix2 동적 메모리 할당 (2차원 배열)
    matrix2 = (int **) malloc (sizeof(int*) * row);

    for(int i = 0; i < column; i++) {
        matrix1[i] = (int*) malloc (sizeof(int) * column);
        matrix2[i] = (int*) malloc (sizeof(int) * column);
    }

    // 값 입력 받기
    for(int i = 0; i < row; i++) {
        
        for(int j = 0; j < column; j++) {
            printf("matrix1 [%d][%d] 값을 입력하시오 : ", i, j);    
            scanf("%d", &matrix1[i][j]);
        }
    }
    for(int i = 0; i < row; i++) {
        
        for(int j = 0; j < column; j++) {
            printf("matrix2 [%d][%d] 값을 입력하시오 : ", i, j);    
            scanf("%d", &matrix2[i][j]);
        }
    }

    printMatrix(matrix1, column, row);
    printMatrix(matrix2, column, row);

    matrixSum(row, column, matrix1, matrix2);

    // matrix 동적메모리 반환
    for(int i = 0; i < column; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);
}