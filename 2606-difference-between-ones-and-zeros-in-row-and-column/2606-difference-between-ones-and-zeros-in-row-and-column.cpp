class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<int> onesRow(rows,0),onesCol(cols,0),zerosRow(rows,0),zerosCol(cols,0);
        for (int i=0;i<rows;i++){
            for (int j=0;j<cols;j++){
                if (grid[i][j]==0){
                    zerosRow[i]++;
                    zerosCol[j]++;
                }
                else{
                    onesRow[i]++;
                    onesCol[j]++;
                }
            }
        }
        vector<vector<int>> diff(rows,vector<int>(cols,0));
        for (int i=0;i<rows;i++){
            for (int j=0;j<cols;j++){
                diff[i][j]=onesRow[i]+onesCol[j]-zerosRow[i]-zerosCol[j];
            }
        }
        return diff;
    }
};