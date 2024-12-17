//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
// Function to check if placing cows with a minimum distance `mid` is feasible
bool isFeasible(vector<int>& stalls, int k, int mid) {
    int countCows = 1; // Place the first cow in the first stall
    int lastPlaced = stalls[0]; // Position of last placed cow

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPlaced >= mid) {
            countCows++; // Place another cow
            lastPlaced = stalls[i]; // Update the position of the last placed cow
            if (countCows == k) return true; // If all cows are placed, return true
        }
    }
    return false; // Not possible to place all cows with at least `mid` distance
}

// Main function to find the largest minimum distance
int aggressiveCows(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end()); // Sort stall positions

    int low = 1; // Minimum possible distance
    int high = stalls[stalls.size() - 1] - stalls[0]; // Maximum possible distance
    int res = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isFeasible(stalls, k, mid)) {
            res = mid; // Update result (mid is a feasible distance)
            low = mid + 1; // Search for a larger minimum distance
        } else {
            high = mid - 1; // Search for a smaller distance
        }
    }
    return res; // Return the largest minimum distance
}

};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends