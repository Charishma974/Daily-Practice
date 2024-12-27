class Solution {
public:
    double myPowUtil(double x,int n){
        if (n==0) return 1;
        double val=myPowUtil(x,n/2);
        val=val*val;
        if (n%2==0) return val;
        return val*x;
    }
    double myPow(double x, int n) {
        long long exp=n;
        double val= myPowUtil(x,abs(exp));
        if (n<0) return 1/val;
        return val;
    }
};