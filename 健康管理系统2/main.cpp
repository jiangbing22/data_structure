#include <iostream>
#include "studentlist.h" // 假设 studentlist 类的声明在 "studentlist.h" 中

using namespace std;

int main() {
    studentlist myList; // 创建学生列表对象

    while (true) {
        cout << "=======================" << endl;
        cout << "学生信息管理系统" << endl;
        cout << "=======================" << endl;
        cout << "1. 添加学生信息" << endl;
        cout << "2. 删除学生信息" << endl;
        cout << "3. 从文件读取学生信息" << endl;
        cout << "4. 将学生信息写入文件" << endl;
        cout << "5. 搜索学生" << endl;
        cout << "6. 查看学生信息" << endl;
        cout << "7. 查看所有学生信息" << endl;
        cout << "8. 退出" << endl;

        int choice;
        cout << "请选择操作: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // 添加学生信息
            student newStudent;
            cout << "请输入学生姓名: ";
            cin >> newStudent.name;
            cout << "请输入学生年龄: ";
            cin >> newStudent.age;
            cout << "请输入学生生日: ";
            cin >> newStudent.date;
            cout << "请输入学生健康信息: ";
            cin >> newStudent.health;
            cout << "请输入学生学号: ";
            cin >> newStudent.num;
            cout << "请输入学生性别: ";
            cin >> newStudent.sex;

            myList.pushback(newStudent);
            break;
        }
        case 2: {
            // 删除学生信息
            string name;
            cout << "请输入要删除学生的姓名: ";
            cin >> name;
            myList.delete_e(name);
            break;
        }
        case 3: {
            // 从文件读取学生信息
            string filePath;
            cout << "请输入文件路径: ";
            cin >> filePath;
            myList.readfile(filePath);
            break;
        }
        case 4: {
            // 将学生信息写入文件
            string filePath;
            cout << "请输入文件路径: ";
            cin >> filePath;
            myList.writefile(filePath);
            break;
        }
        case 5: {
            // 搜索学生
            string num;
            cout << "请输入要搜索的学生学号: ";
            cin >> num;
            myList.search_student(num);
            break;
        }
        case 6: {
            // 查看学生信息
            int index;
            cout << "请输入学生索引: ";
            cin >> index;
            myList.search_by_index(index);
            break;
        }
        case 7: {
            // 查看所有学生信息
            myList.print_all_students();
            break;
        }
        case 8: {
            // 退出程序
            return 0;
        }
        default: {
            cout << "无效的选择，请重新选择操作。" << endl;
            break;
        }
        }
    }

    return 0;
}
