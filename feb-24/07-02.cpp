//https://leetcode.com/problems/sort-characters-by-frequency/submissions/1168597386/?envType=daily-question&envId=2024-02-07

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> f;
        for(auto i : s)
            ++f[i];

        priority_queue<pair<int,char>> pq;

        for(auto i : f){
            pq.push({i.second, i.first});
        }
        string ans = "";
        while(!pq.empty()){
            cout<<pq.top().first<<" ";
            int cnt = pq.top().first;
            while(cnt--)
            ans+=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};