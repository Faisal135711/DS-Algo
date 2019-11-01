#include<iostream>
#include<vector>

using namespace std;

vector<int> vec;

int partition(int p, int r)
{
	int x = vec[r];
	int i = p-1;
	for(int j = p; j <= r-1; j++){
		if(vec[j] <= x){
			int temp = vec[j];
			vec[j] = vec[++i];
			vec[i] = temp;
		}
	} 
	int temp = vec[r];
	vec[r] = vec[i+1];
	vec[i+1] = temp;
	return i+1;
}
void QuickSort(int p, int r)
{
	if(p < r){
		int q = partition(p, r);
		QuickSort(p, q-1);
		QuickSort(q+1, r);
	}
}
int main()
{
	int temp, size;
	
	cin >> size;
	for(int i = 0; i < size; i++){
		cin >> temp;
		vec.push_back(temp)
	}
	QuickSort(0, size-1);
	cout << "After sorting:\n";
	for(int i = 0; i < size; i++){
		cout << vec[i] << endl;
	}
	
	return 0;
}

