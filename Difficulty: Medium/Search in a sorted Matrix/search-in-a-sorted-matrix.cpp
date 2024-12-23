//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
bool searchMatrix(vector<vector<int>>& mat, int x) {
    int n = mat.size();
    int m = mat[0].size();
    int row = 0, col = m - 1;  // Start from top-right corner

    while (row < n && col >= 0) {
        if (mat[row][col] == x) {
            return true;
        } else if (mat[row][col] > x) {
            col--;  // Move left
        } else {
            row++;  // Move down
        }
    }

    return false;  // If we exit the loop, the element is not found
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends