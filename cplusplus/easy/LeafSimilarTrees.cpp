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
    
private:
    vector<int> getLeaves(TreeNode *root){
        
        if((!root->left) && (!root->right)){
            return vector<int>(1, root->val);
        }
        
        vector<int> res;
        if(root->left){
            for(auto &leaf: getLeaves(root->left)){
                res.push_back(leaf);
            }
        }
        if(root->right){
            for(auto &leaf: getLeaves(root->right)){
                res.push_back(leaf);
            }
        }
        return res;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> left_leaves  = getLeaves(root1);
        vector<int> right_leaves = getLeaves(root2);
        
        if(left_leaves.size() != right_leaves.size()){
            return false;
        }
        
        for(int i=0; i<left_leaves.size(); ++i){
            if(left_leaves[i] != right_leaves[i]){
                return false;
            }
        }
        return true;
    }
};