#include <iostream>
#include "adjacency_Matrix.h"
char filepath[100];
int main() {
    


    // 读取文件路径
    std::cout << "请输入文件路径：";
    std::cin >> filepath;
    adjacency_Matrix_Graph myGraph(filepath);
    // 创建图，从文件中读取数据
  

    // 命令行交互界面
    while (true) {
        std::cout << "\n请选择操作:\n";
        std::cout << "1. 进行BFS遍历\n";
        std::cout << "2. 进行DFS遍历\n";
        std::cout << "0. 退出\n";

        int choice;
        std::cout << "请输入选择(0-2): ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            char bfs_start_vertex;
            std::cout << "请输入BFS遍历的起始节点: ";
            std::cin >> bfs_start_vertex;
            myGraph.BFS(bfs_start_vertex);
            break;
        }
        case 2: {
            char dfs_start_vertex;
            std::cout << "请输入DFS遍历的起始节点: ";
            std::cin >> dfs_start_vertex;
            myGraph.DFS(dfs_start_vertex);
            break;
        }
        case 0:
            std::cout << "程序退出\n";
            return 0;
        default:
            std::cerr << "无效的选择，请重新输入\n";
        }
    }

    return 0;
}
