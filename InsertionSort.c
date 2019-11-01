#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int *arr, int n)
{
    int i, j, t, temp;

    for(j = 2; j <= n; j++){
        temp = arr[j];
        i = j-1;

        while(temp < arr[i]){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = temp;
        printf("Pass: \n");
        for(t = 1; t <= n; t++){
            printf("%d ", arr[t]);
        }
        printf("\n");
    }

    printf("Sorted array: \n");
    for(i = 1; i <= n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main()
{
    int *arr, size, i;
    printf("Enter size: ");
    scanf("%d", &size);

    arr = (int*)calloc(size, sizeof(int));

    for(i = 1; i < size; i++){
        scanf("%d", &arr[i]);
    }

    arr[0] = -2147483647;

    insertion_sort(arr, size-1);

    return 0;
}
