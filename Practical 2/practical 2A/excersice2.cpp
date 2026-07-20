#include <iostream>
using namespace std;
int main() {
    int no, count=0;
    cout << "Enter the number: ";
    cin >> no;
    
    for(int i=0;i<8;i++){
        if((no & 1<<i) > 0){
            count++;
        }
    }
    cout << endl;
    cout << "no. of bits set to 1 are: " << count << endl;
    return 0;
}
