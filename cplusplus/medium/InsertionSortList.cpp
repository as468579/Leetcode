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
    ListNode* insertionSortList(ListNode* head) {
        
        ListNode *sorted, *curr, *prev, *tmp;
        curr   = head->next;
        sorted = head;
        sorted->next = nullptr; 
        while(curr){ 
            prev   = nullptr;
            sorted = head;
            while(sorted){
                if((sorted->val) > (curr->val)){
                    break;
                }else{
                    prev = sorted; 
                    sorted = sorted->next;
                }
            }
            tmp = curr;
            curr = curr->next;
            if(not prev){ head = tmp; }
            else{ prev->next = tmp; }
            tmp->next = sorted;
        }
        return head;
    }
};