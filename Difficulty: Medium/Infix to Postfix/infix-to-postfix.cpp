//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int precedence(char ch){
        if (ch=='^') return 3;
        else if (ch=='*' || ch=='/') return 2;
        else if (ch=='+' || ch=='-') return 1;
        else return -1;
    }
    string infixToPostfix(string& s) {
        string result;
        stack<char> st;
        for (auto ch:s){
            if (isdigit(ch) || isalpha(ch)) result+=ch;
            else if (ch=='('){
                st.push(ch);
            }
            else if (ch==')'){
                while (!st.empty() && st.top()!='('){
                    result+=st.top();
                    st.pop();
                }
                if (!st.empty() && st.top()=='(') st.pop();
            }
            else{
                while (!st.empty() && precedence(st.top())>=precedence(ch)){
                    result+=st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};


//{ Driver Code Starts.
//  Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends