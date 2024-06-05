class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = nums[0];
        for(int num:nums){
            ans^=num;
        }
        return ans^nums[0];
    }
};