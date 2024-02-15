//https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/?envType=daily-question&envId=2024-02-15

class Solution {
public:
    long long largestPerimeter(vector<int>& a) { 
        int n = a.size();
        sort(a.begin(), a.end());
        long long s = 0;
        for (int i = 0; i < n; i++) {
            s += a[i];
        }
        for (int i = n - 1; i >= 2; i--) {
            s -= a[i];
            if (a[i] < s) {
                return s + a[i];
            }
        }
        return -1;
    }
};