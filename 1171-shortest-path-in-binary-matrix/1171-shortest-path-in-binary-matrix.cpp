class Solution {
public:
    int bfs(int i,int j,int numRows,int numCols,vector<pair<int,int>>& dir,vector<vector<int>>& grid){
        queue<pair<int,int>> que;
        que.push({i,j});
        int level=1;
        vector<vector<bool>> visited(numRows,vector<bool>(numCols,false));
        visited[i][j]=true;
        while (!que.empty()){
            int size=que.size();
            for (int i=0;i<size;i++){
                pair<int,int> currNode=que.front();
                if (currNode.first==numRows-1 && currNode.second==numCols-1) return level;
                que.pop();
                for (auto k:dir){
                    int newRow=k.first+currNode.first;
                    int newCol=k.second+currNode.second;
                    if (newRow>=0 && newRow<numRows && newCol>=0 && newCol<numCols){
                        if (grid[newRow][newCol]==0 && !visited[newRow][newCol]){
                            que.push({newRow,newCol});
                            visited[newRow][newCol]=true;
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int numRows=grid.size();
        int numCols=grid[0].size();
        if (grid[0][0]!=0) return -1;
        vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
        return bfs(0,0,numRows,numCols,dir,grid);
    }
};