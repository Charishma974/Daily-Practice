class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int gridRow=grid.size();
        int gridCol=grid[0].size();
        queue<pair<int,int>> que;
        for (int row=0;row<gridRow;row++){
            for (int col=0;col<gridCol;col++){
                if (grid[row][col]==2){
                    que.push({row,col});
                }
            }
        }
        vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        int timeTaken=0;
        while (!que.empty()){
            bool changed=false;
            int queSize=que.size();
            for (int i=0;i<queSize;i++){
                pair<int,int> node=que.front();
                que.pop();
                for (auto k:dir){
                    int newRow=k.first+node.first;
                    int newCol=k.second+node.second;
                    if (newRow>=0 && newRow<gridRow && newCol>=0 && newCol<gridCol && grid[newRow][newCol]==1){
                        que.push({newRow,newCol});
                        grid[newRow][newCol]=2;
                        changed=true;
                    }
                }
            }
            if (changed) timeTaken++;
        }
        for (auto row:grid){
            for (auto col:row){
                if (col==1) return -1;
            }
        }
        return timeTaken;
    }
};