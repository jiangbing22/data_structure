#include "HFtree.h"

void HFtree::createtree(int n, char* characters, int* weights)
{
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> minHeap;
	for(int i =0;i<n;i++)
	{
		HuffmanNode* node = new HuffmanNode(characters[i], weights[i]);
		minHeap.push(node);
	}
	root = buildtree(minHeap);


}

void HFtree::savetree(HuffmanNode* node,const char* outfile) 
{

}

void HFtree::destorytree(HuffmanNode* node)
{
	if (node != nullptr)
	{
		destorytree(node->left);
		destorytree(node->right);
		delete node;
	}
}

HuffmanNode* HFtree::buildtree(priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes>& minHeap)
{
	while (minHeap.size() > 1)
	{
		HuffmanNode* left = minHeap.top();
		minHeap.pop();

		HuffmanNode* right = minHeap.top();
		minHeap.pop();
		
		HuffmanNode* internalNode = new HuffmanNode('$', left->weight + right->weight);
		internalNode->left = left;
		internalNode->right = right;

		minHeap.push(internalNode);
	}
	return minHeap.top();
}

void HFtree::encode(HuffmanNode* node, string code, map<char, string>& codes)
{
	if (node != nullptr) {
		if (node->data != '$') {
			codes[node->data] = code;
		}

		encode(node->left, code + "0", codes);
		encode(node->right, code + "1", codes);
	}
}
