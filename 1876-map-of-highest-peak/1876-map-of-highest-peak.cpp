class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int numRows=isWater.size();
        int numCols=isWater[0].size();
        queue<pair<int,int>> que;
        vector<vector<bool>> visited(numRows,vector<bool>(numCols,false));
        for (int i=0;i<numRows;i++){
            for (int j=0;j<numCols;j++){
                if (isWater[i][j]==1){
                    isWater[i][j]=0;
                    visited[i][j]=true;
                    que.push({i,j});
                }
            }
        }
        vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        int level=1;
        while (!que.empty()){
            int size=que.size();
            for (int i=0;i<size;i++){
                pair<int,int> currNode=que.front();
                que.pop();
                for (auto k:dir){
                    int newX=currNode.first+k.first;
                    int newY=currNode.second+k.second;
                    if (newX>=0 && newX<numRows && newY>=0 && newY<numCols && !visited[newX][newY]){
                        que.push({newX,newY});
                        isWater[newX][newY]=level;
                        visited[newX][newY]=true;
                    }
                }
            }
            level++;
        }
        return isWater;
    }
};