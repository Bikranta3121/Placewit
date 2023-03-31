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
    int func(TreeNode *temp,unordered_map<TreeNode*,int> &m)
    {
        if(!temp) return 0;
        int left=func(temp->left,m);
        int right=func(temp->right,m);
        m[temp]=max(left,right)+1;
        return m[temp];
    }
    void f(TreeNode *temp,TreeNode* &ans,unordered_map<TreeNode*,int> &m)
    {
        
        if(m[temp->left]>m[temp->right])
          f(temp->left,ans,m);
        else if(m[temp->left]<m[temp->right])
          f(temp->right,ans,m);  
        else
          ans=temp;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode*ans=NULL;
        unordered_map<TreeNode*,int> m;
        int x=func(root,m);
        f(root,ans,m);
        return ans;
    }
};
