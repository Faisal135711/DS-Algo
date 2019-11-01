#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> vec;

int left(int i)
{
	return 2*i+1;
}
int right(int i)
{
	return 2*i+2;
}
void Max_Heapify(int i, int Heap_size)
{
	int l = left(i);
	int r = right(i);
	int largest;

	if(l < Heap_size && vec[i] <= vec[l]){
		largest = l;
	}
	else{
		largest = i;
	}
	if(r < Heap_size && vec[largest] <= vec[r]){
		largest = r;
	}
	if(largest != i){
		swap(vec[largest], vec[i]);
		Max_Heapify(largest, Heap_size);
	}
}
void HeapSort(int size)
{
    for(int i = (size/2)-1; i >= 0; i--){
        Max_Heapify(i, size);
    }
    for(int i = size-1; i >= 0; i--){
        swap(vec[0], vec[i]);
        Max_Heapify(0, i);
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

    HeapSort(size);

    cout << "After sorting: " << endl;
    for(int i = 0; i < size; i++){
        cout << vec[i] << " ";
    }
    cout << endl;

	return 0;
}
