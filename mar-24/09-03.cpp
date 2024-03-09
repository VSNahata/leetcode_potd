//https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2024-03-09

class Solution {
public:

    bool isPresent(vector<int>& nums, int target){
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid] == target){
                return true;
            }
            else if(nums[mid]>target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return false;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] == nums2[j]){
                return nums1[i];
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return -1;
    }
};