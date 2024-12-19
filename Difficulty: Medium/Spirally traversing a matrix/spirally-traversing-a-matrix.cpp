//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
vector<int> spirallyTraverse(vector<vector<int>> &mat) {
    vector<int> result;
    int n = mat.size();
    int m = mat[0].size();
    
    // Define boundaries for the traversal
    int top = 0, bottom = n - 1, left = 0, right = m - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right
        for (int i = left; i <= right; i++) {
            result.push_back(mat[top][i]);
        }
        top++; // Move the top boundary down

        // Traverse from top to bottom
        for (int i = top; i <= bottom; i++) {
            result.push_back(mat[i][right]);
        }
        right--; // Move the right boundary left

        if (top <= bottom) {
            // Traverse from right to left
            for (int i = right; i >= left; i--) {
                result.push_back(mat[bottom][i]);
            }
            bottom--; // Move the bottom boundary up
        }

        if (left <= right) {
            // Traverse from bottom to top
            for (int i = bottom; i >= top; i--) {
                result.push_back(mat[i][left]);
            }
            left++; // Move the left boundary right
        }
    }

    return result;
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends