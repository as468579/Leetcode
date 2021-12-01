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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> inorder;
        if(not root) return inorder;
        
        vector<int> left_child, right_child;
        left_child = inorderTraversal(root->left);
        right_child = inorderTraversal(root->right);
        for(vector<int>::iterator it=left_child.begin(); it!=left_child.end(); it++){
            inorder.push_back((*it));
        }
        inorder.push_back(root->val);
        for(vector<int>::iterator it=right_child.begin(); it!=right_child.end(); it++){
            inorder.push_back((*it));
        }
        
        return inorder;
    }
};

