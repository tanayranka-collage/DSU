// code by tanay ranka sycse b 8
#include<string.h>
#include <stdio.h>

int main() {
    char *arr[] = {"apple", "banana", "cherry", "dates", "figs", "zebra"};
    int n = sizeof(arr) / sizeof(arr[0]);
    char temp[100];
    printf("put target ");
    fgets(temp, sizeof(temp), stdin);
    const char *target = NULL;
    temp[strcspn(temp, "\n")] = '\0';
    target = temp;
    int low=0;
    int high = n - 1;
    int found=0;
    while (low <= high){
        int mid = low + (high - low) / 2;
        int r = strcmp(target, arr[mid]);
        if (r == 0){
            found = mid + 1;
        }
        
        if (r > 0){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    if ( found > 0){ 
        printf("target at %d", found);
    }else{
        printf("nahh");
    }

    return 0;
}
