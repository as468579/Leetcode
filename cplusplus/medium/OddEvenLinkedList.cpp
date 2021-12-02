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
    ListNode* oddEvenList(ListNode* head) {
        
        if(not head) return head;
        else if(not (head->next)) return head;
        else if(not (head->next->next)) return head;
        
        ListNode *curr;
        ListNode *even_h, *odd_h, *even_c, *odd_c;
        
        // Copy operator?
        odd_h = odd_c = head;
        even_h = even_c = head->next;
        curr = head->next->next;
        int flag = 1;
        while(curr){
            
            if(flag){
                odd_c->next = curr;
                odd_c = odd_c->next;
            }
            else{
                even_c->next = curr;
                even_c = even_c->next;
            }
            flag = not flag;
            curr = curr->next;
        }
        
        odd_c->next = even_h;
        even_c->next = nullptr;
        return odd_h;

    }
};