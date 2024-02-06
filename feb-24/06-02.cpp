//https://leetcode.com/problems/group-anagrams/?envType=daily-question&envId=2024-02-06

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> m;
        vector<vector<string>> ans;
        for(auto str:strs){
            vector<int> f(26, 0);
            for(int i = 0;i<str.size();i++){
                f[str[i]-'a']++;
            }
            m[f].push_back(str);
        }
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }
};