// https://leetcode.com/problems/custom-sort-string/description/?envType=daily-question&envId=2024-03-11

class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> st;
        for(int i = 0;i<s.size();i++){
            st[s[i]]++;
        }
        string ans;
        for(int i = 0;i<order.size();i++){
            auto it = st.find(order[i]);
            if(it!= st.end()) {
                while(it->second != 0) {
                ans+=it->first;
                it->second--;
            }
            st.erase(it);
            }
        }
        for(auto it = st.begin();it!=st.end();it++){
            while(it->second != 0) {
                ans+=it->first;
                it->second--;
            }
            st.erase(it);
        }
        return ans;
    }
};