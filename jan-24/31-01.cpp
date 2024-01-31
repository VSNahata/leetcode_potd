// https://leetcode.com/problems/daily-temperatures/solutions/4651687/beats-98-99-users-c-java-python-javascript-2-approaches-explained/?envType=daily-question&envId=2024-01-31

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        stack<pair<int, int>> st;
        for(int i = temperatures.size()-1;i>=0;i--){
            while(!st.empty()){
                if(temperatures[i]>=st.top().first) st.pop();
                else {
                    ans.push_back(st.top().second - i);
                    break;
                }
            }
            if(st.empty()) ans.push_back(0);
            st.push({temperatures[i], i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};