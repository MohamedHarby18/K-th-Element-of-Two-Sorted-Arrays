#include <iostream>
using namespace std;
const int MAX_SIZE = 1000;

int NonRec_Fun(int arr_1[], int size_1, int arr_2[], int size_2, int sortedArr[], int k) {
    int i = 0, j = 0, sortedArrayIndex = 0;


    while (i < size_1 && j < size_2) {
        if (arr_1[i] < arr_2[j]) {
            sortedArr[sortedArrayIndex++] = arr_1[i++];
        } else {
            sortedArr[sortedArrayIndex++] = arr_2[j++];
        }
    }

    while (i < size_1) {
        sortedArr[sortedArrayIndex++] = arr_1[i++];
    }

    while (j < size_2) {
        sortedArr[sortedArrayIndex++] = arr_2[j++];
    }


    if (k >= 1 && k <= sortedArrayIndex) {
        return sortedArr[k - 1];
    } else {
        return -1;
    }
}

int main() {
    int arr_1[MAX_SIZE], arr_2[MAX_SIZE], sortedArr[2 * MAX_SIZE];
    int size_1, size_2, k;

    cout << "Enter the size of Array 1: ";  cin >> size_1;
    cout << "Enter the elements of Array 1 'sorted': " << endl;
    for (int i = 0; i < size_1; i++) {
        cin >> arr_1[i];
    }

    cout << "Enter the size of Array 2: ";
    cin >> size_2;
    cout << "Enter the elements of Array 2 'sorted': " << endl;
    for (int i = 0; i < size_2; i++) {
        cin >> arr_2[i];
    }

    cout << "Enter k position: ";
    cin >> k;

    if (k < 1 || k > size_1 + size_2) {
        cout << "Error: k is out of range!" << endl;
        return 1;
    }


    int k_Element = NonRec_Fun(arr_1, size_1, arr_2, size_1,sortedArr, k);


    cout << "The " << k << "-th element in the merged array is: " << k_Element << endl;

    return 0;
}



