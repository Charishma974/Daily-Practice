class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int numRows=board.size();
        int numCols=board[0].size();
        int cnt=0;
        for (int i=0;i<numRows;i++){
            for (int j=0;j<numCols;j++){
                if (board[i][j]=='X'){
                    if (i-1<0 || (i-1>=0 && board[i-1][j]!='X')){
                        if (j-1<0 || (j-1>=0 && board[i][j-1]!='X')) cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};