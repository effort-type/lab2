/*
    문제 : 두 행렬의 크기를 입력받아서 필요한 만큼의 메모리를 동적으로 할당하여 행렬의 내용을 저장하고
           두 행렬을 더하는 프로그램을 작성하시오. (벡터사용)
    
    파일 이름 : matrix.cpp
*/

#include <iostream>
#include <vector>
using namespace std;

void matrixSum(vector<vector<int>> &a, vector<vector<int>> &b, vector<vector<int>> &result)
{
    for(int i = 0; i < a.size(); i++) {    
        vector<int> matrix_temp;    
        for(int j = 0; j < a[i].size(); j++) {
            int sum = a.at(i).at(j) + b.at(i).at(j);
            matrix_temp.push_back(sum);
        }
        result.push_back(matrix_temp);
    }
}

int main()
{
    int row; // 행
    int column; // 열
    
    cout << "행을 입력하시오 : ";
    cin >> row;
    cout << "열을 입력하시오 : ";
    cin >> column;

    vector<vector<int>> matrix1;
    vector<vector<int>> matrix2;
    vector<vector<int>> result_matrix;
    

    cout << "-----------matrix1-----------"<<endl;
    for(int i = 0; i < row; i++) {
        vector<int> matrix_column;
        for(int j = 0; j < column; j++) {
            int temp = 0;
            cout << "[" << i <<"][" << j << "]값을 입력하시오 : ";
            cin >> temp;
            matrix_column.push_back(temp);
        }
        matrix1.push_back(matrix_column);
    }

    cout << "-----------matrix2-----------"<<endl;
    for(int i = 0; i < row; i++) {
        vector<int> matrix_column;
        for(int j = 0; j < column; j++) {
            int temp = 0;
            cout << "[" << i <<"][" << j << "]값을 입력하시오 : ";
            cin >> temp;
            matrix_column.push_back(temp);
        }
        matrix2.push_back(matrix_column);
    }
    
    matrixSum(matrix1, matrix2, result_matrix);

    cout << "-----------matrix1-----------"<<endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            cout << matrix1.at(i).at(j) << "\t";
        }
        cout << endl;
    }

    cout << "-----------matrix2-----------"<<endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            cout << matrix2.at(i).at(j) << "\t";
        }
        cout << endl;
    }

    cout << "-----------result-----------"<<endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            cout << result_matrix.at(i).at(j) << "\t";
        }
        cout << endl;
    }

    

    return 0;
}