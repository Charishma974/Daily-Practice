//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool dfs(int src,vector<bool>& visited,vector<bool>& pathVisited,vector<vector<int>>& adj){
        visited[src]=true;
        pathVisited[src]=true;
        for (auto k:adj[src]){
            if (!visited[k]){
                if (dfs(k,visited,pathVisited,adj)) return true;
            }
            else if (pathVisited[k]) return true;
        }
        pathVisited[src]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<bool> visited(V,false);
        vector<bool> pathVisited(V,false);
        for (int i=0;i<V;i++){
            if (!visited[i]){
                if (dfs(i,visited,pathVisited,adj)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends