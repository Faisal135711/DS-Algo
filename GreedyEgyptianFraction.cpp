#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef long double ld;

void GreedyEgyptianFraction(int nr, int dr){
	if(nr == 0 || dr == 0) return;
	else if(dr % nr == 0){
		cout << "1/" << dr/nr << endl;
		return;
	}
	else if(nr % dr == 0){
		cout << nr/dr << endl;
		return;
	}
	else if(nr > dr){
		cout << nr / dr << " + ";
		GreedyEgyptianFraction(nr % dr, dr);
		return;
	}
	else{
	
		int n = dr / nr + 1;
		cout << "1/" << n << " + ";
		GreedyEgyptianFraction(n * nr - dr, dr * n);
	
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(NULL);
	
	GreedyEgyptianFraction(4, 2);
		
	return 0;
}

