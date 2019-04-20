#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct Node{
    int u;
    int v;
    int w;
};
bool cmp(Node a, Node b){
    return a.w < b.w;
}
vector<Node> graph;
int edge, vertex;
int Rank[100];
int parent[100];

void initialize(){
    for(int i = 0; i < vertex; i++){
        Rank[i] = 0;
        parent[i] = i;
    }
}

int FindParent(int x){
    if(x != parent[x]){
        return parent[x] = FindParent(parent[x]);
    }
    else return x;
}

void UnionSet(int x, int y){
    int px = FindParent(x);
    int py = FindParent(y);

    if(px == py){
        return;
    }

    if(Rank[px] > Rank[py]){
        parent[py] = px;
    }
    else if(Rank[px] < Rank[py]){
        parent[py] = px;
    }
    else{
        parent[py] = px;
        Rank[px]++;
    }
}

int KRUSKAL(){
    int mstCost = 0;

    initialize();

    sort(graph.begin(), graph.end(), cmp);

    int len = graph.size();
    for(int i = 0; i < len; i++){
        if(FindParent(graph[i].u) != FindParent(graph[i].v)){
            UnionSet(graph[i].u, graph[i].v);
            mstCost += graph[i].w;
        }
    }

    return mstCost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> vertex >> edge;
    for(int i = 0; i < edge; i++){
        Node e;
        cin >> e.u >> e.v >> e.w;
        graph.push_back(e);
    }

    cout << "Total Cost = " << KRUSKAL() << endl;

    return 0;
}
/*
 8 9
 0 3 3
 0 4 6
 1 5 5
 1 6 1
 2 4 6
 3 5 8
 5 6 3
 5 7 2
 6 7 6
 -----
 8 11
 0 1 4
 0 3 10
 0 4 2
 1 2 18
 1 3 8
 2 3 11
 3 4 5
 3 6 11
 3 7 9
 6 5 1
 5 7 2
*/

