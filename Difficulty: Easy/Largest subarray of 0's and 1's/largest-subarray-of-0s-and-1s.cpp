//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int n=arr.size();
        unordered_map<int, int> hM;

    int sum = 0; // Initialize sum of elements
    int max_len = 0; // Initialize result
    int ending_index = -1;

    for (int i = 0; i < n; i++)
        arr[i] = (arr[i] == 0) ? -1 : 1;

    // Traverse through the given array

    for (int i = 0; i < n; i++) {
        // Add current element to sum

        sum += arr[i];

        // To handle sum=0 at last index

        if (sum == 0) {
            max_len = i + 1;
            ending_index = i;
        }

        // If this sum is seen before, then update max_len
        // if required

        if (hM.find(sum) != hM.end()) {
            if (max_len < i - hM[sum]) {
                max_len = i - hM[sum];
                ending_index = i;
            }
        }
        else // Else put this sum in hash table
            hM[sum] = i;
    }

    for (int i = 0; i < n; i++)
        arr[i] = (arr[i] == -1) ? 0 : 1;

    return max_len;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends