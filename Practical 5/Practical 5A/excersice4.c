// code by tanay ranka sycse b 8
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter length: ");
    scanf("%d", &n);
    int *ps = (int*)malloc(n * sizeof(int));
    for(int i=0;i<n;i++){
        printf("Enter Value: ");
        scanf("%d", &ps[i]);
    }
    //bubble sort
    for (int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(ps[j] > ps[j + 1]){
                int temp = ps[j];
                ps[j] = ps[j+1];
                ps[j+1] = temp;
            }
        }
    }
    printf("\nLargest Element of array: %d\n", ps[n-1]);
    printf("Smallest element: %d\n", ps[0]);


    free(ps);
    return 0;
}
