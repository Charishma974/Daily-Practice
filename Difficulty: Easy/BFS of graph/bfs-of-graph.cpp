//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        int n=adj.size();
        vector<int> result;
        queue<int> que;
        vector<bool> visited(n,false);
        que.push(0);
        visited[0]=true;
        while (!que.empty()){
            int element=que.front();
            result.push_back(element);
            que.pop();
            
            for (int i=0;i<adj[element].size();i++){
                if (!visited[adj[element][i]]){
                    que.push(adj[element][i]);
                    visited[adj[element][i]]=true;
                }
            }
        }
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends