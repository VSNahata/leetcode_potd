// https://leetcode.com/problems/first-unique-character-in-a-string/?envType=daily-question&envId=2024-02-05
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> f(26, 0);
        for(auto i:s){
            f[i-'a']++;
        }
        for(int i = 0;i<s.size();i++){
            if(f[s[i]-'a'] == 1) return i;
        }
        return -1;
    }
};