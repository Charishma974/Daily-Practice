//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfsTraversal(int src,vector<bool>& visited,vector<vector<int>>& adj,vector<int>& dfs){
        visited[src]=true;
        dfs.push_back(src);
        for (auto k:adj[src]){
            if (!visited[k]) dfsTraversal(k,visited,adj,dfs);
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int v=adj.size();
        vector<int> dfs;
        vector<bool> visited(v,false);
        dfsTraversal(0,visited,adj,dfs);
        return dfs;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends