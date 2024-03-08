//https://leetcode.com/problems/count-elements-with-maximum-frequency/?envType=daily-question&envId=2024-03-08

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> v(101, 0);
        for(int i = 0;i<nums.size();i++){
            v[nums[i]]++;
        }
        int maxi = v[0];
        int cnt = 0;
        for(int i = 1;i<v.size();i++){
            if(v[i] == maxi) cnt+=v[i];
            else if(v[i]<maxi) continue;
            else{
                maxi = v[i];
                cnt = v[i];
            }
        }
        return cnt;

    }
};