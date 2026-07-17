#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];
    bool palindrome = true;

    cout << "Enter a string: ";
    cin.getline(str, 100);

    int len = strlen(str);

    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            palindrome = false;
            break;
        }
    }

    if (palindrome)
        cout << "The string is a palindrome.";
    else
        cout << "The string is not a palindrome.";

    return 0;
}