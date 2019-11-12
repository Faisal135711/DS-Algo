#include<iostream>
#include<vector>
#include<stack>

using namespace std;

bool visited[100];
vector<int> vec[100];
stack<int> s;
int V, E;
vector<int> reverse_vec[100];

void dfs_visit(int x)
{
    visited[x] = true;
    int size = vec[x].size();
    for(int i = 0; i < size; i++){
        if(!visited[vec[x][i]]){
            dfs_visit(vec[x][i]);
        }
    }
    s.push(x);
}
void dfs()
{
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            dfs_visit(i);
        }
    }
}
void rDfs(int x)
{
    visited[x] = true;
    int size = reverse_vec[x].size();

    cout << x << endl;
    for(int i = 0; i < size; i++){
        if(!visited[reverse_vec[x][i]]){
            rDfs(reverse_vec[x][i]);
        }
    }
}
void scc()
{
    for(int i = 0; i < V; i++){
        visited[i] = false;
    }

    while(!s.empty()){
        int x = s.top();
        s.pop();
        if(!visited[x]){
            rDfs(x);
        }
    }

}
int main()
{
    int u, v;

    cout << "Enter the number of vertices and edges: \n";
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> u >> v;
        vec[u].push_back(v);
        reverse_vec[v].push_back(u);
    }
    for(int i = 0; i < V; i++){
        visited[i] = false;
    }

    dfs();
    scc();

    return 0;
}
