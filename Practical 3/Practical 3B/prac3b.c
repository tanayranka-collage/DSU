#include <stdio.h>
#include <string.h>
int main() {
    char *arr[] = {"Apple", "Banana", "Cherry", "Coconut", "Blueberry", "Tomato"};
    int f=0;
    char target[100];
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Give a target string to search: ");
    scanf("%s", target);
    
    for(int i=0;i<size;i++){
        if(strcmp(arr[i], target) == 0) {
            f = f + i + 1;
            break;
        }
        
    }
    if(f>0){
        printf("tareget found at position: %d", f);
    }else{
        printf("Element not found.");
    }
    return 0;
}
