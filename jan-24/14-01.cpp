// https://leetcode.com/problems/determine-if-two-strings-are-close/submissions/1145694746/?envType=daily-question&envId=2024-01-14

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        for(int i = 0;i<word1.size();i++){
            v1[word1[i]-'a']++;
            v2[word2[i]-'a']++;

        }
        for(int i = 0;i<=25;i++){
            if(v1[i] == 0&&v2[i]!=0 || v1[i]!=0 && v2[i]==0) return false;

        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for(int i = 0;i<26;i++){
            if(v1[i]!=v2[i]) return false;
        }
        return true;
    }
};
// usi ko likhne ka dusra approach
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> need(26, 0), have(26, 0);
        
        for(auto i : word1)
            ++need[i - 'a'];
        for(auto i : word2)
            ++have[i - 'a'];
        
        for(int i = 0; i < 26; i++){
            if(need[i] == have[i])
                continue;
            
            for(int j = i + 1; j < 26; j++){
                if(need[i] == have[j] and have[i] and have[j]){
                    swap(have[i], have[j]);
                    break;
                }
            }
        }
        
        return need == have;
    }
};