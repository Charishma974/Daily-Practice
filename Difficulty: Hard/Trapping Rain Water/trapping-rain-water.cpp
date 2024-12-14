//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

    // Function to find the trapped water between the blocks.
  public:
    int trappingWater(vector<int> &arr) {
        int n=arr.size();
        int lMax=0,rMax=0,total=0,l=0,r=n-1;
        while (l<r){
            if (arr[l]<=arr[r]){
                if (lMax>arr[l]) total+=lMax-arr[l];
                else lMax=arr[l];
                l=l+1;
            }
            else{
                if (rMax>arr[r]) total+=rMax-arr[r];
                else rMax=arr[r];
                r=r-1;
            }
        }
        return total;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.trappingWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends