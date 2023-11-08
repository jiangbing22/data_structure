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
	class linknode
	{
	public:
		student data;
		linknode* next;
		linknode(linknode* ptr = NULL) :next(ptr){}
		linknode(linknode* ptr, const student& s) :next(ptr), data(s) {}
	};
	linknode* first;
	student* elements;
	int size;
	int capacity;

public:
	studentlist();
	~studentlist();
	void pushback(student element);
	void delete_e(string name);
	void readfile(const string& file_path);
	void writefile(const string& file_path) const;
	void search_student(string num);
	void printstudent(linknode* index) const;
	void print_all_students();
	void search_by_index(int index);

};
