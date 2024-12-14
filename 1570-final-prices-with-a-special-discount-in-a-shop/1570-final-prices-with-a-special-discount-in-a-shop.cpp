class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int n=prices.size();
        vector<int> result(n,-1);
        st.push(prices[n-1]);
        result[n-1]=prices[n-1];
        for (int i=n-2;i>=0;i--){
            while (!st.empty() && st.top()>prices[i]) st.pop();
            if (st.empty()){
                result[i]=prices[i];
            }
            else{
                result[i]=prices[i]-st.top();
            }
            st.push(prices[i]);
        }
        return result;
    }
};