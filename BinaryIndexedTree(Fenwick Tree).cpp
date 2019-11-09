/*
	Created by Faisal Ahmed
*/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef long double ld;

int n;
int arr[1000];
int tree[1000];

void update(int ind, int x){
	
	while(ind <= n){
		tree[ind] += x;
		ind += (ind & -ind);
	}
	
}

int query(int ind){
	
	int sum = 0;
	while(ind > 0){
		sum += tree[ind];
		ind -= (ind & -ind);
	}
	
	return sum;
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(NULL);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		update(i, arr[i]);
	}
	
	cout << query(11) << endl;
	
	return 0;
} 
