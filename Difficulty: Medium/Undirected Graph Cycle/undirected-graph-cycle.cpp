//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool bfs(int src,vector<bool>& visited,vector<vector<int>>& adj){
        queue<pair<int,int>> que;
        que.push({-1,src});
        visited[src]=true;
        while (!que.empty()){
            pair<int,int> currNode=que.front();
            que.pop();
            for (auto k:adj[currNode.second]){
                if (!visited[k]){
                    que.push({currNode.second,k});
                    visited[k]=true;
                }
                else if (currNode.first!=k){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        int v=adj.size();
        vector<bool> visited(v,false);
        for (int i=0;i<v;i++){
            if (!visited[i]){
                if (bfs(i,visited,adj)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends