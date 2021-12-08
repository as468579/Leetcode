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
        ListNode *curr = head;
        int count = 0;
        while(curr){
            curr = curr->next;
            count++;
            if(count > 10000){ return true; }
        }
        return false;
    }
};