//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
void mergeArrays(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();
    int gap = ceil((n + m) / 2.0); // Initial gap size

    while (gap > 0) {
        int i = 0, j = gap;
        // Compare within the first array
        while (j < n) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
            i++;
            j++;
        }

        // Compare across both arrays
        j -= n; // Start `j` in the second array if it exceeds `n`
        while (i < n && j < m) {
            if (a[i] > b[j]) {
                swap(a[i], b[j]);
            }
            i++;
            j++;
        }

        // Compare within the second array
        i -= n; // Start `i` in the second array
        while (j < m) {
            if (b[i] > b[j]) {
                swap(b[i], b[j]);
            }
            i++;
            j++;
        }

        // Update the gap
        gap = (gap == 1) ? 0 : ceil(gap / 2.0);
    }
}

};

//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Inputting the test cases

    while (t--) {
        vector<int> a, b;

        // Reading the first array as a space-separated line
        string arr1;
        getline(cin >> ws, arr1); // Use ws to ignore any leading whitespace
        stringstream ss1(arr1);
        int num;
        while (ss1 >> num) {
            a.push_back(num);
        }

        // Reading the second array as a space-separated line
        string arr2;
        getline(cin, arr2);
        stringstream ss2(arr2);
        while (ss2 >> num) {
            b.push_back(num);
        }

        Solution ob;
        ob.mergeArrays(a, b);

        // Output the merged result
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends