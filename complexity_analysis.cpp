#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*
=====================================================
Exercise 1: Time Complexity Examples
=====================================================
*/

// Example A - O(1)
void exampleA(int n) {
    cout << n << endl;
}

// Example B - O(n)
void exampleB(int n) {
    for (int i = 0; i < n; i++) {
        cout << i << endl;
    }
}

// Example C - O(log n)
void exampleC(int n) {
    for (int i = 1; i < n; i *= 2) {
        cout << i << endl;
    }
}

// Example D - O(n^2)
void exampleD(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << " " << j << endl;
        }
    }
}

// Example E - O(n log n)
void exampleE(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j *= 2) {
            cout << i << " " << j << endl;
        }
    }
}

/*
=====================================================
Exercise 2: Duplicate Detection
=====================================================
*/

// Inefficient Version - O(n^2)
bool hasDuplicate(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}

// Improved Version A - Sort First (O(n log n))
bool hasDuplicateSort(int arr[], int n) {
    sort(arr, arr + n);

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            return true;
        }
    }
    return false;
}

// Improved Version B - Hashing (Average O(n))
bool hasDuplicateHash(int arr[], int n) {
    unordered_set<int> seen;

    for (int i = 0; i < n; i++) {
        if (seen.find(arr[i]) != seen.end()) {
            return true;
        }
        seen.insert(arr[i]);
    }

    return false;
}

/*
=====================================================
Main Function (Testing Section)
=====================================================
*/

int main() {

    int n = 5;

    cout << "Running Example Functions:\n" << endl;

    exampleA(n);
    exampleB(n);
    exampleC(n);

    int arr[] = {1, 2, 3, 4, 2};
    int size = 5;

    cout << "\nDuplicate Check Results:\n" << endl;

    cout << "Inefficient: "
         << (hasDuplicate(arr, size) ? "Duplicate Found" : "No Duplicate")
         << endl;

    cout << "Hash Version: "
         << (hasDuplicateHash(arr, size) ? "Duplicate Found" : "No Duplicate")
         << endl;

    return 0;
}
