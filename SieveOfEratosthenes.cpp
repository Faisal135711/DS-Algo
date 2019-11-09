/*
	Created by Faisal Ahmed
*/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef long double ld;

void SieveOfEratosthenes(int n) 
{ 
 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++){ 
        if (prime[p] == true){ 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    for (int p=2; p<=n; p++){
       if (prime[p]) {
          cout << p << " "; 
       }
    }
    cout << endl;
} 

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(NULL);
	
	int n;
	
	cin >> n;
	SieveOfEratosthenes(n);
	
	return 0;
} 
