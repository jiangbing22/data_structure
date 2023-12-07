#pragma once
#define Pnum 1000
#include <fstream>
#include <iostream>
#include <map>
#include <list>
#include <cstring>
#include <queue>

class adjacency_List_Node {
public:
    std::string vertex;
    adjacency_List_Node* next;

    adjacency_List_Node(std::string v) : vertex(v), next(nullptr) {}
};

class adjacency_List_Graph {
private:
    std::map<std::string, adjacency_List_Node*> vertices;
    bool D;

public:
    void create(char* filepath);
    int first_nei(std::string x);
    int next_nei(std::string x, std::string y);
    void BFS(std::string x);
    void DFS(std::string x);
};

