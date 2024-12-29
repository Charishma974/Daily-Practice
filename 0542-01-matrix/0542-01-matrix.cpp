class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int matRow=mat.size();
        int matCol=mat[0].size();
        queue<pair<int,int>> que;
        vector<vector<bool>> visited(matRow,vector<bool>(matCol,false));
        for (int row=0;row<matRow;row++){
            for (int col=0;col<matCol;col++){
                if (mat[row][col]==0){
                    que.push({row,col});
                    visited[row][col]=true;
                }
            }
        }
        vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        int time=1;
        while (!que.empty()){
            int queSize=que.size();
            for (int i=0;i<queSize;i++){
                int oldRow=que.front().first;
                int oldCol=que.front().second;
                que.pop();
                for (auto k:dir){
                    int newRow=k.first+oldRow;
                    int newCol=k.second+oldCol;
                    if (newRow>=0 && newRow<matRow && newCol>=0 && newCol<matCol && mat[newRow][newCol]==1 && !visited[newRow][newCol]){
                        que.push({newRow,newCol});
                        mat[newRow][newCol]=time;
                        visited[newRow][newCol]=true;
                    }
                }
            }
            time++;
        }
        return mat;
    }
};