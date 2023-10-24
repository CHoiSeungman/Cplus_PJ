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

	Student(const char* name, int num, int ks, int es, int ms)//������
	{
		this->name = new char[strlen(name)+1];
		strcpy(this->name, name);
		this->num = num;
		this->ks = ks;
		this->es = es;
		this->ms = ms;
	}
	int getTotal() { return ks + es + ms; }//���� ��
	double getAverage() { return (ks+es+ms) / 3.0; }//���� ���
	
	void showStudentInfo() {
		cout << "�̸�: " << name << "��ȣ: " << num << "��������: " << ks << "��������: " << es << "��������: " << ms << "���: " << getAverage() <<  endl;
	}
	int GetRank()const { return rank; }
	char* GetName() const { return name; }
	int GetNumber() const { return num; }
	void Close() { return exit(0); }
	void RankP() // ���� �Ѱ� �ø�
	{
		rank++;
	}
	bool operator< (const Student& other) {
		return rank < other.rank;
	}
};
void Rank(Student a);
vector<Student> vs;

//1. �����Է�
void Student_Info()
{
	char stu_name[10];
	int stu_score1;
	int stu_score2;
	int stu_score3;
	int stu_score4;
	
	vector<Student>::iterator itr;
		cout << "�л��� �̸� : ";
		cin >> stu_name;
		cout << "�л��� ��ȣ : ";
		cin >> stu_score1;
		cout << "�л��� �������� : ";
		cin >> stu_score2;
		cout << "�л��� �������� : ";
		cin >> stu_score3;
		cout << "�л��� �������� : ";
		cin >> stu_score4;
		Student s(stu_name, stu_score1, stu_score2, stu_score3, stu_score4);
		// ���� ������ ���ؼ� ������ ���Ѵ�.
		// ���ϴ� �Լ�
		Rank(s);
		//vs.push_back(s);
}
//2. �Էµ� ���� ��� ���
void AllPrint()
{
	vector<Student>::iterator itr;
	for (itr = vs.begin(); itr != vs.end(); itr++)
	{
		itr->showStudentInfo();
	}
}
//3. �̸��˻�
void NameSearch()
{
	vector<Student>::iterator itr;
	char search_name[10];

	cout << "�̸��� �Է��ϼ���";
	cin >> search_name;

	for (itr = vs.begin(); itr != vs.end(); itr++)
	{
		if (strcmp(search_name, itr->GetName()) == 0) 
		{
			itr->showStudentInfo();
		}
	}
}
//4. ��ȣ�˻�
void NumberSearch(){
	vector<Student>::iterator itr;
	int search_num;
	cout << "��ȣ�� �Է��ϼ���.";
	cin >> search_num;
	for(itr=vs.begin();itr != vs.end();itr++)
		if (itr->GetNumber() == search_num)
		{
			itr->showStudentInfo();
		}
}
//5. �̸��Է����� ��� ���� ���
void Name_Avg()
{
	vector<Student>::iterator itr;
	char search_name[10];

	cout << "�̸��� �Է��ϼ���";
	cin >> search_name;

	for (itr = vs.begin(); itr != vs.end(); itr++) {
		if (strcmp(search_name, itr->GetName()) == 0)
		{
			cout <<"�̸�: "<< search_name << ", " << "���: " << itr->getAverage() << ", ���� :" << itr->GetRank() << endl;
		}
	}
}
//6. ������� ��� ���������� ���
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