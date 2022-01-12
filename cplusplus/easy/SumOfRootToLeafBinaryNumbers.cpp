/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 /* Top Downe Recursive
class Solution {
public:
    
    int recursive(TreeNode* root, int value){
        if(not root){ return value; } 
        
        int r_sum = 0, l_sum = 0;
        if(root->right){ r_sum = recursive(root->right, value*2+root->right->val); }
        if(root->left) { l_sum = recursive(root->left, value*2+root->left->val); }
        if(!(root->left) && !(root->right)) { 
            return value; 
        }
        return r_sum + l_sum;
        
    }
    
    int sumRootToLeaf(TreeNode* root) {
        return recursive(root, root->val); 
    }
};
*/