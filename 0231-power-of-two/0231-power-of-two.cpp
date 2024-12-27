class Solution {
public:
    void isPowerUtil(int n,int& cnt){
        if (n==0) return;
        cnt+=(n & 1);
        isPowerUtil((n>>1),cnt);
    }
    bool isPowerOfTwo(int n) {
        if (n<=0) return false;
        int cnt=0;
        isPowerUtil(n,cnt);
        return cnt==1;
    }
};