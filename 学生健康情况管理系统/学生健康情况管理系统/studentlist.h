#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;








class student
{
public:
	string name;
	string age;
	string date;
	string health;
	string num;
	string sex;
};
class studentlist
{
private:
	student* elements;
	int size;
	int capacity;

public:
	studentlist(int default_cap = 10);
	~studentlist();
	void pushback(student element);
	void delete_e(string name);
	void readfile(const string& file_path);
	void writefile(const string& file_path) const;
	void search_student(string num);
	void printstudent(int index) const;
	void print_all_students();

};
