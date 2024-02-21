// https://leetcode.com/problems/bitwise-and-of-numbers-range/?envType=daily-question&envId=2024-02-21

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int i = 0;
        while(left!=right){
            left = left>>1;
            right = right>>1;
            i++;
        }
        return left<<i;
    }
};