#include <stdio.h>
#include <stdlib.h>
void test(void){
    printf("\nHave a bad day Sir.");
}

int main(){
    int n;
    int* t = &n;
    printf("Max length: ");
    scanf("%d", t);

    
    size_t se = sizeof(n);  // size_t is output type of sizeof() operator [bytes]


    // int* arr = (int*)malloc(n * se);
    int* array = (int*)calloc(n, se);  // continous alloaction of memory
    n++;
    int* arr = (int*)realloc(array, n * se); // reallocating the buffer size

    size_t total = sizeof(arr);
    printf("total size: %d\n", total);
    
    for(unsigned int i=0;i<n;i++){
        printf("Vlue: ");
        scanf("%d", &arr[i]);
    }

    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[min] > arr[j])
                min = j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    
    for(unsigned int i=0;i<n;i++){
        printf("  %d  ", arr[i]);
    }

    printf("\n");
    printf("Random Values are upto: %d\n", RAND_MAX);
    
    for (unsigned int i=0; i<3; i++){
        printf("  %d  ", rand()); // python equivalent of import random;random.randint()
    }
    atexit(test);   // runs test when the program exits.
    // free(t);
    free(arr);
    return 0;
}
