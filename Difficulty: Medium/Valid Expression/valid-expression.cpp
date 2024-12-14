//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool valid(string &s) {
        stack<char> st;
        for (auto ch:s){
            if (ch=='(' || ch=='{' || ch=='[') st.push(ch);
            else if (!st.empty() && ((ch==')' && st.top()=='(') || (ch==']' && st.top()=='[') || (ch=='}' && st.top()=='{'))) st.pop();
            else return false;
        }
        if (!st.empty()) return false;
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string str;
        getline(cin, str);
        Solution obj;
        if (obj.valid(str)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends