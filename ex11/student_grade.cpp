#include <numeric>
#include <iostream>
#include <map>
#include <iterator>

using namespace std;

typedef struct
{
    char name[20]; // 이름
    int mid; // 중간 점수
    int end; // 기말 점수
} STUDENT;

int main()
{
    map<int, STUDENT> students;

    int student_num = 0; // 학생 수

    cout << "학생 수를 입력하세요 : ";
    cin >> student_num;

    for (int i = 0; i < student_num; i++) {
        STUDENT student;
        
        cout << "학생 정보를 입력하시오 (이름, 중간, 기말) : ";
        cin >> student.name  >> student.mid >> student.end;
        

        students.emplace(i, student);        
        cout << "학생 추가 완료" << endl;
    }

    for(auto i = begin(students); i != end(students); i++)
        cout << "이름 : "  << i->second.name << " 중간 : " << i->second.mid << " 기말 : " << i->second.end << endl << endl;

    return 0;
}