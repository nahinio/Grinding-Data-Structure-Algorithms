#include <bits/stdc++.h>
using namespace std;

/*
// Bad binary search (may overflow)
int badBinarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        // may overflow when low + high > INT_MAX
        int mid = (low + high) / 2;

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
*/

// Good binary search (no overflow)
int goodBinarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        // Safe way - avoids overflow
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    // Example: very large numbers to simulate overflow
    vector<int> arr = {2000000000, 2100000000};    // 2e9 and 2.1e9
    int target = 2100000000;

    // Demonstrate wrong mid
   //  int badMid  = (arr[0] + arr[1]) / 2;    // may overflow
    
    int goodMid = arr[0] + (arr[1] - arr[0]) / 2;    // safe
    cout << "Good mid = " << goodMid << endl;

    cout << "Good binary search result = " << goodBinarySearch(arr, target) << endl;

    return 0;
}
