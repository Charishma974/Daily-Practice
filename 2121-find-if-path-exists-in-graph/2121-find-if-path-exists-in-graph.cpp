class Solution {
public:
    bool dfs(int src,vector<bool>& visited,vector<vector<int>>& adj,int dest){
        visited[src]=true;
        if (dest==src) return true;
        for (auto k:adj[src]){
            if (!visited[k]){
                if (dfs(k,visited,adj,dest)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (auto k:edges){
            int u=k[0];
            int v=k[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        return dfs(source,visited,adj,destination);
    }
};