// https://leetcode.com/problems/majority-element/?envType=daily-question&envId=2024-02-12

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto num:nums){
            m[num]++;
        }
        for(auto it = m.begin();it!=m.end();it++)
        {
            if(it->second>(nums.size()/2))
            return it->first;
        }
        return -1;
    }
};