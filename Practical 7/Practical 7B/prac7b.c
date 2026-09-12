// code by tanay Ranka Male Vegetarian sycse b 8
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("enter lgn: ");
    scanf("%d", &n);
    getchar();
    char arr[n][100];
    char key[100];
    for(int i=0;i<n;i++){
        printf("val: ");
        fgets(arr[i], sizeof(arr[i]), stdin);
        arr[i][strcspn(arr[i], "\n")] = '\0';
    }
    for(int i=1;i<n;i++){
        strcpy(key, arr[i]);
        int j = i-1;
        while (j>=0 && strcmp(arr[j], key) > 0){
            strcpy(arr[j+1], arr[j]);
            j--;
        }
        strcpy(arr[j+1], key);
    }

    for(int i=0;i<n;i++){
        printf("%s\n", arr[i]);
    }
    return 0;
}
