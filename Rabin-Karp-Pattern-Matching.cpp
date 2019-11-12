/*
	Created by Faisal Ahmed
*/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef long double ld;

#define B 347

ll hash_value(string str, int len, ll M){
	
	ll value = 0, power = 1;
	
	for(int i = len - 1; i >= 0; i--){
		value =  value + (str[i] * power) % M;
		value = value % M;
		power = (power * B) % M;
	}
	
	return value;
	
}

void Rabin_Karp(string text, string pattern){
	
	int n = text.size(), m = pattern.size();
	ll power = 1;
	ll M = 1000000000+7;
	ll hash_text = hash_value(text, m, M);
	ll hash_pattern = hash_value(pattern, m, M);
	bool found = true;
	
	if(hash_text == hash_pattern){
		for(int i = 0; i < m; i++){
			if(text[i] != pattern[i]){
				found = false;
				break;
			}
		}
		
		if(found){
			cout << "\nMatch found at index 0" << endl;
			return;
		}
	}
	
	for(int i = 0; i < m - 1; i++){
		power = (power * B) % M;
	}
	
	for(int i = m; i < n; i++){
		hash_text = (hash_text - (text[i - m] * power) % M) % M;
		hash_text = (hash_text + M) % M;
		hash_text = (hash_text * B) % M;
		hash_text = (hash_text + text[i]) % M;
		
		if(hash_text == hash_pattern){
			cout << "\nMatch found at index " << i - m + 1 << endl;
			return;
		}
	}
	
	cout << "Match not found" << endl;
	
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(NULL);
	
	string text, pattern;
	
	cin >> text >> pattern;
	
	Rabin_Karp(text, pattern);
	
	return 0;
} 
