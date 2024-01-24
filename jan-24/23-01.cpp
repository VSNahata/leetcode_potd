// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/submissions/1154400321/?envType=daily-question&envId=2024-01-23

// my solution
class Solution {
public:
    int solve(int i, vector<string> &arr, unordered_map<char, int> m){
        if(i == arr.size()) return 0;
        int flag = 0;
        int notTake = solve(i+1, arr, m);

            unordered_map<char, int> m2;
        for(char ch:arr[i]){
            if(m2.find(ch) != m2.end()){
                flag = 1;
                break;
            }
            m2[ch]++;
        }
        if(flag) return notTake;
        for(char ch:arr[i]){
            if(m.find(ch)!= m.end()){
            flag = 1;
            break;
            }
        }
        if(flag) return notTake;
        else{
        for(char ch:arr[i]){
            m[ch]++;
        }
        return max(notTake, static_cast<int>(arr[i].size() + solve(i+1, arr, m))) ;
        }
    }
    int maxLength(vector<string>& arr) {
    unordered_map<char, int> m;
        return solve(0, arr, m);
    }
};

//good solution
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0;
        int n = arr.size();

        for(int i = 0; i < (1 << n); i++){
            int cur_ans = 0;
            vector<int> f(26, 0);

            for(int j = 0; j < n; j++){
                if((i >> j) & 1){
                    cur_ans += arr[j].size();

                    for(auto x : arr[j])
                        ++f[x - 'a'];
                }
            }

            bool ok = 1;
            for(auto x : f){
                if(x > 1){
                    ok = 0;
                    break;
                }
            }

            if(ok)
                ans = max(ans, cur_ans);
        }

        return ans;
    }
};