#include "studentlist.h"
studentlist::studentlist(int default_cap)
{

	capacity = default_cap;
	elements = new student[capacity];
	size = 0;
}

studentlist::~studentlist()
{
	delete[] elements;
}

void studentlist::pushback(student element)
{
	if (size >= capacity)
	{
		int newcapacity = capacity * 2;
		student* newelements = new student[newcapacity];
		for (int i = 0; i < size; i++)
		{
			newelements[i] = elements[i];
		}
		delete[]elements;
		elements = newelements;
		capacity = newcapacity;
		cout << "扩容成功" << endl;

	}
	elements[size++] = element;
}

void studentlist::delete_e(string name)
{
	for (int i = 0; i < size; i++)
	{
		if (elements[i].name == name)
		{
			for (int j = i; j < size; j++)
			{
				elements[j] = elements[j + 1];
			}
			size--;
			return;
		}

	}
	cout << "students not found" << endl;
	return;
}

void studentlist::readfile(const string& file_path)
{
	ifstream file(file_path);
	if (!file)
	{
		cout << "无法打开文件" << endl;
		return;
	}

	// 逐行读取文件内容，然后创建学生对象并将其添加到列表中
	while (!file.eof())
	{
		student new_student;
		getline(file, new_student.name, ',');
		getline(file, new_student.age, ',');
		getline(file, new_student.date, ',');
		getline(file, new_student.health, ',');
		getline(file, new_student.num, ',');
		getline(file, new_student.sex);

		pushback(new_student);
	}

	file.close();
}

void studentlist::writefile(const string& file_path) const
{
	ofstream file(file_path);
	if (!file)
	{
		cout << "无法打开文件" << endl;
		return;
	}

	// 遍历学生列表并将每个学生的信息写入文件
	for (int i = 0; i < size; i++)
	{
		file << elements[i].name << "," << elements[i].age << ","
			<< elements[i].date << "," << elements[i].health << ","
			<< elements[i].num << "," << elements[i].sex << endl;
	}

	file.close();
}

void studentlist::search_student(string num)
{
	for (int i = 0; i < size; i++)
	{
		if (num == elements[i].num)
		{
			printstudent(i);
			return;
		}
	}
	cout << "找不到学号为" << num << "的学生";
}

void studentlist::printstudent(int index) const
{
	cout << "姓名:" << elements[index].name;
	cout << "年龄:" << elements[index].age;
	cout << "性别:" << elements[index].sex;
	cout << "学号:" << elements[index].num;
	cout << "健康状况:" << elements[index].health<<endl;
}

void studentlist::print_all_students()
{
	if (size == 0)
	{
		cout << "列表为空" << endl;
		return;
	}
	for (int i = 0; i < size; i++)
	{
		printstudent(i);
	}
}
