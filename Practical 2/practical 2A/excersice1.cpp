#include <iostream>
using namespace std;
int main(){
    int a, new_de, n;
    cout << "Enter a number ";
    cin >> a;
    cout << "Enter position to toggle: ";
    cin >> n;
    
    int t = n - 1;
    new_de = a ^ 1<<t;
    cout << "toggled output number: " << new_de << endl;
    
    
    return 0;
}
