#include <iostream>
using namespace std;

int main() {
    int arr[10] = {10, 20, 12, 34, 4234, 43,42,4,234, 34};
    int a, o=0;
    cout << "Enter target: ";
    cin >> a;
    for(int i=0;i<10;i++){
        if(arr[i] == a){
            o = i + 1;
            break;
        }
    }
    if (o > 0){
        cout << "element found at pos: " << o << endl;
        cout << "No. of comparisions made: " << o << endl;
    }else{
        cout << "neelemt not found.";
    }

    return 0;
}