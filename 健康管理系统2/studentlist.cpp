#include "studentlist.h"
studentlist::studentlist()
{
	first = new linknode;
	if (first == NULL)
	{
		cout << "�����ڴ�ʧ��\n";
		return;
	}
	
}

studentlist::~studentlist()
{
	linknode* current = first;
	while (current != NULL)
	{
		linknode* next = current->next;
		delete current;
		current = next;
	}
}


void studentlist::pushback(student element)
{
	linknode* newnode = new linknode;
	newnode->data = element;
	newnode->next = first->next;
	first->next = newnode;

}

void studentlist::delete_e(string name)
{
	linknode* temp = first;
	linknode* prev = NULL;

	while (temp->next != nullptr)
	{
		if (temp->next->data.name == name)
		{
			linknode* toDelete = temp->next;
			temp->next = temp->next->next;
			delete toDelete;
			return;
		}

		prev = temp;
		temp = temp->next;
	}

	cout << "ѧ��δ�ҵ�" << endl;
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
	linknode* temp = first->next;
	// ����ѧ���б���ÿ��ѧ������Ϣд���ļ�
	while(temp!=NULL)
	{
		file << temp->data.name << "," << temp->data.age << ","
			<< temp->data.date << "," << temp->data.health << ","
			<< temp->data.num << "," << temp->data.sex << endl;
		temp = temp->next;
	}

	file.close();
}

void studentlist::search_student(string num)
{
	linknode* temp = first;
	while (temp != NULL)
	{
		if (temp->data.num == num)
		{
			printstudent(temp);
		}
		temp = temp->next;
	}
	cout << "�Ҳ���ѧ��Ϊ" << num << "��ѧ��";
}

void studentlist::printstudent(linknode* index) const
{
	cout << "����:" << index->data.name;
	cout << "����:" << index->data.age;
	cout << "�Ա�:" << index->data.sex;
	cout << "ѧ��:" << index->data.num;
	cout << "����״��:" << index->data.health<<endl;
}

void studentlist::print_all_students()
{
	if (first->next==NULL)
	{
		cout << "�б�Ϊ��" << endl;
		return;
	}
	linknode* temp = first;
	while (temp != NULL)
	{
		printstudent(temp);
		temp = temp->next;
	}
}
void studentlist::search_by_index(int index)
{
	if (index < 0)
	{
		cout << "������Ч" << endl;
		return;
	}

	int currentIndex = 0;
	linknode* temp = first;

	while (temp != NULL)
	{
		if (currentIndex == index)
		{
			printstudent(temp);
			return; // �ҵ�ѧ���󷵻�
		}

		currentIndex++;
		temp = temp->next;
	}

	cout << "����������Χ" << endl;
}
