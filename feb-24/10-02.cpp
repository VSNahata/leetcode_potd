//https://leetcode.com/problems/palindromic-substrings/?envType=daily-question&envId=2024-02-10

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        vector<vector<int>> isPalindrome(n, vector<int> (n, 0));
        int ans = 0;

        for(int i = n - 1; i > -1; i--){
            for(int j = i; j < n; j++){
                if(i == j){
                    isPalindrome[i][j] = 1;
                    ++ans;
                }
                else{
                    if(s[i] == s[j] and (i == j - 1 or isPalindrome[i + 1][j - 1])){
                        isPalindrome[i][j] = 1;
                        ++ans;
                    }
                }
            }
        }

        return ans;
    }
};