//
// Created by Faisal Ahmed on 2/26/2019.
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//vector<vector<int>> graph;
//vector<int> dis;
//vector<int> parent;
//
//void BFS(int source){
//    queue<int> q;
//    dis[source] = 0;
//    q.push(source);
//
//    while(!q.empty()){
//        int u = q.front();
//
//        cout << u << endl;
//
//        q.pop();
//
//        int len = graph[u].size();
//        for(int i = 0; i < len; i++){
//            int v = graph[u][i];
//            if(dis[v] == INT_MAX){
//                q.push(v);
//                dis[v] = dis[u] + 1;
//                parent[v] = u;
//            }
//        }
//    }
//}
//
//int main()
//{
//    int v, e, n1, n2;
//
//    scanf("%d%d", &v, &e);
//
//    graph.assign(v + 1, vector<int>());
//    dis.assign(v + 1, INT_MAX);
//    parent.assign(v + 1, 0);
//
//    for(int i = 0; i < e; i++){
//        scanf("%d%d", &n1, &n2);
//        graph[n1].push_back(n2);
//        graph[n2].push_back(n1);
//    }
//
//    BFS(1);
//
//    printf("Parent: \n");
//    for(int i = 1; i <= v; i++){
//        printf("Parent of %d is %d\n", i, parent[i]);
//    }
//
//    return 0;
//}
/*
 10 13
 1 2
 1 4
 1 3
 2 6
 4 7
 3 7
 3 8
 7 8
 6 10
 7 9
 8 5
 9 10
 10 5
 */
