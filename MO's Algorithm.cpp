/*
	Created by Faisal Ahmed
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef long double ld;

int block, ans[110];

struct Query{
	int index, l, r;
}q[110];

bool cmp(Query a, Query b){
	
	if(a.l / block != b.l / block){
		return a.l / block < b.l / block;
	}
	else{
		return a.r < b.r;
	}
	
}

void MO(int n, int arr[], int m, Query q[]){
	
	block = (int) sqrt(n);
	
	sort(q, q + m, cmp);
	
	int sum = 0, currL = 0, currR = -1;
	
	for(int i = 0; i < m; i++){
		int l = q[i].l, r = q[i].r;
		
		while(l < currL){
			sum += arr[--currL];
		}		
		
		while(l > currL){
			sum -= arr[currL++];
		}
		
		while(r < currR){
			sum -= arr[currR--];
		}
		
		while(r > currR){
			sum += arr[++currR];
		}
		
		ans[q[i].index] = sum;
			
	}
	
	for(int i = 0; i < m; i++){
		cout << ans[i] << endl;
	}
	
}

int main()
{
	int n, m, arr[1010];
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	cin >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		
		cin >> x >> y;
		q[i].l = x, q[i].r = y, q[i].index = i;
	}
 	
 	MO(n, arr, m, q);
 	
	return 0;
}
