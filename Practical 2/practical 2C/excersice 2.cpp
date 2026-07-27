//code by tanay ranka sucse b 8
#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter length: ";
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout << "Enter value: ";
        cin >> arr[i];
    }
    int counter = 0;
    for(int i=0;i<n;i++){
        if(arr[i] % 2 != 0){
            counter++;
        }
    }
    
    cout << endl;
    cout << "ODD numbers in array are: " << counter << endl;
    return 0;
}
