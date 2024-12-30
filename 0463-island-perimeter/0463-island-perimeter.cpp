class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int numRows=grid.size();
        int numCols=grid[0].size();
        int cnt=0;
        vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        for (int i=0;i<numRows;i++){
            for (int j=0;j<numCols;j++){
                if (grid[i][j]==1){
                    int peri=4;
                    for (auto k:dir){
                        int newRow=i+k.first;
                        int newCol=j+k.second;
                        if (newRow>=0 && newRow<numRows && newCol>=0 && newCol<numCols){
                            if (grid[newRow][newCol]==1) peri--;
                        }
                    }
                    cnt+=peri;
                }
            }
        }
        return cnt;
    }
};