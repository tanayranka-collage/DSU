//code b tanay ranka sycse b 8
#include <stdio.h>

void main() {
    int n;
    printf("Enter max length: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("\nEnter Value: ");
        scanf("%d", &arr[i]);
    }
    int max_and = arr[0] | arr[1];
    for(int i=1;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int temp = arr[i] | arr[j];
            if(temp > max_and){
                max_and = arr[i] | arr[j];
            }
        }
    }
    
    printf("\n Max AND value of array is: %d", max_and);
  
}
