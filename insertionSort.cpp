#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;


void insertionSortRec(int arr[], int n) {
    if (n <= 1) return;

    insertionSortRec(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = last;
}


void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    for (int i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        merged[size1 + i] = arr2[i];
    }
}

int main() {
    int arr_1[MAX_SIZE], arr_2[MAX_SIZE], sortedArr[2 * MAX_SIZE];
    int size_1, size_2, k;

    cout << "Enter the size of Array 1: ";
    cin >> size_1;
    cout << "Enter the elements of Array 1 'sorted':" << endl;
    for (int i = 0; i < size_1; i++) {
        cin >> arr_1[i];
    }

    cout << "Enter the size of Array 2: ";
    cin >> size_2;
    cout << "Enter the elements of Array 2 'sorted':" << endl;
    for (int i = 0; i < size_2; i++) {
        cin >> arr_2[i];
    }

    cout << "Enter k position: ";
    cin >> k;

    if (k < 1 || k > size_1 + size_2) {
        cout << "Error: k is out of range!" << endl;
        return 1;
    }

    mergeArrays(arr_1, size_1, arr_2, size_2, sortedArr);

    insertionSortRec(sortedArr, size_1 + size_2);


    cout << "The " << k << "-th element in the merged array is: " << sortedArr[k - 1] << endl;

    return 0;
}
