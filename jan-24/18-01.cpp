// https://leetcode.com/problems/climbing-stairs/submissions/1149949386/?envType=daily-question&envId=2024-01-18

class Solution {
public:
    int solve(int i, int n, vector<int> &dp){
        if(i == n) return 1;
        if(dp[i]!=-1) return dp[i];
        int one = 0;
        int two = 0;
        if(i + 1 <=n) one = solve(i + 1, n, dp);
        if(i + 2 <=n) two = solve(i + 2, n, dp);
        return dp[i] = one + two;

    }
    int climbStairs(int n) {
        vector<int> dp(n, -1);
       return solve(0,n ,dp);
    }
};