//https://leetcode.com/problems/intersection-of-two-arrays/description/?envType=daily-question&envId=2024-03-10

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;
        set<int> s2;
        vector<int> ans;
        for(int i = 0;i<nums1.size();i++){
            s1.insert(nums1[i]);
        }
        for(int  i= 0;i<nums2.size();i++){
            s2.insert(nums2[i]);
        }
        for(auto it = s1.begin();it!=s1.end();it++){
            if(s2.find(*it)!=s2.end()) ans.push_back(*it);
        }
        return ans; 
    }
};