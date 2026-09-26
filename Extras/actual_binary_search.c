#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

#include <math.h>

int main() {
    // binary search in C
    int n, tar;
    int found = 0;
    bool there = false;
    unsigned int i,j;
    size_t length = sizeof(int);
    printf("Enter length: ");
    scanf("%d", &n);
    int *arr = (int*)calloc(n, length);
    for(i=0;i<n;i++){
        printf("Value: ");
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(arr[j] > arr[j+1]){
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
    sleep(1);
    printf("target:? ");
    scanf("%d", &tar);
    int high = n-1;
    int low = 0;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == tar){
            found = mid+1;
            there = true;
            break;
        }else if(arr[mid] > tar){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    sleep(1);
    if(there){
        printf("found element at POS: %d\n", found);
    }else{
        printf("elemnet not found.\n");
    }
    return 0;
}
