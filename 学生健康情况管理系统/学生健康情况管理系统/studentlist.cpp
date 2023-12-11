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
		cout << "���ݳɹ�" << endl;

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
		cout << "�޷����ļ�" << endl;
		return;
	}

	// ���ж�ȡ�ļ����ݣ�Ȼ�󴴽�ѧ�����󲢽�����ӵ��б���
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
		cout << "�޷����ļ�" << endl;
		return;
	}

	// ����ѧ���б���ÿ��ѧ������Ϣд���ļ�
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
	cout << "�Ҳ���ѧ��Ϊ" << num << "��ѧ��";
}

void studentlist::printstudent(int index) const
{
	cout << "����:" << elements[index].name;
	cout << "����:" << elements[index].age;
	cout << "�Ա�:" << elements[index].sex;
	cout << "ѧ��:" << elements[index].num;
	cout << "����״��:" << elements[index].health<<endl;
}

void studentlist::print_all_students()
{
	if (size == 0)
	{
		cout << "�б�Ϊ��" << endl;
		return;
	}
	for (int i = 0; i < size; i++)
	{
		printstudent(i);
	}
}
