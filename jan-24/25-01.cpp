// https://leetcode.com/problems/longest-common-subsequence/?envType=daily-question&envId=2024-01-25

class Solution {
public:
    // int solve(int i, int j, string text1, string text2, vector<vector<int>>&dp){
    //     if(i==text1.size() || j==text2.size()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(text1[i] == text2[j]) return dp[i][j] = 1+solve(i+1,j+1, text1, text2, dp);
    //     else return dp[i][j] = max(solve(i+1,j, text1, text2, dp), solve(i,j+1, text1, text2, dp));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        // return solve(0,0,text1, text2, dp);
        int n= text1.size();
        int m= text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 0;i<=n;i++) dp[i][m] =0;
        for(int j = 0;j<=m;j++) dp[n][j] =0;

        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(text1[i] == text2[j]) dp[i][j] = 1 + dp[i+1][j+1];
                else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];

    }
};