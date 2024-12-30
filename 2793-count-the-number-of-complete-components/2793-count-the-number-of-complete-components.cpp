class Solution {
public:
    bool bfs(int src,vector<bool>& visited,vector<vector<int>>& adj,int n){
        queue<int> que;
        que.push(src);
        visited[src]=true;
        int overallNodes=0;
        int overallEdges=0;
        while (!que.empty()){
            int node=que.front();
            que.pop();
            overallNodes++;
            for (auto k:adj[node]){
                overallEdges++;
                if (!visited[k]){
                    que.push(k);
                    visited[k]=true;
                }
            }
        }
        return overallNodes*(overallNodes-1)/2 == overallEdges/2;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto k:edges){
            int u=k[0];
            int v=k[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        int cnt=0;
        for (int i=0;i<n;i++){
            if (!visited[i]){
                cnt+=bfs(i,visited,adj,n);
            }
        }
        return cnt;
    }
};