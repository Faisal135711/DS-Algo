#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi; 

vector<vector<int>> graph;
vector<int> dis;
vector<int> parent;
int cost[100][100];

void Dijkstra(int source){
    priority_queue<pi, vector<pi>, greater<pi> > PQ;
    
    dis[source] = 0;
    PQ.push(make_pair(source, 0));

    while(!PQ.empty()){
        int u = PQ.top().first;
        cout << u << endl;

        PQ.pop();

        int len = graph[u].size();
        for(int i = 0; i < len; i++){
            int v = graph[u][i];
            if(cost[u][v] + dis[u] < dis[v]){
            	dis[v] = cost[u][v] + dis[u];
                PQ.push(make_pair(v, dis[v]));
                parent[v] = u;
            }
        }
    }
}

int main()
{
    int v, e, n1, n2, n3;

    scanf("%d%d", &v, &e);

    graph.assign(v + 1, vector<int>());
    dis.assign(v + 1, INT_MAX);
    parent.assign(v + 1, 0);

    for(int i = 0; i < e; i++){
        scanf("%d%d%d", &n1, &n2, &n3);
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
        cost[n1][n2] = n3;
        cost[n2][n1] = n3;
    }

    Dijkstra(1);

    printf("Parent: \n");
    for(int i = 1; i <= v; i++){
        printf("Parent of %d is %d\n", i, parent[i]);
        printf("distance of %d is %d \n", i, dis[i]);
    }

    return 0;
}
/*
4 4

1 2 2
1 3 5
2 3 1
3 4 3


9 14

1 2 4 
1 8 8 
2 3 8 
2 8 11 
3 4 7 
3 9 2 
3 6 4 
4 5 9 
4 6 14 
5 6 10 
6 7 2 
7 8 1 
7 9 6 
8 9 7


*/

