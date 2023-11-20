#pragma 
#include<queue>
#include<stack>
#include<algorithm>
#include<iostream>
template<class T>
class node
{
public:
	T  data;
	node<T>* left; node<T>* right; 
	node() :left(nullptr), right(nullptr ) {}
	node(T x, node<T>* l = nullptr, node<T>* r = nullptr) :data(x), left(l), right(r) {}


};
template<class T>
class Btree
{
public:
	node<T>* root;
	Btree() :root(nullptr){}
	Btree(T value):refvalue(value),root(nullptr){}
	Btree(Btree<T>& s);
	~Btree();
	bool isempty() { return (root == nullptr) ? false : true; }
	void levelordered(void (*visit)(node<T>* p));
	void r_preordered(node<T>* current,void (*visit)(node<T>* p));
	void r_postordered(node<T>* current, void (*visit)(node<T>* p));
	void r_inordered(node<T>* current, void (*visit)(node<T>* p));
	void f_preordered(node<T>* current, void(*visit)(node<T>* p));
	void f_inordered(node<T>* current, void(*visit)(node<T>* p));
	void f_postordered(node<T>* current, void(*visit)(node<T>* p));
	int get_height(node<T>* current);
	int count_leaves(node<T>* current);
	void print_trees(node<T>* current,void (*visit)(node<T>* p));
	node<T>* insert_node(node<T>* root, T value);
	node<T> * parent(node<T>* current)
	{
		return (root == nullptr || root == current) ? nullptr : parent(root, current);
	};

protected:
	node<T>* parent(node<T>* subtree, node<T>* current);
	T refvalue;


	


	
};

template<class T>
Btree<T>::Btree(Btree<T>& s)
{
}

template<class T>
Btree<T>::~Btree()
{
}

template<class T>
void Btree<T>::levelordered(void(*visit)(node<T>* p))
{
	if (root == nullptr)
	{
		return ;
	}
	else
	{
		std::queue<node<T>*> nodequeue;
		nodequeue.push(root);
		while (!nodequeue.empty())
		{
			node<T>* current = nodequeue.front();
			visit(current);
			if (current->left != nullptr) {
				nodequeue.push(current->left);
			}
			if (current->right != nullptr) {
				nodequeue.push(current->right);
			}

			// 弹出已访问的节点
			nodequeue.pop();
		}

		
	}
}

template<class T>
void Btree<T>::r_preordered(node<T>* current,void(*visit)(node<T>* p))
{
	if (current == nullptr)
	{
		return;
	}
	else
	{
		visit(current);
		r_preordered(current->left,visit);
		r_preordered(current->right,visit);
	}
}

template<class T>
void Btree<T>::r_postordered(node<T>* current, void(*visit)(node<T>* p))
{
	if (current == nullptr)
	{
		return;
	}
	else
	{
		
		r_postordered(current->left, visit);
		r_postordered(current->right, visit);
		visit(current);
	}
}

template<class T>
void Btree<T>::r_inordered(node<T>* current, void(*visit)(node<T>* p))
{
	if (current == nullptr)
	{
		return;
	}
	else
	{
	
		r_inordered(current->left, visit);
		visit(current);
		r_inordered(current->right, visit);

	}
}

template<class T>
void Btree<T>::f_preordered(node<T>* current, void(*visit)(node<T>* p)) 
{
	if (current == nullptr) 
	{
		return;
	}
	else 
	{
		std::stack<node<T>*> nodestack;
		nodestack.push(current);
		while (!nodestack.empty())
		{
			node<T>* temp = nodestack.top();
			visit(temp); 
			nodestack.pop();
			if (temp->right != nullptr) 
			{
				nodestack.push(temp->right); 
			}
			if (temp->left != nullptr)
			{
				nodestack.push(temp->left); 
			}
		}
	}
}

template<class T>
void Btree<T>::f_inordered(node<T>* current, void(*visit)(node<T>* p))
{
	if (current == nullptr)
	{
		return;
	}
	else 
	{
		std::stack<node<T>*> nodestack;
		while (current != nullptr || !nodestack.empty())//如果节点为空，跳出循环，取stack中第一个
		{
			while (current != nullptr)//直到左节点为空时，跳出
			{
				nodestack.push(current);
				current = current->left;
			}
			current = nodestack.top();

			nodestack.pop();
			visit(current);
			current = current->right;

		}


	}


}

template<class T>
void Btree<T>::f_postordered(node<T>* current, void(*visit)(node<T>* p))
{
	if (current == nullptr)
	{
		return;
	}
	else
	{
		std::stack<node<T>*> nodestack,reversestack;
		nodestack.push(current);
		while (!nodestack.empty())
		{
			node<T>* temp = nodestack.top();
			reversestack.push(temp);
			
			nodestack.pop();
			if (temp->left != nullptr)
			{
				nodestack.push(temp->left);
			}
			if (temp->right != nullptr)
			{
				nodestack.push(temp->right);
			}

		}
		while (!reversestack.empty())
		{
			node<T>* out = reversestack.top();
			visit(out);
			reversestack.pop();
		}
	}
}

template<class T>
int Btree<T>::get_height(node<T>* current)

{
	if (current == nullptr)
	{
		return 0;
	}
	else
	{
		int left_height = get_height(current->left);
		int right_height = get_height(current->right);
		return 1 + std::max(left_height, right_height);
	}
}

template<class T>
int Btree<T>::count_leaves(node<T>* current)
{
	if (current == nullptr)
	{
		return 0;
	}
	
	if (current->left == nullptr && current->right == nullptr)
	{
		return 1;
	}
	int leftleaves = count_leaves(current->left);
	int rightleaves = count_leaves(current->right);
	return leftleaves + rightleaves;
	
}

template<class T>
void Btree<T>::print_trees(node<T>* current,  void (*visit)(node<T>* p))
{
	this->f_preordered(current,visit);
}

template<class T>
node<T>* Btree<T>::insert_node(node<T>* root, T value)
{
	if (root == nullptr)
	{
		return new node<T>(value);
	}
	if (value < root->data)
	{
		root->left = insert_node(root->left, value);
	}
	else
	{
		root->right = insert_node(root->right, value);
	}
}


template<class T>
node<T>* Btree<T>::parent(node<T>* subtree, node<T>* current)
{
	return nullptr;
}
