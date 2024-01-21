// https://leetcode.com/problems/house-robber/submissions/1152463448/?envType=daily-question&envId=2024-01-21

class Solution {
public:
    int solve(int i, vector<int>&nums, vector<int>&dp){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int pick = nums[i], notPick = 0;
        pick += solve(i+2, nums, dp);
        notPick = solve(i+1, nums, dp);
        return dp[i] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(0, nums, dp);
    }
};