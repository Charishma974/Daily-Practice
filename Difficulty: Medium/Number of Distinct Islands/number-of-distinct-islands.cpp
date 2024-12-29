//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void bfs(int row,int col,int numRows,int numCols,vector<vector<bool>>& visited,set<vector<pair<int,int>>>& st,vector<vector<int>>& grid){
        queue<pair<int,int>> que;
        que.push({row,col});
        visited[row][col]=true;
        vector<pair<int,int>> temp;
        vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        while (!que.empty()){
            int i=que.front().first;
            int j=que.front().second;
            que.pop();
            for (auto k:dir){
                int newRow=i+k.first;
                int newCol=j+k.second;
                if (newRow>=0 && newRow<numRows && newCol>=0 && newCol<numCols){
                    if (grid[newRow][newCol]==1 && !visited[newRow][newCol]){
                        temp.push_back({newRow-row,newCol-col});
                        que.push({newRow,newCol});
                        visited[newRow][newCol]=true;
                    }
                }
            }
        }
        st.insert(temp);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int numRows=grid.size();
        int numCols=grid[0].size();
        vector<vector<bool>> visited(numRows,vector<bool>(numCols,false));
        set<vector<pair<int,int>>> st;
        for (int row=0;row<numRows;row++){
            for (int col=0;col<numCols;col++){
                if (grid[row][col]==1 && !visited[row][col]){
                    bfs(row,col,numRows,numCols,visited,st,grid);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends