// https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=daily-question&envId=2024-03-02

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        multiset<int> s;
        for(auto e: nums){
            s.insert(e*e);
        }
        vector<int> ans;
        for(auto it = s.begin();it!=s.end();it++){
            ans.push_back(*it);
        }
        return ans;
    }
};