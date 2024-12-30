class Solution {
public:
    int bfs(int row,int col,int numRows,int numCols,vector<vector<bool>>& visited,vector<vector<int>>& grid){
        queue<pair<int,int>> que;
        que.push({row,col});
        visited[row][col]=true;
        int cnt=0;
        vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        while (!que.empty()){
            pair<int,int> node=que.front();
            cnt++;
            que.pop();
            for (auto k:dir){
                int newRow=k.first+node.first;
                int newCol=k.second+node.second;
                if (newRow>=0 && newRow<numRows && newCol>=0 && newCol<numCols){
                    if (grid[newRow][newCol]==1 && !visited[newRow][newCol]){
                        que.push({newRow,newCol});
                        visited[newRow][newCol]=true;
                    }
                }
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int numRows=grid.size();
        int numCols=grid[0].size();
        vector<vector<bool>> visited(numRows,vector<bool>(numCols,false));
        int maxi=INT_MIN;
        for (int i=0;i<numRows;i++){
            for (int j=0;j<numCols;j++){
                if (grid[i][j]==1 && !visited[i][j]){
                    maxi=max(maxi,bfs(i,j,numRows,numCols,visited,grid));
                }
            }
        }
        return maxi==INT_MIN ? 0 : maxi;
    }
};