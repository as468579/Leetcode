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

// 18:35
class Solution {
    
private:
    vector<vector<unsigned int>> traverse(TreeNode *root, unsigned int index){

        vector<vector<unsigned int>> left;
        vector<vector<unsigned int>> right;
        if(root->left) { left  = traverse(root->left,   index*2); }
        if(root->right){ right = traverse(root->right, index*2+1 ); }
        
        int i=0, j=0;
        vector<vector<unsigned int>> res(max(left.size(), right.size()) + 1);
        res[0] = vector<unsigned int>(2, index);
        while((i < left.size()) && (j < right.size())){
            left[i][1] = right[j][1];
            res[i+1] = left[i];
            i = i + 1;
            j = j + 1;
        }
        
        while(i < left.size()){ 
            res[i+1] = (left[i]);
            i++;
        }
        while(j < right.size()){
            res[j+1] = (right[j]);
            j++;
        }
        
        return res;
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        
        vector<vector<unsigned int>> level_indices;
        while(root->left && !root->right){ root = root->left; }
        while(!root->left && root->right){ root = root->right; }
        
        level_indices = traverse(root, 1);
        
        unsigned int level_max = 0;
        int left, right;
        
        for(auto &vec: level_indices){
            level_max = max(level_max, (vec[1] - vec[0] + 1));
        }
        return (int)level_max;
        
        return 0;
    }
};