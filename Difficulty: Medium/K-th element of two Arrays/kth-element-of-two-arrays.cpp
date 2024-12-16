//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
int kthElement(vector<int>& a, vector<int>& b, int k) {
    int n = a.size();
    int m = b.size();
    
    // Ensure that `a` is the smaller array to minimize binary search complexity
    if (n > m) {
        return kthElement(b, a, k);
    }

    int low = max(0, k - m), high = min(k, n);

    while (low <= high) {
        int partitionA = (low + high) / 2;
        int partitionB = k - partitionA;

        int maxLeftA = (partitionA == 0) ? INT_MIN : a[partitionA - 1];
        int minRightA = (partitionA == n) ? INT_MAX : a[partitionA];

        int maxLeftB = (partitionB == 0) ? INT_MIN : b[partitionB - 1];
        int minRightB = (partitionB == m) ? INT_MAX : b[partitionB];

        if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
            return max(maxLeftA, maxLeftB);
        } else if (maxLeftA > minRightB) {
            high = partitionA - 1;
        } else {
            low = partitionA + 1;
        }
    }

    return -1; // This should never be reached if inputs are valid
}

};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends