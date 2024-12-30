//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string findOrder(vector<string> dict, int k) {
        int dictSize=dict.size();
        vector<int> indegree(k,0);
        vector<vector<int>> adj(k);
        for (int i=1;i<dictSize;i++){
            for (int j=0;j<min(dict[i].size(),dict[i-1].size());j++){
                if (dict[i][j]!=dict[i-1][j]){
                    int u=dict[i-1][j]-'a';
                    int v=dict[i][j]-'a';
                    adj[u].push_back(v);
                    indegree[v]++;
                    break;
                }
            }
        }
        queue<int> que;
        string str;
        for (int i=0;i<k;i++) if (indegree[i]==0) que.push(i);
        while (!que.empty()){
            int node=que.front();
            que.pop();
            str+=node+'a';
            for (auto k:adj[node]){
                indegree[k]--;
                if (indegree[k]==0){
                    que.push(k);
                }
            }
        }
        return str;
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            a.push_back(number);
        }
        int K;
        cin >> K;
        getchar();
        Solution obj;
        string ans = obj.findOrder(a, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[a.size()];
        std::copy(a.begin(), a.end(), temp);
        sort(temp, temp + a.size(), f);

        bool f = true;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != temp[i])
                f = false;

        if (f)
            cout << "true";
        else
            cout << "false";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends