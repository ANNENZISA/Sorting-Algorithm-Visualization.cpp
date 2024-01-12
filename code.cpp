#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>

using namespace std;

void displayArray(const vector<int>& arr, int currentIndex = -1, int sortedIndex = -1) {
    system("clear"); // For Unix-like systems; use "cls" for Windows

    cout << "Sorting in progress:\n";
    for (int i = 0; i < arr.size(); ++i) {
        if (i == currentIndex) {
            cout << "[" << arr[i] << "] ";
        } else if (i <= sortedIndex) {
            cout << arr[i] << " ";
        } else {
            cout << arr[i] << " ";
        }
    }
    cout << "\n";
    this_thread::sleep_for(chrono::milliseconds(100)); // Delay for visualization
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                displayArray(arr, j, n - i - 1);
            }
        }
    }
}

int main() {
    vector<int> arrayToSort = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array:\n";
    displayArray(arrayToSort);

    cout << "Press Enter to start the Bubble Sort...";
    cin.ignore();

    bubbleSort(arrayToSort);

    cout << "Sorted array:\n";
    displayArray(arrayToSort);

    return 0;
}
