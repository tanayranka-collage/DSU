#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Function to reverse a string
void strrev_custom(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to convert string to uppercase
void strupr_custom(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to convert string to lowercase
void strlwr_custom(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char str1[100], str2[100], copy[100];
    char ch;

    cout << "Enter first string: ";
    cin.getline(str1, 100);

    cout << "Enter second string: ";
    cin.getline(str2, 100);

    // strlen()
    cout << "\nLength of first string = " << strlen(str1) << endl;
    cout << "Length of second string = " << strlen(str2) << endl;

    // strcmp()
    int result = strcmp(str1, str2);
    if (result == 0)
        cout << "Both strings are equal.\n";
    else if (result > 0)
        cout << "First string is greater than second string.\n";
    else
        cout << "First string is smaller than second string.\n";

    // strcpy()
    strcpy(copy, str1);
    cout << "Copied string = " << copy << endl;

    // strcat()
    strcat(str1, str2);
    cout << "Concatenated string = " << str1 << endl;

    // strrev()
    strrev_custom(copy);
    cout << "Reversed copied string = " << copy << endl;

    // strupr()
    strupr_custom(copy);
    cout << "Uppercase string = " << copy << endl;

    // strlwr()
    strlwr_custom(copy);
    cout << "Lowercase string = " << copy << endl;

    // strchr()
    cout << "Enter a character to search: ";
    cin >> ch;

    char *ptr = strchr(str1, ch);

    if (ptr != NULL)
        cout << "Character found at position " << (ptr - str1 + 1) << endl;
    else
        cout << "Character not found." << endl;

    return 0;
}