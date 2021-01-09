#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<ll,ll> pll;
typedef pair<int, int> pii;

#define N 100010
#define M 200010
#define X 110
#define Y 1010
#define Z 10010
#define endl "\n"
#define mod 1000000007

int arr[110];

int partition(int s, int e){
    int p_index = s;
    int pivot = arr[e];

    for(int i = s; i < e; i++){
        if(arr[i] <= pivot){
            swap(arr[i], arr[p_index++]);
        }
    }

    swap(arr[p_index], arr[e]);

    return p_index;
}

void quick_sort(int s, int e){
    if(s < e){
        int p = partition(s, e);
        quick_sort(s, p - 1);
        quick_sort(p + 1, e);
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);

    int n;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    quick_sort(0, n - 1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }

    return 0;
}
