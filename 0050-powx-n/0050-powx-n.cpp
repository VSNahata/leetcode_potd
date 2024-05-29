class Solution {
public:
    double solve(double x, long n){
        if(n == 1) return x;
        if(n%2) return x*solve(x, n-1);
        else return solve(x*x, n/2);
    }
    double myPow(double x, int neg) {
        if(neg == 0) return 1;
        if(x == 0) return 0;
        if(x == 1) return 1;
        
        if(neg<0) {
            return 1/solve(x, (long)neg*-1);
        }
        return solve(x,neg);
    }
};