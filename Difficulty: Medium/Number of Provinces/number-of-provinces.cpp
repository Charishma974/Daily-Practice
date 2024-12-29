//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void bfs(int src,vector<bool>& visited,vector<vector<int>>& adjNew){
        queue<int> que;
        que.push(src);
        visited[src]=true;
        while (!que.empty()){
            int node=que.front();
            que.pop();
            for (auto k:adjNew[node]){
                if (!visited[k]){
                    que.push(k);
                    visited[k]=true;
                }
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<vector<int>> adjNew(V);
        for (int row=0;row<adj.size();row++){
            for (int col=0;col<adj[row].size();col++){
                if (row!=col && adj[row][col]==1){
                    adjNew[row].push_back(col);
                    adjNew[col].push_back(row);
                }
            }
        }
        int cnt=0;
        vector<bool> visited(V,false);
        for (int i=0;i<V;i++){
            if (!visited[i]){
                cnt++;
                bfs(i,visited,adjNew);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends