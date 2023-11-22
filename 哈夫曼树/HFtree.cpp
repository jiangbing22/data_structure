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

void HFtree::savetree(HuffmanNode* node,ofstream& outfile) 
{
	if (node != nullptr)
	{
		if (node->data == '$')
		{
			outfile.put('$');
			savetree(node->left, outfile);
			savetree(node->right, outfile);
		}
		else
		{
			outfile.put(node->data);
		}
	}

}

void HFtree::load(const char* treefile)
{
	ifstream infile(treefile, ios::binary);
	root = loadtree(infile);
	infile.close();

}

void HFtree::encoder(const char* inputfile, const char* outputfile,string prefix)
{
	map<char, string> codes;
	encode(root, prefix, codes);

	ifstream infile(inputfile);
	ofstream outfile(outputfile, ios::binary);
	char c;
	while (infile.get(c))
	{
		outfile <<codes[c];
		cout << c << ":encode to:" << codes[c] << endl;
		
	}
	infile.close();
	outfile.close();
}
void HFtree::decode(const char* inputFile, const char* outputFile) {
	ifstream inFile(inputFile, ios::binary);
	ofstream outFile(outputFile);

	HuffmanNode* currentNode = root;

	char bit;
	while (inFile.get(bit)) {
		if (bit == '0') {
			currentNode = currentNode->left;
		}
		else {
			currentNode = currentNode->right;
		}

		if (currentNode->left == nullptr && currentNode->right == nullptr) {
			outFile.put(currentNode->data);
			cout << (currentNode->data);
			currentNode = root;
		}
	}

	inFile.close();
	outFile.close();
}

void HFtree::save(const char* treefile)
{
	ofstream outfile(treefile, ios::binary);
	savetree(root, outfile);
	outfile.close();
	
}

HuffmanNode* HFtree::loadtree(ifstream& inFile) {
	char c;
	inFile.get(c);

	if (c == '$') {
		HuffmanNode* internalNode = new HuffmanNode('$', 0);
		internalNode->left = loadtree(inFile);
		internalNode->right = loadtree(inFile);
		return internalNode;
	}
	else {
		return new HuffmanNode(c, 0);
	}
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
