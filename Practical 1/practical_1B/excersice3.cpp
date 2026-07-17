#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[200];
    int words = 0;

    cout << "Enter a sentence: ";
    cin.getline(str, 200);

    for (int i = 0; str[i] != '\0'; i++) {
        if ((i == 0 && str[i] != ' ') ||
            (str[i] != ' ' && str[i - 1] == ' '))
            words++;
    }

    cout << "Number of words = " << words << endl;

    return 0;
}