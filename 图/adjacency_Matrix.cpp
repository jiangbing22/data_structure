#include "adjacency_Matrix.h"

void adjacency_Matrix_Graph::create(char* filepath)
{
	std::ifstream txt_reader(filepath);
	if (!txt_reader.is_open()) {
		std::cerr << "无法打开文件" << std::endl;
		return; // 返回错误代码
	}
	txt_reader >> vexnum >> arcnum;
	for (int i = 0; i < vexnum; i++)
	{
		for (int j = 0; j < vexnum; j++)
		{
			matrix[i][j] = 0;
		}
	}
	std::cout << "节点个数:" << vexnum << "弧的条数：" << arcnum << std::endl;
	txt_reader >> D;
	if (D)
	{
		std::cout << "图为有向图" << std::endl;

	}
	else
	{
		std::cout << "图为无向图" << std::endl;
	}
	std::cout << "图的节点:";
	for (int i = 0; i < vexnum; i++)
	{
		index_to_vertex = new std::string[vexnum];
		static std::string temp;
		txt_reader >> temp;
		index_to_vertex[i] = temp;
		vertex[temp] = i;
		std::cout << i << temp << std::endl;
	}
	for (int i = 0; i < arcnum; i++)
	{
		static std::string P1, P2;
		txt_reader >> P1>>P2;
		matrix[vertex[P1]][vertex[P2]] = 1;
	}


}

int adjacency_Matrix_Graph::first_nei(std::string x)
{
	int index = vertex[x];
	for (int i = 0; i < vexnum; i++)
	{
		if (matrix[index][i])
		{
			return i;
		}
	}
	return -1;
}

int adjacency_Matrix_Graph::next_nei(std::string x,std::string y)
{
	int index = vertex[x];
	int yindex = vertex[y];
	for (int i = yindex+1; i < vexnum; i++)
	{
		if (matrix[index][i])
		{
			return i;
		}
	}
	return -1;
}

void adjacency_Matrix_Graph::BFS(std::string x)
{
	bool visited[Pnum] = { false };
	int index = vertex[x];
	std::queue<int> q;
	std::cout << "BFS顺序: ";

	visited[index] = true;
	std::cout << x << " ";

	q.push(index);
	while (!q.empty())
	{
		int front = q.front();
		q.pop();

		for (int i = first_nei(index_to_vertex[front]); i != -1; i = next_nei(index_to_vertex[front], index_to_vertex[i]))
		{
			if (!visited[i])
			{
				visited[i] = true;
				std::cout << index_to_vertex[i] << " ";
				q.push(i);
			}
		}
	}
	std::cout << std::endl;
}

void adjacency_Matrix_Graph::DFS(std::string x)
{
	bool visited[Pnum] = { false };
	int index = vertex[x];
	visited[index] = true;
	std::cout << x << " ";
	for (int i = first_nei(x); i != -1; i = next_nei(x, index_to_vertex[i]))
	{
		if (!visited[i])
		{
			DFS(index_to_vertex[i]);
		}
	}

}
