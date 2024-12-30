class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for (auto row:prerequisites){
            int v=row[0];
            int u=row[1];
            indegree[v]++;
            adj[u].push_back(v);
        }
        queue<int> que;
        for (int i=0;i<numCourses;i++) if (indegree[i]==0) que.push(i);
        int cnt=0;
        while (!que.empty()){
            int node=que.front();
            que.pop();
            cnt++;
            for (auto k:adj[node]){
                indegree[k]--;
                if (indegree[k]==0) que.push(k);
            }
        }
        return cnt==numCourses;
    }
};