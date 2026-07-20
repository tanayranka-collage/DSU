#include <iostream>
#include <string>
using namespace std;

int main() {
    string text[] = {"apple", "Carrot", "Banana", "apple", "apple"};
    string target;
    int count=0;
    cout << "Enter the target string: ";
    cin >> target;
    for(int i=0;i<size(text);i++){
        if(text[i] == target){
            count++;
        }
    }
    if(count > 0){
        cout << "There are multiple occurences of the string";
    }else{
        cout << "No string found.";
    }
    return 0;
}
