// https://leetcode.com/problems/find-the-pivot-integer/description/?envType=daily-question&envId=2024-03-13

class Solution {
public:
    int pivotInteger(int n) {
        float x = sqrt((n*(n+1))/2);
        if(x == floor(x)) return x;
        return -1;
    }
};