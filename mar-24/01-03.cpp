// https://leetcode.com/problems/maximum-odd-binary-number/submissions/1190275337/?envType=daily-question&envId=2024-03-01

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = count(s.begin(), s.end(), '1');
        string ans;
        for(int i = 0 ;i<s.size();i++){
            if(n!=1){
            ans.push_back('1');
            n--;
            }
            else{
            ans.push_back('0');
            }
        }
        ans.pop_back();
        ans.push_back('1');
        return ans;
    }
};