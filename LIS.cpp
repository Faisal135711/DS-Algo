#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

void LIS(vector<int>& v){
	
	// O(n^2)
	
	int n = v.size();
	
	vector<int> d(n, 1), p(n, -1), subsequence;
	
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(v[j] < v[i] && d[i] < d[j] + 1){
				d[i] = d[j] + 1;
				p[i] = j;
			}
		}
	}
	
	int ans = d[0], pos = 0;
	for(int i = 1; i < n; i++){
		if(d[i] > ans){
			ans = d[i];
			pos = i;
		}
	}
	
	while(pos != -1){
		subsequence.push_back(v[pos]);
		pos = p[pos];
	}
	
	reverse(subsequence.begin(), subsequence.end());
	
	cout << "Length of LIS: " << ans << endl;
	cout << "Longest Sub-sequence: ";
	for(int i = 0; i < subsequence.size(); i++){
		cout << subsequence[i] << " ";
	}
	cout << endl;
	
}

void LIS_with_multiset(vector<int>& v){
	multiset<int> ms;
	
	for(int i = 0; i < v.size(); i++){
		ms.insert(v[i]);
		
		auto it = ms.upper_bound(v[i]);
		
		if(it != ms.end()){
			ms.erase(it);
		}
	}
	
	cout << "LIS = " << ms.size() << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	int n, x;
	vector<int> vec;
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x;
		vec.push_back(x);
	}    
	
	LIS_with_multiset(vec);
	
	return 0;
}



