#include"Btree.hpp"
using namespace std;
void printnode(node<int>* current)
{
    std::cout << current->data;
}
int main() {
    Btree<int> tree;
    int choice;
    while (true) {
        cout << "=======================" << endl;
        cout << "�������ṹ" << endl;
        cout << "=======================" << endl;
        cout << "1. ������" << endl;
        cout << "2. ǰ������ݹ��㷨" << endl;
        cout << "3. ǰ������ǵݹ��㷨" << endl;
        cout << "4. ��������ݹ��㷨" << endl;
        cout << "5.��������ǵݹ��㷨" << endl;
        cout << "6. ��������ݹ��㷨" << endl;
        cout << "7. ��������ǵݹ��㷨" << endl;
        cout << "8. ������" << endl;
        cout << "9. ��Ҷ������" << endl;
        cout << "10. ���������" << endl;
        cout << "11. �˳�" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "����Ҫ����Ľڵ�ֵ" << endl;
            int temp;
            cin >> temp;
            tree.insert_node(temp);

            break;
        case 2:
            // ǰ������ݹ��㷨
            tree.r_preordered();
            break;
        case 3:
            tree.f_preordered();
            break;
        case 4:
            tree.r_inordered();
            break;
        case 5:
            tree.f_inordered();
            break;
        case 6:
            tree.r_postordered();
            break;
        case 7:
            tree.f_postordered();
            break;
        case 8:
            std::cout<<"���ĸ߶�Ϊ:" << tree.get_height();
            break;
        case 9:
            std::cout<<"Ҷ�ӵ�����Ϊ:" << tree.count_leaves();
            break;
        case 10:
            tree.print_trees();
            break;
        case 11:
            // �˳�
            return 0;
        default:
            cout << "��Ч��ѡ�����������롣" << endl;
        }
    }
    return 0;
};