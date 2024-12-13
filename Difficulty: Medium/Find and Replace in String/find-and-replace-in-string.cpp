//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
        int i=0;
        for (int idx=0;idx<Q;idx++){
            if (idx!=0) i+=index[idx]-index[idx-1];
            else i+=index[idx];
            if (S.substr(i,sources[idx].size())==sources[idx]){
                S.replace(i,sources[idx].size(),targets[idx]);
                i+=targets[idx].size()-sources[idx].size();
            }
        }
        return S;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends