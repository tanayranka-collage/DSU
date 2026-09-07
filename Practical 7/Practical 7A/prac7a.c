//code by tanay ranka sycse b 8
// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

int main() {
    int n;
    printf("g: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i=0;i<n;i++){
        printf("v: ");
        scanf("%d", &arr[i]);
    }
    for(int i=1;i<n;i++){
        int key= arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
    for(int i=0;i<n;i++){
        printf("\n%d", arr[i]);
    }
    free(arr);
    return 0;
}
