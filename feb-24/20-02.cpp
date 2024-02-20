// https://leetcode.com/problems/missing-number/submissions/1180778543/?envType=daily-question&envId=2024-02-20

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i;
        for( i = 0;i<nums.size();i++){
            if(nums[i]!=i) return i;
        }
        return i;
    }
};