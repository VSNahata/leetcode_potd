// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/?envType=daily-question&envId=2024-03-05

class Solution {
public:
    int minimumLength(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i] == s[j]){
                while(i<j && s[i] == s[i+1]) i++;
                i++;
                while(i<j && s[j] == s[j-1]) j--;
                j--;
            }
            else break;
        }
        if(j<i) return 0;
        return j-i+1;
    }
};