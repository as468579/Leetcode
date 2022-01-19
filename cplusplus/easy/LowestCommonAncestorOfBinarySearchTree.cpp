/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {             
        TreeNode *smaller = ((p->val) <= (q->val)) ? p : q;
        TreeNode *larger = ((p->val) > (q->val)) ? p : q;
        int lca = root->val;
        while( !( (lca >= (smaller->val)) && ( lca <= (larger->val))) ){
            if(lca < (smaller->val)){
                root = root->right;
            }else if(lca > (larger->val)){
                root = root->left;
            }
            lca = root->val;
        }
        return root;
    }
};