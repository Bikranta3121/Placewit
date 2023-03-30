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
    bool preorder(TreeNode*temp,int count,int targetSum)
    {
        if(temp and !temp->left and !temp->right)
        {
            if(count+temp->val==targetSum) return true;
            else return false;
        }
        if(!temp) return false;
        if(preorder(temp->left,count+temp->val,targetSum)) return true;
         if(preorder(temp->right,count+temp->val,targetSum) ) return true;
         return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
       return preorder(root,0,targetSum);
    }
};
