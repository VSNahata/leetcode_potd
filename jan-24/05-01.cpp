// https://leetcode.com/problems/longest-increasing-subsequence/solutions/4509129/99-54-easy-solution-with-explanation/?envType=daily-question&envId=2024-01-05

// dp approach , dp on subsequences

class Solution {
public:
    int solve(int i, int prev, vector<int>& nums, vector<vector<int>> &dp){
        if(i == nums.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int take = 0, notTake = 0;
        notTake = solve(i+1, prev, nums, dp);
        if(prev == -1 || nums[i] > nums[prev]){
            take = 1 + solve(i+1, i, nums, dp);
        }
        return dp[i][prev+1] = max(notTake, take);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        return solve(0, -1, nums, dp);
    }
};

// another approach

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int n = nums.size();
        std::vector<int> dp(n, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};