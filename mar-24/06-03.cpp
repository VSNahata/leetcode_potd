// https://leetcode.com/problems/linked-list-cycle/description/?envType=daily-question&envId=2024-03-06

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* s = head;
        ListNode* f = head;
        if(!head) return false;
        while(true){
            if(s->next) s = s->next;
            else return false;
            if(f->next && f->next->next) f = f->next->next;
            else return false;
            if(s == f) return true;
        }
        return false;
    }
};