// https://leetcode.com/problems/power-of-two/submissions/1179701286/?envType=daily-question&envId=2024-02-19

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n>0 && __builtin_popcount(n) == 1 ) return true;
        return false;
    }
};