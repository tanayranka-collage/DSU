//code by tanay Ranka sycse b 7

#include <stdio.h>
#include <string.h>

long int Mul(int a, int b){
    if(b == 0){
        return 0;
    }else{
        return a + Mul(a, b-1);
    }
}

void reverse(char str[]){
    if(str[0] == '\0'){
        return;
    }
    reverse(str+1);
    printf("%c", str[0]);
}

int main() {
    char s[100];
    printf("%d\n", Mul(77,10));
    printf("enter string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';
    reverse(s);
    return 0;
}
