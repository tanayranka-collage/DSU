#include <stdio.h>

int main() {
    int no,pos;
    printf("Enter the number: ");
    scanf("%d", &no);
    
    printf("Enter a nth position to check: ");
    scanf("%d", &pos);
    int t = pos - 1;
    if((no & 1<<t) > 0){
        printf("\nyes the nth bit is set to 1");
    }else{
        printf("\nno the nth bit is set to 0");
    }
    
    
    return 0;
}
