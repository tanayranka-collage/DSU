#include <iostream>
using namespace std;

int main() {
    int arr[100], n, choice;

    // Input array
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    do {
        cout << endl;
        cout << "1. Insert Element\n";
        cout << "2. Delete Element\n";
        cout << "3. Display Array\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int pos, value;

                cout << "Enter the position (1 to " << n + 1 << "): ";
                cin >> pos;

                if (pos < 1 || pos > n + 1) {
                    cout << "Invalid position!\n";
                    break;
                }

                cout << "Enter the value to insert: ";
                cin >> value;

                for (int i = n; i >= pos; i--) {
                    arr[i] = arr[i - 1];
                }

                arr[pos - 1] = value;
                n++;

                cout << "Element inserted successfully.\n";
                break;
            }

            case 2: {
                int pos;

                cout << "Enter the position to delete (1 to " << n << "): ";
                cin >> pos;

                if (pos < 1 || pos > n) {
                    cout << "Invalid position!\n";
                    break;
                }

                for (int i = pos - 1; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }

                n--;

                cout << "Element deleted successfully.\n";
                break;
            }

            case 3: {
                if (n == 0) {
                    cout << "Array is empty.\n";
                } else {
                    cout << "Array elements are: ";
                    for (int i = 0; i < n; i++) {
                        cout << arr[i] << " ";
                    }
                    cout << endl;
                }
                break;
            }

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}