
// code by tanay ranka sycse b 8
#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter length: ";
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout << "Enter Value: ";
        cin >> arr[i];
    }
    // sortin array  bubble sort
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j] < arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    int target;
    cout << "\nEnter a tagret number: ";
    cin >> target;

    // binary search
    int low = 0;
    int high = n - 1;
    int found = 0;
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (arr[mid] == target){
            found = mid + 1;
            break;
        }
        if(arr[mid] > target){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    if (found > 0){
        cout << "\n Target found at position: " << found;
    }else{
        cout << "\nTarget no tfound";
    }
    
    
    return 0;
}
