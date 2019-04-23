#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define MX 100

int arr[MX];
int tree[MX * 3];

void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}

int query(int node, int b, int e, int i, int j){
    if(b >= i && e <= j){
        return tree[node];
    }
    if(i > e || j < b){
        return 0;
    }

    int mid = (b + e) / 2;
    int left = node * 2;
    int right = node * 2 + 1;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid + 1, e, i, j);
    return p1 + p2;
}

void init(int node, int b, int e){
    if(b == e){
        tree[node] = arr[b];
        return;
    }

    int mid = (b + e) / 2;
    int left = node * 2;
    int right = node * 2 + 1;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = tree[left] + tree[right];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    init(1, 1, n);

    cout << query(1, 1, n, 3, 6) << endl;

    update(1, 1, n, 3, 6);

    cout << query(1, 1, n, 3, 6) << endl;

    return 0;
}
/*
7
4 -9 3 7 1 0 2
*/
