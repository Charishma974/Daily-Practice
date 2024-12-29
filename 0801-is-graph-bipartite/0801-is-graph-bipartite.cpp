class Solution {
public:
    bool bfs(int src,vector<int>& visited,vector<vector<int>>& graph){
        queue<int> que;
        que.push(src);
        int currColor=1;
        visited[src]=currColor;
        while (!que.empty()){
            int currNode=que.front();
            que.pop();
            for (auto k:graph[currNode]){
                if (visited[k]==0){
                    que.push(k);
                    visited[k]=-visited[currNode];
                }
                else if (visited[k]==visited[currNode]) return true;
            }
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> visited(v,0);
        for (int i=0;i<v;i++){
            if (visited[i]==0){
                if (bfs(i,visited,graph)) return false;
            }
        }
        return true;
    }
};