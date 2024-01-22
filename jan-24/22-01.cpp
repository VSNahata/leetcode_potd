// https://leetcode.com/problems/set-mismatch/submissions/1153302302/?envType=daily-question&envId=2024-01-22

class Solution {
public:
    void swapSort(vector<int> &nums){
        int i = 0;
        while(i<nums.size()){
            if(nums[i] - 1 == i){
                i++;
            }else{
                if(nums[i] == nums[nums[i] - 1]){
                    i++;
                }else{
                    swap(nums[i], nums[nums[i] - 1]);
                }
            }
        }
    }
    vector<int> findErrorNums(vector<int>& nums) {
        swapSort(nums);
        for(int i =0;i<nums.size();i++){
            if(i != nums[i] - 1){
                return {nums[i], i+1};
            }
        }
        return {};
    }
};