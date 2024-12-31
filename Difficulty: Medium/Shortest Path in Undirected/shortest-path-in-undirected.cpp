//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int v=adj.size();
        vector<int> result(v,INT_MAX);
        result[src]=0;
        queue<int> que;
        que.push(src);
        while (!que.empty()){
            int node=que.front();
            que.pop();
            for (auto k:adj[node]){
                int calDist=result[node]+1;
                if (calDist<result[k]){
                    result[k]=calDist;
                    que.push(k);
                }
            }
        }
        for (int i=0;i<v;i++) if (result[i]==INT_MAX) result[i]=-1;
        return result;
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
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends