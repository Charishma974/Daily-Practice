//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        stack<string> st;
        for (auto ch:exp){
            if (isalnum(ch)){
                st.push(string(1,ch));
            }
            else{
                string ch1,ch2;
                if (!st.empty() && st.size()>=2){
                    ch1=st.top();
                    st.pop();
                    ch2=st.top();
                    st.pop();
                }
                st.push('('+ch2+ch+ch1+')');
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    fclose(stdout);

    return 0;
}

// } Driver Code Ends