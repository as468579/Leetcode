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
    ListNode* deleteDuplicates(ListNode* head) {
        
        while(!head || !(head->next)){ return head; }
        
        ListNode *curr = head->next, *rm_tmp;
        int remove = false;
        while(curr && ((head->val) == (curr->val))){
            rm_tmp = curr;
            curr = curr->next;
            delete rm_tmp;
            remove = true;
        }
        
        if(remove){
            delete head;
            return deleteDuplicates(curr); 
        }else{
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }   
};