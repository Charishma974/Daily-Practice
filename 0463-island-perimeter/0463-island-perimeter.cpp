class Solution {
public:
    int bfs(int row,int col,int numRows,int numCols,set<pair<int,int>>& visited,vector<vector<int>>& grid){
        queue<pair<int,int>> que;
        que.push({row,col});
        visited.insert({row,col});
        int cnt=0;
        vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        while (!que.empty()){
            pair<int,int> node=que.front();
            que.pop();
            int peri=4;
            for (auto k:dir){
                int newRow=node.first+k.first;
                int newCol=node.second+k.second;
                if (newRow>=0 && newRow<numRows && newCol>=0 && newCol<numCols){
                    if (grid[newRow][newCol]==1 && visited.find({newRow,newCol})==visited.end()){
                        visited.insert({newRow,newCol});
                        que.push({newRow,newCol});
                        peri--;
                    }
                    else if (visited.find({newRow,newCol})!=visited.end()){
                        peri--;
                    }
                }
            }
            cout<<node.first<<"---"<<node.second<<"---"<<peri<<endl;
            cnt+=peri;
        }
        return cnt;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int numRows=grid.size();
        int numCols=grid[0].size();
        int cnt=0;
        set<pair<int,int>> visited;
        for (int i=0;i<numRows;i++){
            for (int j=0;j<numCols;j++){
                if (grid[i][j]==1 && visited.find({i,j})==visited.end()){
                    cnt+=bfs(i,j,numRows,numCols,visited,grid);
                }
            }
        }
        return cnt;
    }
};