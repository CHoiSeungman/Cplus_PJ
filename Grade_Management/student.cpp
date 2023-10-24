#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include <vector>
#include<algorithm>
//#include "student.h"
using namespace std;

class Student
{
public:
	char * name;
	int num;
	int ks;
	int es;
	int ms;
	int rank =1;

	Student(const char* name, int num, int ks, int es, int ms)//생성자
	{
		this->name = new char[strlen(name)+1];
		strcpy(this->name, name);
		this->num = num;
		this->ks = ks;
		this->es = es;
		this->ms = ms;
	}
	int getTotal() { return ks + es + ms; }//점수 합
	double getAverage() { return (ks+es+ms) / 3.0; }//점수 평균
	
	void showStudentInfo() {
		cout << "이름: " << name << "번호: " << num << "국어점수: " << ks << "영어점수: " << es << "수학점수: " << ms << "평균: " << getAverage() <<  endl;
	}
	int GetRank()const { return rank; }
	char* GetName() const { return name; }
	int GetNumber() const { return num; }
	void Close() { return exit(0); }
	void RankP() // 석차 한개 올림
	{
		rank++;
	}
	bool operator< (const Student& other) {
		return rank < other.rank;
	}
};
void Rank(Student a);
vector<Student> vs;

//1. 정보입력
void Student_Info()
{
	char stu_name[10];
	int stu_score1;
	int stu_score2;
	int stu_score3;
	int stu_score4;
	
	vector<Student>::iterator itr;
		cout << "학생의 이름 : ";
		cin >> stu_name;
		cout << "학생의 번호 : ";
		cin >> stu_score1;
		cout << "학생의 국어점수 : ";
		cin >> stu_score2;
		cout << "학생의 영어점수 : ";
		cin >> stu_score3;
		cout << "학생의 수학점수 : ";
		cin >> stu_score4;
		Student s(stu_name, stu_score1, stu_score2, stu_score3, stu_score4);
		// 총합 점수를 비교해서 석차를 구한다.
		// 비교하는 함수
		Rank(s);
		//vs.push_back(s);
}
//2. 입력된 정보 모두 출력
void AllPrint()
{
	vector<Student>::iterator itr;
	for (itr = vs.begin(); itr != vs.end(); itr++)
	{
		itr->showStudentInfo();
	}
}
//3. 이름검색
void NameSearch()
{
	vector<Student>::iterator itr;
	char search_name[10];

	cout << "이름을 입력하세요";
	cin >> search_name;

	for (itr = vs.begin(); itr != vs.end(); itr++)
	{
		if (strcmp(search_name, itr->GetName()) == 0) 
		{
			itr->showStudentInfo();
		}
	}
}
//4. 번호검색
void NumberSearch(){
	vector<Student>::iterator itr;
	int search_num;
	cout << "번호를 입력하세요.";
	cin >> search_num;
	for(itr=vs.begin();itr != vs.end();itr++)
		if (itr->GetNumber() == search_num)
		{
			itr->showStudentInfo();
		}
}
//5. 이름입력으로 평균 석차 출력
void Name_Avg()
{
	vector<Student>::iterator itr;
	char search_name[10];

	cout << "이름을 입력하세요";
	cin >> search_name;

	for (itr = vs.begin(); itr != vs.end(); itr++) {
		if (strcmp(search_name, itr->GetName()) == 0)
		{
			cout <<"이름: "<< search_name << ", " << "평균: " << itr->getAverage() << ", 석차 :" << itr->GetRank() << endl;
		}
	}
}
//6. 평균점수 평균 높은순으로 출력
void Rank(Student a)
{
	vector<Student>::iterator itr;
	for (itr = vs.begin(); itr != vs.end(); itr++)
	{
		if (a.getAverage() > (*itr).getAverage())
		{
			(*itr).RankP();
		}
		else if (a.getAverage() == (*itr).getAverage()) {}
		else
		{
			a.RankP();
		}
	}
	vs.push_back(a);
}
void Rank_Print()
{
	sort(vs.begin(), vs.end());
	AllPrint();
}

int main() {

	Student_Info();
	Student_Info();
	Student_Info();
	NameSearch();
	NumberSearch();
	Name_Avg();
	Rank_Print();
}