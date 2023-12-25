#include "adjacency_Matrix.h"

void adjacency_Matrix_Graph::create(char* filepath)
{
	std::ifstream txt_reader(filepath);
	if (!txt_reader.is_open()) {
		std::cerr << "�޷����ļ�" << std::endl;
		if (txt_reader.fail()) {
			std::cerr << "���ļ�ʧ�ܣ��ļ�״̬����" << std::endl;
		}
		else if (txt_reader.bad()) {
			std::cerr << "���ļ�ʧ�ܣ���״̬����" << std::endl;
		}
		else if (txt_reader.eof()) {
			std::cerr << "���ļ�ʧ�ܣ������ļ�ĩβ" << std::endl;
		}
		else {
			std::cerr << "���ļ�ʧ�ܣ�δ֪ԭ��" << std::endl;
		}
		return; // ���ش������
	}
	txt_reader >> vexnum >> arcnum;
	for (int i = 0; i < vexnum; i++)
	{
		for (int j = 0; j < vexnum; j++)
		{
			matrix[i][j] = 0;
		}
	}
	std::cout << "�ڵ����:" << vexnum << "����������" << arcnum << std::endl;
	txt_reader >> D;
	if (D)
	{
		std::cout << "ͼΪ����ͼ" << std::endl;

	}
	else
	{
		std::cout << "ͼΪ����ͼ" << std::endl;
	}
	std::cout << "ͼ�Ľڵ�:";
	index_to_vertex = new char[vexnum];
	for (int i = 0; i < vexnum; i++)
	{
		static char temp;
		txt_reader >> temp;
		index_to_vertex[i] = temp;
		vertex[temp] = i;
		std::cout << i << temp << std::endl;
	}
	for (int i = 0; i < arcnum; i++)
	{
		static char P1, P2;
		txt_reader >> P1>>P2;
		matrix[vertex[P1]][vertex[P2]] = 1;
	}


}

int adjacency_Matrix_Graph::first_nei(char x)
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

int adjacency_Matrix_Graph::next_nei(char x, char y)
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

void adjacency_Matrix_Graph::BFS(char x)
{
	bool visited[Pnum] = { false };
	int index = vertex[x];
	std::queue<int> q;
	std::cout << "BFS˳��: ";

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

void adjacency_Matrix_Graph::DFS(char x)
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
