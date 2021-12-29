/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/


// Recursive version
class Solution {
public:
    Node* connect(Node* root) {
        if(not root){ return nullptr; }
        
        if(root->left){
            root->left->next = root->right;
        }
        if(root->right && root->next){
            root->right->next = root->next->left;
        }
        
        connect(root->left);
        connect(root->right);
        return root;
    }
};

/*  Iterative Version
class Solution {
public:
    Node* connect(Node* root) {
        
        if(not root){ return root; }
        
        Node* prev=root, *curr;
        while(prev){
            curr = prev;
            while(curr){
                if(curr->left){
                    curr->left->next = curr->right;
                }
                if(curr->right && curr->next){
                    curr->right->next = curr->next->left;
                }
                curr = curr->next;
            }
            prev = prev->left;
        }
        return root;
    }
};
*/