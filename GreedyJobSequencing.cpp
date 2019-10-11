#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef long double ld;

char ch;
int n, d, p;

struct Job{
	char id;
	int deadline;
	int profit;
}arr[100];

bool cmp(Job a, Job b){
	return a.profit > b.profit;
}

void GreedyJobSequencing(){
	
	bool slot[n + 1];
	int totProfit = 0;
	vector<char> sequence(n + 1);
	
	for(int i = 0; i <= n; i++){
		slot[i] = false;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = min(n, arr[i].deadline); j >= 1; j--){
			if(!slot[j]){
				sequence[j] = arr[i].id;
				slot[j] = true;
				totProfit += arr[i].profit;
				break;
			}
		}
	}
	
	cout << "Job sequence: ";
	for(int i = 1; i <= n; i++){
		if(slot[i]) cout << sequence[i] << " ";
	}
	cout << endl << "Total Profit: " << totProfit << endl;
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(NULL);
	
	//cout << "Enter how many jobs: ";
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> ch >> d >> p;
		arr[i + 1].id = ch;
		arr[i + 1].deadline = d;
		arr[i + 1].profit = p;
	}	
	
	sort(arr + 1, arr + 1 + n, cmp);
	
//	for(int i = 1; i <= n; i++){
//		cout << arr[i].id << " " << arr[i].deadline << " " << arr[i].profit << endl;
//	}
	
	GreedyJobSequencing();
		
		
	return 0;
}
/*

5 
a 2 100
b 1 19
c 2 27
d 1 25
e 3 15
________

4
a 4 20
b 1 10
c 1 40
d 1 30

*/

