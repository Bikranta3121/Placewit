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
    int f(TreeNode*temp,int &ans)
    {
        if(!temp) return 0;
        int left=f(temp->left,ans);
        int right=f(temp->right,ans);
        ans=max({left+temp->val+right,temp->val+left,temp->val+right,ans});
        int max_subtree=max({temp->val+left,temp->val+right,temp->val});
        if(max_subtree<0) return 0;
        return max_subtree;
    }
    int maxPathSum(TreeNode* root) {
      int ans=INT_MIN;
      f(root,ans);
      return ans;  
    }
};
