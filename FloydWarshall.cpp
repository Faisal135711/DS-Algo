#include <bits/stdc++.h>

using namespace std;

#define LARGE 1000000

typedef long long int ll;

struct Node{
    int u;
    int v;
    int w;
};

vector<Node> graph;
int dis[100][100];
int mid[100][100];
int edge, vertex;

void FloydWarshall(){
    for(int k = 1; k <= vertex; k++){
        for(int i = 1; i <= vertex; i++){
            for(int j = 1; j <= vertex; j++){
                if(dis[i][j] > dis[i][k] + dis[k][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                    mid[i][j] = mid[i][k];
                }
            }
        }
    }
}
void FindPath(int i, int j){
    printf("Path to go from %d to %d: \n", i, j);
    cout << i << " --> ";
    while(i != j){
        i = mid[i][j];
        cout << i << " --> ";
    }
    cout << endl;
}
int main() {

    cin >> edge >> vertex;

    for(int i = 1; i <= vertex; i++){
        for(int j = 1; j <= vertex; j++){
            mid[i][j] = j;
            if(i == j) dis[i][j] = 0;
            else dis[i][j] = LARGE;
        }
    }

    for(int i = 0; i < edge; i++){
        Node e;
        cin >> e.u >> e.v >> e.w;

        graph.push_back(e);
        dis[e.u][e.v] = e.w;
    }

    FloydWarshall();

    for(int i = 1; i <= vertex; i++){
        for(int j = 1; j <= vertex; j++){
            printf("Shortest path from node %d to %d is %d\n", i, j, dis[i][j]);
        }
    }

    FindPath(1, 3);

    return 0;
}
/*

6 4

2 1 2
3 2 5
4 3 8
4 1 20
2 3 2
1 2 3

<--->
 4 4

 0 3 10
 0 1 5
 1 2 3
 2 3 1

<-->
 5 4

 1 2 10
 1 3 8
 1 4 2
 3 2 1
 4 3 3
*/

