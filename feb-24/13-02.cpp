// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/submissions/1173970319/?envType=daily-question&envId=2024-02-13

class Solution {
public:
    bool isPalindrome(string word){
        int i =0;
        int j = word.size()-1;
        while(i<=j){
            if(word[i]!=word[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(string word: words){
            if(isPalindrome(word)){
                return word;
            }
        }
        return "";
    }
};