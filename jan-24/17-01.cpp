// https://leetcode.com/problems/unique-number-of-occurrences/submissions/1148604004/?envType=daily-question&envId=2024-01-17
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> freq(2001, 0);
        for(int num: arr){
            freq[1001 + num]++;
        }
        unordered_set<int> s;
        for(int i = 0;i<freq.size();i++){
            if(freq[i]!=0 && s.find(freq[i])!=s.end()) return false;
            else{
                s.insert(freq[i]);
            }
        }
        return true;
    }
};