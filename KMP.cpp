/*
	Created by Faisal Ahmed
*/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef long double ld;

vector<int> create_lps(string pattern){
	int len = pattern.size();
	vector<int> lps(len);
	
	for(int i = 1, j = 0; i < len;){
		if(pattern[i] == pattern[j]){
			i++, j++;
			lps[i] = j;
		}
		else{
			if(j != 0){
				j = lps[j - 1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
	
	return lps;
}


void KMP(string text, string pattern){
	vector<int> lps = create_lps(pattern);
	int i = 0, j = 0;
	int n = text.size(), m = pattern.size();
	bool found = false;
	
	while(i < n){
		if(text[i] == pattern[j]){
			i++, j++;
		}
		else{
			if(j != 0){
				j = lps[j - 1];
			}
			else{
				i++;
			}
		}
		
		if(j == m){
			found = true;
			break;
		}
	}
	
	if(found){
		cout << "Found" << endl;
	}
	else{
		cout << "Not Found" << endl;
	}
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(NULL);
	
	string text, pattern;
	
	getline(cin, text);
	getline(cin, pattern);
	
	KMP(text, pattern);
	
	return 0;
} 
