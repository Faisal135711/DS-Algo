#include<iostream>
#include<vector>
#include<climits>

using namespace std;

struct Node{
    int u;
    int v;
    int w;
};
vector<Node> vec;
int V, E;
int dis[100];
int parent[100];

bool Relax(int u, int v, int w)
{
    if(dis[u]+w < dis[v]){
        dis[v] = dis[u]+w;
        return true;
    }
    return false;
}
int main()
{
    bool flag;

    cin >> V >> E;

    for(int i = 0; i < E; i++){
        Node a;
        cin >> a.u >> a.v >> a.w;
        vec.push_back(a);
    }
    for(int i = 0; i < V; i++){
        dis[i] = INT_MAX;
    }
    dis[0] = 0;
    for(int i = 0; i < V-1; i++){
        for(int j = 0; j < E; j++){
            if(Relax(vec[j].u, vec[j].v, vec[j].w)){
                parent[vec[j].v] = vec[j].u;
            }
        }
    }
    flag = true;

    for(int j = 0; j < E; j++){
        if(Relax(vec[j].u, vec[j].v, vec[j].w)){
            flag = false;
            break;
        }
    }
    if(flag) cout << "No negative cycle" << endl;
    else{
        cout << "Negative cycle" << endl;
    }

    return 0;
}
