// https://leetcode.com/problems/rearrange-array-elements-by-sign/?envType=daily-question&envId=2024-02-14

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positives;
        vector<int> negetives;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>0)
            positives.push_back(nums[i]);
            else
            negetives.push_back(nums[i]);
        }
        for(int i = 0;i<positives.size();i++){
            nums[2*i] = positives[i];
            nums[2*i+1] = negetives[i];
        }
        return nums;
    }
};