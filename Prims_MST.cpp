#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> PII;

struct Node{
    int u;
    int c;
};
bool operator<(Node a, Node b){
    return a.c > b.c;
}
vector<PII> graph[100];
priority_queue<Node> PQ;
int edge, vertex;
bool finish[100];
int cost[100];

int PRIMS(int source){
    int mstCost = 0;

    for(int i = 0; i < vertex; i++){
        finish[i] = false;
        cost[i] = INT_MAX;
    }

    cost[source] = 0;
    Node n;
    n.u = source;
    n.c = 0;
    PQ.push(n);

    while(!PQ.empty()){
        Node current = PQ.top();
        PQ.pop();

        if(finish[current.u]){
            continue;
        }

        finish[current.u] = true;
        mstCost += current.c;
    //    cout << "c-cost = " << current.c << endl;

        int len = graph[current.u].size();
        for(int i = 0; i < len; i++){
            int v = graph[current.u][i].first;
            if(finish[v]){
                continue;
            }
            if(graph[current.u][i].second < cost[v]){
                Node temp;
                temp.u = v;
                temp.c = graph[current.u][i].second;
                PQ.push(temp);
                cost[v] = graph[current.u][i].second;
            }

        }
    }

    return mstCost;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> vertex >> edge;
    for(int i = 0; i < edge; i++){
        PII p;
        int source;

        cin >> source >> p.first >> p.second;
        graph[source].push_back(p);
        swap(p.first, source);
        graph[source].push_back(p);
    }

    cout << "Total Cost = " << PRIMS(0) << endl;

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

