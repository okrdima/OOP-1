#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct Student
{
	string name, surname, addres, gender, gruppa, phone, date_birthday, kurs;
	int mark, biologik, mathematic, english, spanich;
};

void RW(Student *student, int n, const char *file_name);// перша реалізація 
void RD(Student *student, int n, const char *file_name);// перша реалізація
void RW(int n, string file_name);//друга реалізація 
void RD(Student *student, int N, string file_name1, string **student_mark);// друга реалізація

int main()
{
	int N;
	const char *file_name1 = "INFO.dat";
	string file_name2 = "INFO.txt";
	cout << "Enter number of students: ";
	cin >> N;

	Student *student, *student1,*stundentbinary;
	student = new Student[N];
	student1 = new Student[N];
	string **student_mark = new string*[N];
	for (int i = 0; i < N; i++)
	student_mark[i] = new string[6];
	RW(student, N, file_name1);
	RD(student1, N, file_name1);

	cout << "\n\n";
	cout << "Enter name and mark:\n";
	RW(N, file_name2);
	RD(student1, N, file_name2,student_mark);
	cin.get();
	cin.get();
	return 0;
}
void RW(Student *student, int N, const char *file_name)// перша реалізація функції 
{
	int i = 0;
	while (i < N)
	{
		cout << " Enter name: ";
		cin >> student[i].name;
		cout << "Enter Kurs:";
		cin >> student[i].kurs;
		cout << "Enter surname:";
		cin >> student[i].surname;
		cout << " Enter addres:";
		cin >> student[i].addres;
		cout << "Enter gender:";
		cin >> student[i].gender;
		cout << " Enter gruppa: ";
		cin >> student[i].gruppa;
		cout << "Enter phone:";
		cin >> student[i].phone;
		cout << "Enter Date Birthday:";
		cin >> student[i].date_birthday;
		cout << "Enter mark biologik:";
		cin >> student[i].biologik;
		cout << "Enter mark mathematik:";
		cin >> student[i].mathematic;
		cout << "Enter mark spanich:";
		cin >> student[i].spanich;
		cout << "Enter mark english:";
		cin >> student[i].english;
		cout << " " << endl;
		i++;
	}
	FILE *f = fopen(file_name, "wb");
	if (!f)
	{
		cout << "Error";
		system("pause");
		exit(1);
	}
	fwrite(&student, sizeof(student), 1, f);
	fclose(f);
}
void RD(Student *student, int N, const char *file_name)
{
	string temp;
	FILE *f1 = fopen(file_name, "rb");
	if (f1 == NULL)
	{
		cout << "Error";
		system("pause");
		exit(1);
	}
	fread(&student, sizeof(student), 1, f1);
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (student[i].kurs > student[j].kurs)
			{
				temp = student[i].kurs;
				student[i].kurs = student[j].kurs;
				student[j].kurs = temp;

				
					temp = student[i].name;
				student[i].name = student[j].name;
				student[j].name = temp;
			}
		}
	}
	cout << "Sort for kurs \n";
	for (int i = 0; i < N; i++)
	{
		cout << "Name:" << student[i].name << "\tKurs:" << student[i].kurs << "\n";
	}
	fclose(f1);
}
void RW(int N, string file_name1)
{
	int i = 0;
	string surname, biologik, english, spanich, french, phizik;
	ofstream File(file_name1);
	while (i < N)
	{
		cout << "surname: ";
		cin >> surname;
		File << surname << ' ';
		cout << "Enter mark biologik: " << " ";
		cin >> biologik;
		File << biologik << ' ';
		cout << "Enter mark english: " << " ";
		cin >> english;
		File << english << ' ';
		cout << "Enter mark biologik: " << " ";
		cin >> spanich;
		File << spanich << ' ';
		cout << "Enter mark french: " << " ";
		cin >> french;
		File << french << ' ';
		cout << "Enter mark phizik: " << " ";
		cin >> phizik;
		File << phizik << ' ';
		i++;
	}
	File.close();
	
}
void RD(Student *student, int N, string file_name1, string **student_mark)
{
	int i = 0, j = 0;
	ifstream File(file_name1);
	if (!File)
	{
		cout << "Error";
		exit(1);
	}
	else
	{
		i == 0;
		while (i < N)
		{
			getline(File, student_mark[i][j], ' ');
			getline(File, student_mark[i][j + 1], ' ');
			getline(File, student_mark[i][j + 2], ' ');
			getline(File, student_mark[i][j + 3], ' ');
			getline(File, student_mark[i][j + 4], ' ');
			getline(File, student_mark[i][j + 5], ' ');
			i++;
		}
		
		for (int i = 0; i < N; i++)
		{
			if (student_mark[i][j+1] == "4")
			{
				cout << "Mark 4:" << student_mark[i][j];
			}
		}
		File.close();
	}
}