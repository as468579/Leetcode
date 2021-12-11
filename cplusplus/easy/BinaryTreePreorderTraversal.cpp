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
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(not root){ return preorder; }
        
        vector<int> left_children = preorderTraversal(root->left);
        vector<int> right_children = preorderTraversal(root->right);
        
        preorder.push_back(root->val);
        for(int &v: left_children) { preorder.push_back(v); }
        for(int &v: right_children){ preorder.push_back(v); }
        return preorder;
    }
};