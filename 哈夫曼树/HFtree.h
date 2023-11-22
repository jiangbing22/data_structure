#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
struct HuffmanNode {
    char data;
    int weight;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char d, int w) : data(d), weight(w), left(nullptr), right(nullptr) {}
};

// 优先队列比较器，用于构建最小堆
struct CompareNodes {
    bool operator()(HuffmanNode* lhs, HuffmanNode* rhs) const {
        return lhs->weight > rhs->weight;
    }
};
class HFtree{
public:
    HFtree() :root(nullptr) {};
    ~HFtree(){destorytree(root);}
    void createtree(int n, char* characters, int* weights);
    void save(const char* outfile);
    void load(const char* treefile);
    void encoder(const char* inputfile, const char* outputfile,string prefix);
    void decode(const char* inputFile, const char* outputFile);
    bool isempty() { return (root == nullptr); }

private:
    HuffmanNode* root;
    void savetree(HuffmanNode* node, ofstream& outfile);
    HuffmanNode* loadtree(ifstream& inFile);
    void destorytree(HuffmanNode* node);
    HuffmanNode* buildtree(priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes>& minHeap);
    void encode(HuffmanNode* node, string code, map<char, string>& codes);
};