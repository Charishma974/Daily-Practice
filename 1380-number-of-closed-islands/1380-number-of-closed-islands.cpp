class Solution {
public:
    void dfs(int i,int j,int numRows,int numCols,vector<vector<bool>>& visited,vector<vector<int>>& grid,vector<pair<int,int>>& dir){
        visited[i][j]=true;
        for (auto k:dir){
            int newRow=k.first+i;
            int newCol=k.second+j;
            if (newRow>=0 && newRow<numRows && newCol>=0 && newCol<numCols){
                if (grid[newRow][newCol]==0 && !visited[newRow][newCol]){
                    dfs(newRow,newCol,numRows,numCols,visited,grid,dir);
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int numRows=grid.size();
        int numCols=grid[0].size();
        vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<bool>> visited(numRows,vector<bool>(numCols,false));
        for (int i=0;i<numRows;i++){
            for (int j=0;j<numCols;j++){
                if (i==0 || i==numRows-1 || j==0 || j==numCols-1){
                    if (grid[i][j]==0 && !visited[i][j]){
                        dfs(i,j,numRows,numCols,visited,grid,dir);
                    }
                }
            }
        }
        int cnt=0;
        for (int i=0;i<numRows;i++){
            for (int j=0;j<numCols;j++){
                if (grid[i][j]==0 && !visited[i][j]){
                    dfs(i,j,numRows,numCols,visited,grid,dir);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};