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
   
    int rob(TreeNode* root) {
       if(!root) return 0;
       int notpick=rob(root->left)+rob(root->right);
       int rob_val=root->val;
       if(root->left) rob_val+=rob(root->left->left)+rob(root->left->right);
       if(root->right) rob_val+=rob(root->right->left)+rob(root->right->right);
       return max(notpick,rob_val);
    }
};
