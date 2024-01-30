// https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/1160824185/?envType=daily-question&envId=2024-01-30

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int i = 0;
        for(i;i<tokens.size();i++){
            if(tokens[i] == "+" && st.size()>1){
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                st.push(op1+op2);
            }
            else if(tokens[i] == "-" && st.size()>1){
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                st.push(op1-op2);
            }
            else if(tokens[i] == "*" && st.size()>1){
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                st.push(op1*op2);
            }
            else if(tokens[i] == "/" && st.size()>1){
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                st.push(op1/op2);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        if(i<tokens.size()) return INT_MIN;
        return st.top();

    }
};