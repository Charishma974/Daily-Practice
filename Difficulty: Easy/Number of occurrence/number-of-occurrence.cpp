//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findLower(vector<int>& arr,int target){
        int n=arr.size();
        int low=0,high=n-1;
        while (low<=high){
            int mid=low+(high-low)/2;
            if (arr[mid]>=target) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
    int findUpper(vector<int>& arr,int target){
        int n=arr.size();
        int low=0,high=n-1;
        while (low<=high){
            int mid=low+(high-low)/2;
            if (arr[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
    int countFreq(vector<int>& arr, int target) {
        int n=arr.size();
        int lowerIndex=findLower(arr,target);
        if (lowerIndex==n || arr[lowerIndex]!=target) return 0;
        int upperIndex=findUpper(arr,target);
        return upperIndex-lowerIndex;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends