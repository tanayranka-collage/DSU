// code by tanay ranka sycse b 8
#include<stdio.h>
#include <string.h>
int binary_search(char *arr[], int low, int high, const char *target) {
    if (low > high) {
        return -1;
    }
    int mid = low + (high - low) / 2;

    int result = strcmp(target, arr[mid]);

    if (result == 0) {
        return mid;
    }

    if (result < 0) {
        return binary_search(arr, low, mid - 1, target);
    }
    return binary_search(arr, mid + 1, high, target);
}

int main(){
    // already sorted array
    char *arr[] = {"apple", "banana", "cherry", "date", "fig", "grape"};
    char temp[100];
    int n = sizeof(arr) / sizeof(arr[0]);
    // printf("ENter target: ");
    // fgets(temp, sizeof(temp), stdin);
    const char *target = "fig";
    
    int k = binary_search(arr, 0, n - 1, target);
    if(k != -1){
        printf("Element found at position %d", k+1);
    }else{
        printf("Element not found");
    }
    
    
    return 0;
}
