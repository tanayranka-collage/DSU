//code by tanay ranka syces b 8
#include <stdio.h>

int main() {
    int nmu;
    printf("Enter a numbre: ");
    scanf("%d", &nmu);
    
    
    if((nmu & 1) > 0){
        printf("\n The number is ODD number.");
    }else{
        printf("\nThe number is EVEN number.");
    }

    return 0;
}
