// code by tanay ranka sycse b 8
#include<string.h>
#include <stdio.h>

int main() {
    char *arr[] = {"zebra", "figs", "dates", "cherry", "banana", "apple"};
    int n = sizeof(arr) / sizeof(arr[0]);
    const char *target = NULL;
    char temp[100];
    printf("enter target: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';
    target = temp;
    int low = 0, found = 0;
    int high = n - 1;
    while (low <= high){
        int mid=low + (high - low) / 2;
        int r = strcmp(target, arr[mid]);
        if (r == 0){
            found = mid + 1;
        }
        if (r > 0){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    if (found > 0){
        printf("found at %d", found);
        
    }else{
        printf("fuck off");
    }

    return 0;
}

