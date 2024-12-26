//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
bool twoSum(vector<int>& arr, int target) {
    unordered_map<int, int> seen; // Map to store numbers and their indices

    for (int num : arr) {
        int complement = target - num; // Calculate the complement
        if (seen.find(complement) != seen.end()) {
            return true; // Pair found
        }
        seen[num] = 1; // Mark the current number as seen
    }

    return false; // No pair found
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.twoSum(arr, x);
        cout << (ans ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends