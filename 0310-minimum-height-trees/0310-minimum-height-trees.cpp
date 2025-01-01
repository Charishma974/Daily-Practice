class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; // Special case for single node
        
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        
        // Build the adjacency list and degree count
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        // Initialize the queue with leaf nodes
        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                leaves.push(i);
            }
        }
        
        // Trim the leaves layer by layer
        int remainingNodes = n;
        while (remainingNodes > 2) {
            int leafCount = leaves.size();
            remainingNodes -= leafCount;
            
            for (int i = 0; i < leafCount; ++i) {
                int leaf = leaves.front();
                leaves.pop();
                
                for (int neighbor : adj[leaf]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }
        
        // Remaining nodes are the roots of Minimum Height Trees
        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        return result;
    }
};