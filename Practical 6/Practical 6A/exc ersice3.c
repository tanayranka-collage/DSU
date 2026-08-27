//code by tanay ranka sycse b 8

#include <stdio.h>

int main() {
    int n;
    printf("Enter length: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Values: ");
        scanf("%d", &arr[i]);
    }
    //selection sort
    int count = 0;
    for(int i=0;i<n-1;i++){
        int min_index = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }

        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
        count++;
    }
    printf("\nSorted Array: ");
    for(int i=0;i<n;i++){
        printf(" %d ", arr[i]);
    }
    printf("\nSwaps: %d", count);

    return 0;
}
