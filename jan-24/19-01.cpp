//https://leetcode.com/problems/minimum-falling-path-sum/?envType=daily-question&envId=2024-01-19

class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
    //     if(i == matrix.size() - 1) return matrix[i][j];
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int ld = INT_MAX;
    //     int rd = INT_MAX;
    //     int b = INT_MAX;
    //     if(j-1>=0) ld = solve(i+1, j-1, matrix, dp);
    //     if(j+1<matrix[i].size()) rd = solve(i+1, j+1, matrix ,dp);
    //     b = solve(i + 1, j, matrix, dp);
    //     return dp[i][j] = matrix[i][j] + min({ ld, rd, b});

    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int mini = INT_MAX;
        // vector<vector<int>>dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        // for(int j = 0;j<matrix[0].size();j++){
        //     mini = min(mini, solve(0, j, matrix, dp ));
        // }
        // return mini;

        // vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size(), -1));
        vector<int> prev(matrix[0].size());
        for(int j = 0;j<matrix[0].size();j++){
            prev[j] = matrix[matrix.size()-1][j];
        }
        for(int i = matrix.size()-2;i>=0;i--){
            vector<int> curr(matrix[0].size(), 0);
            for(int j = 0;j<matrix[0].size();j++){
                int ld = INT_MAX;
                int rd = INT_MAX;
                int b = INT_MAX;
                if(j-1>=0) ld = matrix[i][j] + prev[j-1];
                if(j+1<matrix[0].size()) rd = matrix[i][j] + prev[j+1];
                b = matrix[i][j] + prev[j];
                curr[j] = min({ld, rd, b});
            }
            prev = curr;
        }
        int mini = INT_MAX;
        for(int j = 0;j<matrix[0].size();j++)
        mini = min(mini, prev[j]);
        return mini;
    }
};