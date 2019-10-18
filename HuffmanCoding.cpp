#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef long double ld;

vector<char> data = {'a', 'b', 'c', 'd', 'e', 'f'};
int freq[] = {5, 9, 12, 13, 16, 45};

struct MinHeapNode{
	char data;
	int freq;
	MinHeapNode *left, *right;
	
	MinHeapNode(char data, int freq){
		this->data = data;
		this->freq = freq;
		this->left = this->right = NULL;
	}
};

struct Compare{
	bool operator()(MinHeapNode *l, MinHeapNode *r){
		return (l->freq > r->freq);
	}
};

void printCode(MinHeapNode* root, string str){
	if(!root) return;
	
	if(root->data != '$'){
		cout << root->data << " : " << str << endl;
	}
	
	printCode(root->left, str+"0");
	printCode(root->right, str+"1");
}

void HuffmanCodes(){
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, Compare> PQ;
	
	for(int i = 0; i < data.size(); i++){
		PQ.push(new MinHeapNode(data[i], freq[i]));
	}
	
	while(PQ.size() > 1){
		MinHeapNode *top, *left, *right;
		
		left = PQ.top();
		PQ.pop();
		right = PQ.top();
		PQ.pop();
		
		top = new MinHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		
		PQ.push(top);
	}
	
	printCode(PQ.top(), "");
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(NULL);
	
	HuffmanCodes();
		
	return 0;
}
