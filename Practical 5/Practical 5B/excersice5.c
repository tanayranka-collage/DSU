//code by tanay ranka sycse b 8
#include <stdio.h>
#include<string.h>

int main() {
    char temp[100];
    int n, count = 0;
    printf("Enter lenght: ");
    scanf("%d", &n);
    getchar();
    char arr[n][100];
    for(int i=0;i<n;i++){
        printf("Enetr Value: ");
        fgets(arr[i], sizeof(arr[i]), stdin);
    }
    //bubble sort:

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(strcmp(arr[j], arr[j + 1]) > 0){
                count++;
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
    }
    printf("\nSorted Array:\n");
    for(int i=0;i<n;i++){
        printf(" %s ", arr[i]);
    }
    printf("Number of comparisions performed: %d", count);

    return 0;
}
