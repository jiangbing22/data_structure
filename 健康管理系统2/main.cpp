#include <iostream>
#include "studentlist.h" // ���� studentlist ��������� "studentlist.h" ��

using namespace std;

int main() {
    studentlist myList; // ����ѧ���б����

    while (true) {
        cout << "=======================" << endl;
        cout << "ѧ����Ϣ����ϵͳ" << endl;
        cout << "=======================" << endl;
        cout << "1. ���ѧ����Ϣ" << endl;
        cout << "2. ɾ��ѧ����Ϣ" << endl;
        cout << "3. ���ļ���ȡѧ����Ϣ" << endl;
        cout << "4. ��ѧ����Ϣд���ļ�" << endl;
        cout << "5. ����ѧ��" << endl;
        cout << "6. �鿴ѧ����Ϣ" << endl;
        cout << "7. �鿴����ѧ����Ϣ" << endl;
        cout << "8. �˳�" << endl;

        int choice;
        cout << "��ѡ�����: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // ���ѧ����Ϣ
            student newStudent;
            cout << "������ѧ������: ";
            cin >> newStudent.name;
            cout << "������ѧ������: ";
            cin >> newStudent.age;
            cout << "������ѧ������: ";
            cin >> newStudent.date;
            cout << "������ѧ��������Ϣ: ";
            cin >> newStudent.health;
            cout << "������ѧ��ѧ��: ";
            cin >> newStudent.num;
            cout << "������ѧ���Ա�: ";
            cin >> newStudent.sex;

            myList.pushback(newStudent);
            break;
        }
        case 2: {
            // ɾ��ѧ����Ϣ
            string name;
            cout << "������Ҫɾ��ѧ��������: ";
            cin >> name;
            myList.delete_e(name);
            break;
        }
        case 3: {
            // ���ļ���ȡѧ����Ϣ
            string filePath;
            cout << "�������ļ�·��: ";
            cin >> filePath;
            myList.readfile(filePath);
            break;
        }
        case 4: {
            // ��ѧ����Ϣд���ļ�
            string filePath;
            cout << "�������ļ�·��: ";
            cin >> filePath;
            myList.writefile(filePath);
            break;
        }
        case 5: {
            // ����ѧ��
            string num;
            cout << "������Ҫ������ѧ��ѧ��: ";
            cin >> num;
            myList.search_student(num);
            break;
        }
        case 6: {
            // �鿴ѧ����Ϣ
            int index;
            cout << "������ѧ������: ";
            cin >> index;
            myList.search_by_index(index);
            break;
        }
        case 7: {
            // �鿴����ѧ����Ϣ
            myList.print_all_students();
            break;
        }
        case 8: {
            // �˳�����
            return 0;
        }
        default: {
            cout << "��Ч��ѡ��������ѡ�������" << endl;
            break;
        }
        }
    }

    return 0;
}
