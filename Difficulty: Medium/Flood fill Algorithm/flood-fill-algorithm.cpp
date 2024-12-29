//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int newColor) {
        queue<pair<int,int>> que;
        if (sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || image[sr][sc]==newColor) return image;
        int prevColor=image[sr][sc];
        que.push({sr,sc});
        vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        while (!que.empty()){
            pair<int,int> node=que.front();
            image[node.first][node.second]=newColor;
            que.pop();
            for (auto k:dir){
                int newRow=k.first+node.first;
                int newCol=k.second+node.second;
                if (newRow>=0 && newRow<image.size() && newCol>=0 && newCol<image[0].size() && image[newRow][newCol]==prevColor){
                    que.push({newRow,newCol});
                }
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends