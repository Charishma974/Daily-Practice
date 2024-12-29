//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int result=arr[n-1]-arr[0];
        for (int i=1;i<n;i++){
            int mini=min(arr[i]-k,arr[0]+k);
            int maxi=max(arr[i-1]+k,arr[n-1]-k);
            result=min(result,maxi-mini);
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.getMinDiff(arr, k) << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends