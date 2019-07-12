#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

int dp[1000][1000];

void LCS(string a, string b){
	for(int i = 1; i <= a.size(); i++){
		for(int j = 1; j <= b.size(); j++){
			if(a[i - 1] == b[j - 1]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	
	cout << "LENGTH OF LCS: " << dp[a.size()][b.size()] << endl;
	
	vector<char> lcs(dp[a.size()][b.size()]);
	int r = a.size(), c = b.size(), ind = dp[a.size()][b.size()];
	
	while(r > 0 && c > 0){
		if(a[r - 1] == b[c - 1]){
			lcs[--ind] = a[r - 1];
			r--, c--;
		}
		else if(dp[r - 1][c] > dp[r][c - 1]){
			r--;
		}
		else{
			c--;
		}
	}
	
	cout << "LCS: ";
	for(int i = 0; i < lcs.size(); i++){
		cout << lcs[i];
	}
	cout << endl;
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string a, b;
    
    cin >> a >> b;
    
    LCS(a, b);
	
	return 0;
}



