#include<stdio.h>
#include<stdlib.h>

void selection_sort(int *arr, int size)
{
    int i, j, t, temp, k;

    for(j = size-1; j >= 1; j--){
        t = 0;

        for(i = 1; i <= j; i++){
            if(arr[t] < arr[i]){
                t = i;
            }
        }
        temp = arr[j];
        arr[j] = arr[t];
        arr[t] = temp;

   /*     printf("Pass: \n");
        for(k = 0; k < size; k++){
            printf("%d ", arr[k]);
        }
        printf("\n");*/
    }

    printf("Sorted array: \n");
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int* arr, i, size;

    printf("Enter size: ");
    scanf("%d", &size);

    arr = (int*)calloc(size, sizeof(int));

    for(i = 0; i < size; i++){
       // scanf("%d", &arr[i]);
       arr[i] = rand() % 20000;
    }

    selection_sort(arr, size);

    return 0;
}
