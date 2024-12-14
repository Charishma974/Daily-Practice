//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        stack<string> st;
        int n=pre_exp.size();
        for (int i=n-1;i>=0;i--){
            char ch=pre_exp[i];
            if (isalnum(ch)) st.push(string(1,ch));
            else{
                string ch1,ch2;
                if (!st.empty() && st.size()>=2){
                    ch1=st.top();
                    st.pop();
                    ch2=st.top();
                    st.pop();
                }
                st.push('('+ch1+ch+ch2+')');
            }
        }
        string str=st.top();
        reverse(str.begin(),str.end());
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
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends