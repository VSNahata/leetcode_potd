//https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/?envType=daily-question&envId=2024-02-16

class Solution {
    struct CompareNodes {
        bool operator() (const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.second < rhs.second;
        }
    };
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> arr_freq_map;

        for (int num: arr) {
            ++arr_freq_map[num];
        }

        vector<pair<int, int>> buffer (
            arr_freq_map.begin(),
            arr_freq_map.end()
        );

        sort(buffer.begin(), buffer.end(), CompareNodes());

        int i = 0;
        for (; i < buffer.size() && k > 0; ++i) {
            if (buffer.at(i).second <= k) {
                k -= min(k, buffer[i].second);
            } else {
                break;
            }
        }

        return buffer.size() - i;
    }
};