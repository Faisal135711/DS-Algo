#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int Rank[100];
int parent[100];

void makeSet(int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        Rank[i] = 0;
    }
}
int findParent(int m){
    if(m != parent[m]){
        return parent[m] = findParent(parent[m]);
    }
    else return m;
}
void unionSet(int a, int b){
    int x = findParent(a);
    int y = findParent(b);
    if(x != y){
        if(Rank[x] < Rank[y]){
            parent[x] = y;
        }
        else if(Rank[x] > Rank[y]){
            parent[y] = x;
        }
        else{
            parent[y] = x;
            Rank[x]++;
        }
    }
}
void printSet(int n){
    for(int i = 0; i < n; i++){
        printf("Node is %d, Parent is %d, Rank is %d\n", i, parent[i], Rank[i]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;

    cin >> n;

    makeSet(n);

    unionSet(0, 1);
    unionSet(4, 2);
    unionSet(0, 3);
    unionSet(3, 1);
    unionSet(0, 4);

    printSet(n);

    return 0;
}
/*

 5

 0 1
 4 2
 3 1
 0 3
 0 4
*/

