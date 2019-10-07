#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef long double ld;
 
struct Activity{
	int start;
	int finish;
};

bool cmp(Activity a, Activity b){
	return a.finish < b.finish;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(NULL);
	
	int n, s, f;
	
	cin >> n;
	
	vector<Activity> arr(n);	
	
	for(int i = 0; i < n; i++){
		cin >> s >> f;
		arr[i].start = s;
		arr[i].finish = f;
	}
	
	sort(arr.begin(), arr.end(), cmp);
	
	cout << endl << "Following activities are selected: " << endl;
	cout << "(" << arr[0].start << ", " << arr[0].finish << ")" << endl;
	for(int i = 0, j = 1; j < n; j++){
		if(arr[j].start >= arr[i].finish){
			cout << "(" << arr[j].start << ", " << arr[j].finish << ")" << endl;
			i = j;
		}
	}
		
	return 0;
}

/*
6
5 9
1 2
3 4
0 6
5 7
8 9

----
3
10 20
12 25
20 30

*/
