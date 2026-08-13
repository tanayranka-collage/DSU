// code by tanay ranka sycse b 8
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n, temp;
    printf("Enter length: ");
    scanf("%d", &n);
    int *ps = (int*)malloc(n * sizeof(int));
    for(int i=0;i<n;i++){
        printf("Enter Value: ");
        scanf("%d", &ps[i]);
    }
    //bubble sort
    bool flag;
    for (int i=0;i<n-1;i++){
        flag = false;
        for(int j=0;j<n-i-1;j++){
            if(ps[j] > ps[j + 1]){
                int temp = ps[j];
                ps[j] = ps[j+1];
                ps[j+1] = temp;
                flag = true;
            }
        }
        if(flag == false){
            break;
        }
    }
    printf("\nArrAy: ");
    for(int i=0;i<n;i++){
        printf("\n%d", ps[i]);
    }


    free(ps);
    return 0;
}
