class Solution {
public:
    void dfs(int src,vector<bool>& visited,vector<vector<int>>& rooms){
        visited[src]=true;
        for (auto k:rooms[src]){
            if (!visited[k]){
                dfs(k,visited,rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visited(n,false);
        dfs(0,visited,rooms);
        for (auto k:visited){
            if (k==false) return false;
        }
        return true;
    }
};