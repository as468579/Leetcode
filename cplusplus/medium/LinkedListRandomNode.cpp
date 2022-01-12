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

// With Extra Space, but much faster
class Solution {
private:
    vector<int> container;
public:
    Solution(ListNode* head) {
        ListNode *curr = head;
        while(curr){
            container.push_back(curr->val);
            curr = curr->next;
        }
    }
    
    int getRandom() {
        return container[rand() % container.size()];
    }
};

/*

// No extra space, but much slower
class Solution {
private:
    ListNode *m_head;
    double curr_max;
    int choosen;
public:
    Solution(ListNode* head):m_head(head) {
        curr_max = 0.0;
    }
    
    int getRandom() {
        ListNode *curr = m_head;
        curr_max = 0;
        while(curr){

            random_device rd;
            mt19937 gen(rd());
            uniform_real_distribution<> dist(0.0, 1.0);
            double rnd = dist(gen);
            if(rnd > curr_max){
                choosen = curr->val;
                curr_max = rnd;
            }
            // cout << curr->val << ", " << rnd << ", " << curr_max <<endl;
            curr = curr->next;
        }
        return choosen;    
    }
};

*/ 

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */