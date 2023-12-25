#include <iostream>
#include "adjacency_Matrix.h"
char filepath[100];
int main() {
    


    // ��ȡ�ļ�·��
    std::cout << "�������ļ�·����";
    std::cin >> filepath;
    adjacency_Matrix_Graph myGraph(filepath);
    // ����ͼ�����ļ��ж�ȡ����
  

    // �����н�������
    while (true) {
        std::cout << "\n��ѡ�����:\n";
        std::cout << "1. ����BFS����\n";
        std::cout << "2. ����DFS����\n";
        std::cout << "0. �˳�\n";

        int choice;
        std::cout << "������ѡ��(0-2): ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            char bfs_start_vertex;
            std::cout << "������BFS��������ʼ�ڵ�: ";
            std::cin >> bfs_start_vertex;
            myGraph.BFS(bfs_start_vertex);
            break;
        }
        case 2: {
            char dfs_start_vertex;
            std::cout << "������DFS��������ʼ�ڵ�: ";
            std::cin >> dfs_start_vertex;
            myGraph.DFS(dfs_start_vertex);
            break;
        }
        case 0:
            std::cout << "�����˳�\n";
            return 0;
        default:
            std::cerr << "��Ч��ѡ������������\n";
        }
    }

    return 0;
}
