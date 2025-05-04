#include <iostream>
using namespace std;

void mergeRecursive(int arr1[], int size1, int arr2[], int size2,
                    int merged[], int i = 0, int j = 0, int k = 0) {
    // Base case
    if (i == size1 && j == size2) {
        return;
    }

    if (i == size1) {
        merged[k] = arr2[j];
        mergeRecursive(arr1, size1, arr2, size2, merged, i, j + 1, k + 1);
    } else if (j == size2) {
        merged[k] = arr1[i];
        mergeRecursive(arr1, size1, arr2, size2, merged, i + 1, j, k + 1);
    }
    // Compare the smaller element
    else if (arr1[i] < arr2[j]) {
        merged[k] = arr1[i];
        mergeRecursive(arr1, size1, arr2, size2, merged, i + 1, j, k + 1);
    } else {
        merged[k] = arr2[j];
        mergeRecursive(arr1, size1, arr2, size2, merged, i, j + 1, k + 1);
    }
}

int main() {
    int m, n, k;

    cout << "Enter size of Array 1: ";
    cin >> m;
    int A[m];
    cout << "Enter elements of Array 1 (sorted): ";
    for (int i = 0; i < m; i++) {
        cin >> A[i];
    }

    cout << "Enter size of Array 2: ";
    cin >> n;
    int B[n];
    cout << "Enter elements of Array 2 (sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    int mergedArr[m+n];

    mergeRecursive(A, m, B, n, mergedArr);

    cout << "Enter value of k: ";
    cin >> k;

    if (k < 1 || k > m + n) {
        cout << "Invalid value of k!" << endl;
    } else {
        int result = mergedArr[k-1];
        cout << "The " << k << "-th element in the merged array is: " << result << endl;
    }

    return 0;
}
