#pragma once
#define Pnum 20
#include<fstream>
#include<iostream>
#include<map>
#include<cstring>
#include<queue>
class adjacency_Matrix_Graph
{
private:
	std::map<char, int> vertex;
	char *index_to_vertex=nullptr;
	int matrix[Pnum][Pnum];
	int vexnum, arcnum;
	bool D;
	
public:
	adjacency_Matrix_Graph(char* filepath)
	{
		create(filepath);
	}
	~adjacency_Matrix_Graph()
	{

	}
	void create(char* filepath);
	int first_nei(char x); 
	int next_nei(char x, char y);
	void BFS(char x);
	void DFS(char x);




};

