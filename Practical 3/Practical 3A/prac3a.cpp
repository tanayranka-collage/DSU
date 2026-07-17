#include <iostream>   // practical 3a of dsu linear search
using namespace std;
int main(){
    int n, target, flag = 0, temp;
    cout << "Enter a length: ";
    cin >> n;
    int arr[n];
    cout << endl;
    for(int i=0; i<n;i++){
        cout << "Enter " << i+1 << " element: ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Enter a number to search: ";
    cin >> target;
    for(int i=0; i<n;i++){
        if(arr[i] == target){
            // flag++;
            flag = 1;
            temp = i+1;
            break;
        }
    }
    if (flag > 0){
        cout << "Found Element at index: " << temp << endl;
    }
    else{
        cout << "Element not in the array" << endl;
    }
    return 0;
}