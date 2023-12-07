#pragma once
#define Pnum 1000
#include<fstream>
#include<iostream>
#include<map>
#include<cstring>
#include<queue>
class adjacency_Matrix_Graph
{
private:
	std::map<std::string, int> vertex;
	std::string* index_to_vertex;
	int matrix[Pnum][Pnum];
	int vexnum, arcnum;
	bool D;
public:
	void create(char* filepath);
	int first_nei(std::string x);
	int next_nei(std::string x,std::string y);
	void BFS(std::string x);
	void DFS(std::string x);




};

