#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

int dp[100][100];

struct Node{
	int weight;
	int cost;
}arr[100];

bool cmp(Node a, Node b){
	return a.weight < b.weight;
}

int cap, n;

int ZeroOneKnapsack(int i, int w){
	if(i == n) return 0;
	
	int profit1 = 0, profit2 = 0;
	
	if(w + arr[i].weight <= cap){
		profit1 = arr[i].cost + ZeroOneKnapsack(i + 1, w + arr[i].weight);
	}
	else profit1 = 0;
	
	profit2 = ZeroOneKnapsack(i + 1, w);
	
	return max(profit1, profit2);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> cap;
	
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		arr[i].weight = x, arr[i].cost = y;
	}
	
	sort(arr, arr + n, cmp);

	int ans = ZeroOneKnapsack(0, 0);
	
	cout << ans << endl;
	
	return 0;
}

/*
4 10 
1 120 
4 280
3 150
4 200

3 50
10 60
20 100
30 120

5 10
1 120
7 400
4 280
3 150
4 200
*/

