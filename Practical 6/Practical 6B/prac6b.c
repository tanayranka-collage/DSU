//code by tanay ranka sycse b 8
#include <stdio.h>
#include <string.h>
int main(){
    int n;
    char temp[100];
    printf("Engter length: ");
    scanf("%d", &n);
    getchar();
    char arr[n][100];
    for(int i=0;i<n;i++){
        printf("Enter value: ");
        fgets(arr[i], sizeof(arr[i]), stdin);
    }
    //selection sort
    for(int i=0;i<n-1;i++){
        int min_idx = i;
        for(int j=i+1;j<n;j++){
            if(strcmp(arr[min_idx], arr[j]) > 0){
                min_idx = j;
            }
        }
        strcpy(temp, arr[min_idx]);
        strcpy(arr[min_idx], arr[i]);
        strcpy(arr[i], temp);
    }
  printf("\nSorted Array");
    for(int i=0;i<n;i++){
        printf(" %s ", arr[i]);
    }
    return 0;
}
