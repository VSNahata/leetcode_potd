// https://leetcode.com/problems/cherry-pickup-ii/submissions/1172058757/?envType=daily-question&envId=2024-02-11

class Solution {
public:
    int dp[70][70][70];
    int solve(int r, int c1, int c2, vector<vector<int>> &grid){
        if(r == grid.size() || c1 == c2 ||min(c1 , c2)<0 ||max(c1, c2) == grid[0].size()) return 0;
        if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];
        int delc1[] = {-1,0,1};
        int delc2[] = {-1,0,1};
        int res = 0;
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                int c11 = c1 + delc1[i];
                int c22 = c2 + delc2[j];
                res = max(res, solve(r+1, c11, c22, grid));
            }
        }
        return dp[r][c1][c2] = res + grid[r][c1] + grid[r][c2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0 ,grid[0].size()-1, grid);
    }
};