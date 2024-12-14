//{ Driver Code Starts
#include <bits/stdc++.h>
#define N 10000
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector<int> print_next_greater_freq(int arr[],int n)
    {
        stack<int> st;
        unordered_map<int,int> pq;
        for (int i=0;i<n;i++){
            pq[arr[i]]++;
        }
        st.push(arr[n-1]);
        vector<int> result(n,-1);
        for (int i=n-2;i>=0;i--){
            int currEle=arr[i];
            while (!st.empty() && pq[currEle]>=pq[st.top()]) st.pop();
            if (!st.empty()) result[i]=st.top();
            st.push(currEle);
        }
        return result;
    }
};


//{ Driver Code Starts.

int main()
{
    int arr[N];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans=ob.print_next_greater_freq(arr,n);
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
	return 1;
}

// } Driver Code Ends