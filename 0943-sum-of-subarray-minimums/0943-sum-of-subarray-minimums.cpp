class Solution {
public:
    vector<int> leftSmaller(int n, vector<int> a){
        stack<int> st;
        vector<int> result(n,-1);
        for (int i=0;i<n;i++){
            int currEle=a[i];
            while (!st.empty() && currEle<a[st.top()]) st.pop();
            if (!st.empty()) result[i]=st.top();
            st.push(i);
        }
        return result;
    }
    vector<int> rightSmaller(int n, vector<int> a){
        stack<int> st;
        vector<int> result(n,-1);
        for (int i=n-1;i>=0;i--){
            int currEle=a[i];
            while (!st.empty() && currEle<=a[st.top()]) st.pop();
            if (!st.empty()) result[i]=st.top();
            st.push(i);
        }
        return result;
    }
    int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> leftSmallerIndices = leftSmaller(n, arr); // Nearest smaller on the left
    vector<int> rightSmallerIndices = rightSmaller(n, arr); // Nearest smaller on the right
    
    const int MOD = 1e9 + 7; // To handle large numbers
    long long total = 0;

    for (int i = 0; i < n; i++) {
        // Compute the number of subarrays where `arr[i]` is the minimum
        int leftCount = (leftSmallerIndices[i] == -1) ? (i + 1) : (i - leftSmallerIndices[i]);
        int rightCount = (rightSmallerIndices[i] == -1) ? (n - i) : (rightSmallerIndices[i] - i);

        // Contribution of arr[i] to the total sum
        total = (total + (long long)arr[i] * leftCount * rightCount) % MOD;
    }

    return total;
}

};