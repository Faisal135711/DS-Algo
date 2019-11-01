#include<stdio.h>
#include<stdlib.h>

int main(){
    int i, k, n, t, j, temp;
    int *arr;

    printf("Enter n: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    for(i = 1; i <= n; i++){
        scanf("%d", (arr+i));
    }

    k = n;
    while(k!=0){
        t = 0;
        for(j = 1; j <= k-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                t = j;
            }
        }
        k = t;
        printf("k = %d\n", k);
      //  if(t == 0) break;
        printf("Pass:\n");
        for(i = 1; i <= n; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    for(i = 1; i <= n ; i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}

