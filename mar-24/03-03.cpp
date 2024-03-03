// https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/1192448403/?envType=daily-question&envId=2024-03-03

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode* slow = new ListNode();
        slow->next = head;
        ListNode* fast = slow;
        for(int i = 0;i<n;i++) 
        fast = fast -> next;
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        if(head == slow->next){
            return head->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};