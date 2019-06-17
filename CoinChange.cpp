#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

int dp[5][7500];
int coin[] = {1, 5, 10, 25, 50};

int CoinChange(int i, int amount){
	if(i == 5){
		if(amount == 0) return 1;
		else return 0;
	}
	
	if(dp[i][amount] != -1) return dp[i][amount];
	
	int ret1 = 0, ret2 = 0;
	
	if(amount - coin[i] >= 0) ret1 = CoinChange(i, amount - coin[i]);
	ret2 = CoinChange(i + 1, amount);
	
	dp[i][amount] = ret1 + ret2;
	
	return dp[i][amount];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	
	memset(dp, -1, sizeof(dp));
	
	int amount;
	
	while(scanf("%d", &amount) != EOF){
		cout << CoinChange(0, amount) << endl;
	}
	
	return 0;
}



