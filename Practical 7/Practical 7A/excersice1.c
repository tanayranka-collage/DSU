// code by tanaya ranka sycse b 8
include <stdio.h>
#include <stdlib.h>

int main() {
    int n, key, i, j, count, swaps;
    count = 0;
    swaps = 0;
    printf("len: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    for(i=0;i<n;i++){
        printf("val: ");
        scanf("%d", &arr[i]);
    }

    for(i=1;i<n;i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j] < key){
            swaps++;
            arr[j+1] = arr[j];
            j--;
        }
        count++;
        arr[j+1] = key;
    }
    printf("counts %d\n", count);
    printf("swaps: %d\n", swaps);
    printf("sorted array:\n");
    for (i=0;i<n;i++){
        printf(" %d ", arr[i]);
    }
    free(arr);

    return 0;
}
