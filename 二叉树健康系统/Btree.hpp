#pragma 
#include<queue>
#include<stack>
template<class T>
class node
{
public:
	T  data;
	node<T>* left; node<T>* right; (
		node() :left(nullptr), right(nullptr ) {}
	node(T x, node<T>* l = nullptr, node<T>* r = nullptr) :data(x), left(l), right(r) {}


};
template<class T>
class Btree
{
public:
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
	node<T> * parent(node<T>* current)
	{
		return (root == nullptr || root == current) ? nullptr : parent(root, current);
	};

protected:
	node<T>* parent(node<T>* subtree, node<T>* current);


private:
	node<T>* root;
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
void Btree<T>::f_preordered(node<T>* current, void(*visit)(node<T>* p)) {
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


	}


}


template<class T>
node<T>* Btree<T>::parent(node<T>* subtree, node<T>* current)
{
	return nullptr;
}
