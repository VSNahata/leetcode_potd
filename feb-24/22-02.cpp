//https://leetcode.com/problems/find-the-town-judge/submissions/1183219987/?envType=daily-question&envId=2024-02-22

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> a(n+1,0), b(n+1,0);
        for(int i=0;i<trust.size();i++)
        {
            b[trust[i][0]]++;
            a[trust[i][1]]++;
        }

        for(int i=1;i<=n;i++){
            if(a[i]==n-1 && b[i]==0)
                return i;
        }
        return -1;
    }
};