class Solution {
public:
    void bfs(int src,vector<bool>& visited,vector<vector<int>>& adj){
        queue<int> que;
        que.push(src);
        visited[src]=true;
        while (!que.empty()){
            int node=que.front();
            que.pop();
            for (auto k:adj[node]){
                if (!visited[k]){
                    visited[k]=true;
                    que.push(k);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<vector<int>> adj(v);
        for (int i=0;i<v;i++){
            for (int j=0;j<v;j++){
                if (isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        vector<bool> visited(v,false);
        for (int i=0;i<v;i++){
            if (!visited[i]){
                cnt++;
                bfs(i,visited,adj);
            }
        }
        return cnt;
    }
};