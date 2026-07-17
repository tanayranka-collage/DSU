#include <iostream>
using namespace std;

int main() {
    int arr[10] = {10, 10, 10, 20, 20, 2323, 23, 23, 2394, 342};
    int a, occ=0, ok=0;
    cout << "target: ";
    cin >> a;
    for(int i=0;i<10;i++){
        if(arr[i] == a){
            occ++;
            ok = 1;
        }
    }
    cout << endl;
    if(ok == 1){
        cout << "Found " << occ << " times." << endl;
    }else{
        cout << "element not found.";
    }

    return 0;
}