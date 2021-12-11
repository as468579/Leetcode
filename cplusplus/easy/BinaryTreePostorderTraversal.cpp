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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> myVector;
        if(not root){ return myVector; }
        
        vector<int> left_children  = postorderTraversal(root->left);
        vector<int >right_children = postorderTraversal(root->right);
        for(int& v: left_children){ myVector.push_back(v); }
        for(int& v: right_children){ myVector.push_back(v); }
        myVector.push_back(root->val);
        return myVector;
    }
private:
    vector<int> myVector;
};