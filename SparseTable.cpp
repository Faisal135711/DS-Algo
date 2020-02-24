/*
	Created by Faisal Ahmed
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef long double ld;

int logs[20];
int ST[100010][20];
int arr[100010];
int n;

void computeLogs(){
	for(int i = 1; i <= n; i++){
		logs[i] = i == 1 ? 0 : logs[i / 2] + 1;
	}
}

void buildSparseTable(){
	for(int i = 0; i < n; i++){
		ST[0][i] = arr[i];
	}
	
	for(int i = 1; i <= logs[n]; i++){
		int len = 1 << i;
		
		for(int j = 0; j + len <= n; j++){
			ST[i][j] = min(ST[i - 1][j], ST[i - 1][j + len / 2]);
		}
	}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}	
	
	computeLogs();
	buildSparseTable();
	
	int q, l, r;
	
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> l >> r;
		
		int x = logs[r - l + 1];
		int y = 1 << x; 
		
		cout << min(ST[x][l], ST[x][r - y + 1]) << endl;
	}
 	
	return 0;
}
/*

10
10 2 4 6 8 200 -2 40 -8 46
4
1 10
10 10
1 1
4 6 

*/
