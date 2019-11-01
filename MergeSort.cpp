#include<iostream>
#include<vector>

using namespace std;

vector<int> vec;

void merge(int p, int q, int r)
{
	int n1 = q-p+1;
	int n2 = r-q;
	cout << "n1 n2= " << n1 << " " << n2 << endl;

	vector<int> L, R;
	for(int i = 0; i < n1; i++){
		L.push_back(vec[p+i]);
	//	L[i] = vec[p+i];
	}
	for(int i = 0; i < n2; i++){
		R.push_back(vec[q+i+1]);
	//	R[i] = vec[q+i+1];
	}
	//L[n1] = INT_MAX;
	L.push_back(INT_MAX);
	R.push_back(INT_MAX);
	int i = 0, j = 0;

	for(int k = p; k <= r; k++){
		if(L[i] <= R[j]){
			vec[k] = L[i++];
		}
		else{
			vec[k] = R[j++];
		}
	}
}
void merge_sort(int p, int r)
{
	if(p < r){
		int q = (p+r)/2;
		merge_sort(p, q);
		merge_sort(q+1, r);
		merge(p, q, r);
	}
}
int main()
{
	int size, temp;

	cin >> size;
	for(int i = 0; i < size; i++){
		cin >> temp;
		vec.push_back(temp);
	}
	merge_sort(0, size-1);
	cout << "After sorting: " << endl;

	for(int i = 0; i < size; i++){
		cout << vec[i] << endl;
	}

	return 0;
}
