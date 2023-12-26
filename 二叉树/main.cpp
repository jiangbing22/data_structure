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
        cout << "二叉树结构" << endl;
        cout << "=======================" << endl;
        cout << "1. 建立树" << endl;
        cout << "2. 前序遍历递归算法" << endl;
        cout << "3. 前序遍历非递归算法" << endl;
        cout << "4. 中序遍历递归算法" << endl;
        cout << "5.中序遍历非递归算法" << endl;
        cout << "6. 后序遍历递归算法" << endl;
        cout << "7. 后序遍历非递归算法" << endl;
        cout << "8. 求树高" << endl;
        cout << "9. 求叶子总数" << endl;
        cout << "10. 输出二叉树" << endl;
        cout << "11. 退出" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "输入要插入的节点值" << endl;
            int temp;
            cin >> temp;
            tree.insert_node(temp);

            break;
        case 2:
            // 前序遍历递归算法
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
            std::cout<<"树的高度为:" << tree.get_height();
            break;
        case 9:
            std::cout<<"叶子的数量为:" << tree.count_leaves();
            break;
        case 10:
            tree.print_trees();
            break;
        case 11:
            // 退出
            return 0;
        default:
            cout << "无效的选择，请重新输入。" << endl;
        }
    }
    return 0;
};