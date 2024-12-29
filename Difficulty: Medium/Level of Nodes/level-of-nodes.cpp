//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int v, vector<int> adj[], int x) 
	{
	    int level=0;
	    queue<int> que;
	    vector<bool> visited(v,false);
	    que.push(0);
	    visited[0]=true;
	    while (!que.empty()){
	        int queSize=que.size();
	        for (int i=0;i<queSize;i++){
	            int node=que.front();
	            que.pop();
	            if (node==x) return level;
	            for (auto k:adj[node]){
	                if (!visited[k]){
	                    que.push(k);
	                    visited[k]=true;
	                }
	            }
	        }
	        level++;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends