//https://leetcode.com/problems/middle-of-the-linked-list/description/?envType=daily-question&envId=2024-03-07

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* f = head;
        ListNode* s = head;
        if(!head||!head->next)
        return head;
        while(f && f->next)
        {
            f = f->next->next;
            s= s->next;
        }
        return s;
    }
};