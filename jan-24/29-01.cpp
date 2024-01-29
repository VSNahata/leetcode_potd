// https://leetcode.com/problems/implement-queue-using-stacks/solutions/4641109/beats-100-users-c-java-python-javascript-explained/?envType=daily-question&envId=2024-01-29

class MyQueue {
public:
        stack<int> s1,s2;
    MyQueue() {

    }
    
    void push(int x) {
        if(s1.empty()) s1.push(x);
        else{
            while(!s1.empty()){
                int temp  = s1.top();
                s1.pop();
                s2.push(temp);
            }
            s1.push(x);
            while(!s2.empty()){
                int temp = s2.top();
                s2.pop();
                s1.push(temp);
            }
        }
        return ;
    }
    
    int pop() {
        int temp = s1.top();
        s1.pop();
        return temp;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        if(s1.empty())
        return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
