//https://leetcode.com/problems/minimum-window-substring/submissions/1165861545/?envType=daily-question&envId=2024-02-04
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        
        unordered_map<char, int> m;
        for (char c : t) {
            m[c]++;
        }

        int cnt = m.size();
        int i = 0, j = 0;
        int minLen = INT_MAX;
        int minStart = 0;

        while (j < s.size()) {
            if (m.find(s[j]) != m.end()) {
                m[s[j]]--;
                if (m[s[j]] == 0) {
                    cnt--;
                }
            }
            j++;

            while (cnt == 0) {
                if (j - i < minLen) {
                    minLen = j - i;
                    minStart = i;
                }

                if (m.find(s[i]) != m.end()) {
                    m[s[i]]++;
                    if (m[s[i]] > 0) {
                        cnt++;
                    }
                }
                i++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
    }
};
