// #include <bits/stdc++.h>
// using namespace std;

// void toi(int n, char s, char d, char a) {
//     if (n == 0) return;
//     toi(n - 1, s, a, d);
//     cout << "Move disk " << n << " from " << s << " to " << d << endl;
//     toi(n - 1, a, d, s);
// }

// int main() {
//     int n;
//     cout << "Enter the number of disks: ";
//     cin >> n;
//     toi(n, 'A', 'C', 'B'); // Calling the tower of hanoi function
//     return 0;
// }

#include <iostream>
#include <vector>

using namespace std;

// Function to heapify a subtree rooted at index i.
// n is the size of the heap
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left child
    int right = 2 * i + 2; // right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    cout << "Original array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    heapSort(arr);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countSort(vector<int>& arr) {
    int max_element = *max_element(arr.begin(), arr.end()); // Find the maximum element in the array

    // Create a count array to store the count of each element
    vector<int> count(max_element + 1, 0);

    // Count the frequency of each element in the input array
    for (int num : arr)
        count[num]++;

    // Modify the count array to store the actual position of each element in the sorted array
    for (int i = 1; i <= max_element; ++i)
        count[i] += count[i - 1];

    // Create a temporary array to store the sorted output
    vector<int> output(arr.size());
    
    // Place the elements in the output array according to the count array
    for (int i = arr.size() - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements from the output array to the original array
    for (int i = 0; i < arr.size(); ++i)
        arr[i] = output[i];
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    cout << "Original array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    countSort(arr);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
