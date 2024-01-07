// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

// my incorrect attempt
class Solution {
public:
    void solve(int i, int diff, vector<int> op, vector<int> &nums, int &cnt){
        if(i == nums.size()){
            if(op.size()>=3) cnt++;
            return;
        }
        if(!op.size()){
            op.push_back(nums[i]);
            solve(i+1, diff, op, nums, cnt);
            op.pop_back();
            solve(i+1, diff, op, nums, cnt);
        }
        else if(diff == INT_MAX){
            op.push_back(nums[i]);
            solve(i+1, nums[i] - op[0],op, nums, cnt);// kyonki 2nd element hi hoga op mein anyways
            op.pop_back();
             solve(i+1, diff, op, nums, cnt);
        }
        else if(diff == (nums[i] - op[op.size()-1])){
            if(diff < (nums[i] - op[op.size()-1])) return;
            cout<< nums[i] - op[op.size()-1]<<endl;
            op.push_back(nums[i]);
            solve(i+1, diff, op, nums, cnt);
            op.pop_back();
            solve(i+1, diff, op, nums, cnt);
        }
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int cnt = 0;
        vector<int> op;
        solve(0, INT_MAX, op, nums, cnt );
        return cnt;
    }
};