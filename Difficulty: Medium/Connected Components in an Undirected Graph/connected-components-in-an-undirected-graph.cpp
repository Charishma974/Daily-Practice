//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    void dfs(int src,vector<bool>& visited,vector<vector<int>>& adj,vector<int>& temp){
        visited[src]=true;
        temp.push_back(src);
        for (auto k:adj[src]){
            if (!visited[k]){
                dfs(k,visited,adj,temp);
            }
        }
    }
    vector<vector<int>> connectedcomponents(int v, vector<vector<int>>& edges) {
        vector<vector<int>> adj(v);
        for (auto k:edges){
            int u=k[0];
            int ve=k[1];
            adj[u].push_back(ve);
            adj[ve].push_back(u);
        }
        vector<vector<int>> result;
        vector<bool> visited(v,false);
        for (int i=0;i<v;i++){
            if (!visited[i]){
                vector<int> temp;
                dfs(i,visited,adj,temp);
                sort(temp.begin(),temp.end());
                result.push_back(temp);
            }
        }
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        vector<vector<int>> res = obj.connectedcomponents(v, edges);
        sort(res.begin(), res.end());
        for (const auto &component : res) {
            for (int node : component) {
                cout << node << " ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends