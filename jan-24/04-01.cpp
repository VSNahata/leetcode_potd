// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/submissions/?envType=daily-question&envId=2024-01-04

// it has both dp and map solution
// my approach dp>

class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp){
        if(i == nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int takeTwo = 1e6, takeThree = 1e6;
        if(i<nums.size() - 1 && nums[i]==nums[i+1])
        takeTwo = 1+solve(i+2, nums, dp);
        if(i < nums.size() - 2 && nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2])
        takeThree = 1+solve(i+3, nums, dp);
        return dp[i] = min(takeTwo, takeThree);

    }
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size()+1, -1);
        int result = solve(0, nums, dp);
        if(result>=1e6) return -1;
        return result;
    }
};

//elegant map approach>>
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        
        unordered_map<int,int> f;
        
        for(auto i : nums)
            ++f[i];
        
        for(auto i : f){
            if(i.second % 3 == 0){
                ans += i.second / 3;
            }
            else if(i.second % 3 == 2){
                ++ans;
                ans += (i.second - 2) / 3;
            }
            else{
                if(i.second == 1)
                    return -1;
                
                ans += 2;
                ans += (i.second - 4) / 3;
            }
        }
        
        return ans;
    }
};