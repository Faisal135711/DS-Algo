#include<bits/stdc++.h>

using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3

vector<vector<int>> graph;
vector<int> color;
vector<int> ft;
int V, E;

void DFS_Visit(int u)
{
	color[u] = GRAY;
	
	cout << u << endl;
	
	int len = graph[u].size();
	for(int i = 0; i < len; i++){
		int v = graph[u][i];
		if(color[v] == WHITE){
			DFS_Visit(v);
		}
	}
	
	ft.push_back(u);
	color[u] = BLACK;
}
void DFS()
{
	for(int i = 0; i < V; i++){
		if(color[i] == WHITE){
			DFS_Visit(i);
		}
	}
}
int main()
{
	int n1, n2;
	
	cout << "Enter the number of edges and vertices: ";
	cin >> E >> V;
	
	graph.assign(V, vector<int>());
	color.assign(V, WHITE);
	
	cout << "Enter the edges: " << endl;
	for(int i = 0; i < E; i++){
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}
	
	DFS();
	
	//finishing time basis
	cout << endl;
	for(int i = 0; i < ft.size(); i++){
		cout << ft[i] << endl;
	}
	
	return 0;
}
