#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};

    int totalSize = sizeof(arr);
    int elementSize = sizeof(arr[0]);
    int numberOfElements = totalSize / elementSize;

    cout << "Total size of array = " << totalSize << " bytes" << endl;
    cout << "Size of one element = " << elementSize << " bytes" << endl;
    cout << "Number of elements = " << numberOfElements << endl;

    return 0;
}