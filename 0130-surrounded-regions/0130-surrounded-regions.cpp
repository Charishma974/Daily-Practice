class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();
        queue<pair<int,int>> que;
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                if (i==0 || i==row-1 || j==0 || j==col-1){
                    if (board[i][j]=='O'){
                        que.push({i,j});
                        visited[i][j]=true;
                    }
                }
            }
        }
        vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        while (!que.empty()){
            pair<int,int> currNode=que.front();
            que.pop();
            for (auto k:dir){
                int newRow=k.first+currNode.first;
                int newCol=k.second+currNode.second;
                if (newRow>=0 && newRow<row && newCol>=0 && newCol<col && board[newRow][newCol]=='O' && !visited[newRow][newCol]){
                    visited[newRow][newCol]=true;
                    que.push({newRow,newCol});
                }
            }
        }
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                if (board[i][j]=='O' && visited[i][j]==false) board[i][j]='X';
            }
        }
    }
};