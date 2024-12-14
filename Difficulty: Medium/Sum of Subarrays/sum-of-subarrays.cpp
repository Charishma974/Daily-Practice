//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long subarraySum(vector<int>& arr) {
        int MOD=pow(10,9)+7;
        int n=arr.size();
        long long total=0;
        for (int i=0;i<n;i++){
            long long contribution = (1LL * arr[i] * (i + 1) % MOD * (n - i) % MOD) % MOD;
            total = (total + contribution) % MOD;
        }
        return total%MOD;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        long long res = obj.subarraySum(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends