//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
int findMin(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    // If the array is not rotated, the first element is the minimum
    if (arr[left] <= arr[right]) {
        return arr[left];
    }

    while (left < right) {
        int mid = left + (right - left) / 2;

        // Check if mid+1 is the minimum element
        if (arr[mid] > arr[mid + 1]) {
            return arr[mid + 1];
        }

        // Check if mid itself is the minimum element
        if (arr[mid] < arr[mid - 1]) {
            return arr[mid];
        }

        // Decide the search space
        if (arr[mid] > arr[right]) {
            // Minimum is in the right half
            left = mid + 1;
        } else {
            // Minimum is in the left half
            right = mid - 1;
        }
    }

    return arr[left];
}

};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends