#include "adjacency_List_Graph.h"

void adjacency_List_Graph::create(char* filepath) {
    std::ifstream txt_reader(filepath);
    if (!txt_reader.is_open()) {
        std::cerr << "无法打开文件" << std::endl;
        return; // 返回错误代码
    }

    int vexnum, arcnum;
    txt_reader >> vexnum >> arcnum;

    std::cout << "节点个数:" << vexnum << "弧的条数：" << arcnum << std::endl;
    txt_reader >> D;

    if (D) {
        std::cout << "图为有向图" << std::endl;
    }
    else {
        std::cout << "图为无向图" << std::endl;
    }

    std::cout << "图的节点:";
    for (int i = 0; i < vexnum; i++) {
        std::string temp;
        txt_reader >> temp;

        adjacency_List_Node* newNode = new adjacency_List_Node(temp);
        vertices[temp] = newNode;

        std::cout << i << temp << std::endl;
    }

    for (int i = 0; i < arcnum; i++) {
        std::string P1, P2;
        txt_reader >> P1 >> P2;

        adjacency_List_Node* newNode = new adjacency_List_Node(P2);
        newNode->next = vertices[P1];
        vertices[P1] = newNode;
    }
}

int adjacency_List_Graph::first_nei(std::string x) {
    if (vertices.find(x) != vertices.end()) {
        adjacency_List_Node* current = vertices[x];
        if (current != nullptr) {
            return vertices[x]->vertex;
        }
    }
    return -1;
}

int adjacency_List_Graph::next_nei(std::string x, std::string y) {
    if (vertices.find(x) != vertices.end()) {
        adjacency_List_Node* current = vertices[x];
        while (current != nullptr && current->vertex != y) {
            current = current->next;
        }

        if (current != nullptr && current->next != nullptr) {
            return current->next->vertex;
        }
    }
    return -1;
}

void adjacency_List_Graph::BFS(std::string x) {
    std::queue<std::string> q;
    std::map<std::string, bool> visited;

    std::cout << "BFS顺序: ";
    q.push(x);
    visited[x] = true;

    while (!q.empty()) {
        std::string front = q.front();
        q.pop();

        std::cout << front << " ";

        if (vertices.find(front) != vertices.end()) {
            adjacency_List_Node* current = vertices[front];
            while (current != nullptr) {
                if (!visited[current->vertex]) {
                    q.push(current->vertex);
                    visited[current->vertex] = true;
                }
                current = current->next;
            }
        }
    }
    std::cout << std::endl;
}

void adjacency_List_Graph::DFS(std::string x) {
    if (vertices.find(x) != vertices.end()) {
        std::map<std::string, bool> visited;
        DFSHelper(x, visited);
    }
}

void adjacency_List_Graph::DFSHelper(std::string x, std::map<std::string, bool>& visited) {
    visited[x] = true;
    std::cout << x << " ";

    if (vertices.find(x) != vertices.end()) {
        adjacency_List_Node* current = vertices[x];
        while (current != nullptr) {
            if (!visited[current->vertex]) {
                DFSHelper(current->vertex, visited);
            }
            current = current->next;
        }
    }
}
