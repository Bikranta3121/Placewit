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
    void f(TreeNode *root,int sum,int &count)
    {
        if(!root) return;
       if(!root->left and !root->right)
       {
           sum=sum*10+root->val;
           count+=sum;
           return;
       }
       sum=sum*10+root->val;
       f(root->left,sum,count);
       f(root->right,sum,count);
    }
    int sumNumbers(TreeNode* root) {
        
        int total_sum=0;
        f(root,0,total_sum);
        return total_sum;
    }
};
