
// code by tanay ranka sycse b 8
#include<stdio.h>
int binary_search(int arr[], int target, int low, int high){
    if(low > high){
        return -1;
    }
    int mid = low + (high - low) / 2;
    if(arr[mid] == target){
        return mid;
    }
    if(target < arr[mid]){
        return binary_search(arr, target, low, mid - 1);
    }
    return binary_search(arr, target, mid + 1,high);
}

int main(){
    int n, target;
    printf("Enter a length: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter Value: ");
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    printf("\nEnter target: ");
    scanf("%d", &target);
    int k = binary_search(arr, target, 0, n-1);
    if(k != -1){
        printf("Element found at position %d", k+1);
    }else{
        printf("Element not found");
    }
    
    
    return 0;
}
