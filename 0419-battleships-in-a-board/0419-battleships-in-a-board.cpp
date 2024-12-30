class Solution {
public:
    int bfs(int row,int col,int numRows,int numCols,vector<vector<bool>>& visited,vector<vector<char>>& grid){
        queue<pair<int,int>> que;
        que.push({row,col});
        // row check
        bool rowCheck=false;
        while (!que.empty()){
            pair<int,int> node=que.front();
            que.pop();
            int newRow=node.first+1;
            if (newRow>=0 && newRow<numRows && grid[newRow][node.second]=='X' && !visited[newRow][node.second]){
                que.push({newRow,node.second});
                visited[newRow][node.second]=true;
                rowCheck=true;
            }
        }
        if (rowCheck) return 1;
        que.push({row,col});
        bool colCheck=false;
        while (!que.empty()){
            pair<int,int> node=que.front();
            que.pop();
            int newCol=node.second+1;
            if (newCol>=0 && newCol<numCols && grid[node.first][newCol]=='X' && !visited[node.first][newCol]){
                que.push({node.first,newCol});
                visited[node.first][newCol]=true;
                colCheck=true;
            }
        }
        return 1;
    }
    int countBattleships(vector<vector<char>>& board) {
        int numRows=board.size();
        int numCols=board[0].size();
        vector<vector<bool>> visited(numRows,vector<bool>(numCols,false));
        int cnt=0;
        for (int row=0;row<numRows;row++){
            for (int col=0;col<numCols;col++){
                if (board[row][col]=='X' && !visited[row][col]){
                    cnt+=bfs(row,col,numRows,numCols,visited,board);
                }
            }
        }
        return cnt;
    }
};