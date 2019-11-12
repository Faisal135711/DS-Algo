#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
stack<int> s;
vector<bool> visited;
vector<int> sTime, fTime;
int t = 0;

void dfs_visit(int x)
{
	visited[x] = true;
	sTime[x] = ++t;
	
	for(int i = 0; i < graph[x].size(); i++){
		int v = graph[x][i];
		if(!visited[v]){
			dfs_visit(v);
		}
	}
	s.push(x);
	fTime[x] = ++t;
}
void topological_sort(int V)
{
	for(int i = 0; i < V; i++){
		if(!visited[i]){
			dfs_visit(i);
		}
	}
}
int main()
{
	int u, v, E, V;
	
	cin >> V >> E;
	
	graph.resize(V);
	visited.resize(V);
	sTime.resize(V);
	fTime.resize(V);
	
	for(int i = 0; i < E; i++){
		cin >> u >> v;
		graph[u].push_back(v);
	}
	
	topological_sort(V);
	
	while(!s.empty()){
		int n = s.top();
		s.pop();
		
		printf("Starting and Finishing time of %d  = %d %d\n", n, sTime[n], fTime[n]);
	}
	
	return 0;
}
