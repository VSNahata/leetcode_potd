// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/submissions/1144970234/?envType=daily-question&envId=2024-01-13

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;
        for(int i = 0;i<s.size();i++){
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        int deficit = 0;
        for(auto it = smap.begin();it!=smap.end();it++){
            auto itr = tmap.find(it->first);
            if(itr == tmap.end())
            deficit += it->second;
            else if(it->second>itr->second){
              deficit += (it->second) - (itr->second);  
            } 
        }
            return deficit;
    }
};