#pragma once
class HFtree
{
protected:
	class HFnode
	{
	public:
		int weight;
		HFnode* lchild;
		HFnode* rchild;
		HFnode(int w = 0, HFnode* l = nullptr, HFnode* r = nullptr) :weight(w), lchild(l), rchild(r) {};

	};
	HFnode* root;
public:

};

