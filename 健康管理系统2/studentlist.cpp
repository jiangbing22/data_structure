#include "studentlist.h"
studentlist::studentlist()
{
	first = new linknode;
	if (first == NULL)
	{
		cout << "分配内存失败\n";
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

	cout << "学生未找到" << endl;
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
	linknode* temp = first->next;
	// 遍历学生列表并将每个学生的信息写入文件
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
	cout << "找不到学号为" << num << "的学生";
}

void studentlist::printstudent(linknode* index) const
{
	cout << "姓名:" << index->data.name;
	cout << "年龄:" << index->data.age;
	cout << "性别:" << index->data.sex;
	cout << "学号:" << index->data.num;
	cout << "健康状况:" << index->data.health<<endl;
}

void studentlist::print_all_students()
{
	if (first->next==NULL)
	{
		cout << "列表为空" << endl;
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
		cout << "索引无效" << endl;
		return;
	}

	int currentIndex = 0;
	linknode* temp = first;

	while (temp != NULL)
	{
		if (currentIndex == index)
		{
			printstudent(temp);
			return; // 找到学生后返回
		}

		currentIndex++;
		temp = temp->next;
	}

	cout << "索引超出范围" << endl;
}
