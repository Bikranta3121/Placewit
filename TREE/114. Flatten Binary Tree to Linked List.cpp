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
  TreeNode *r=NULL;
  void f(TreeNode* &root){
 
       if(!root) return;
       f(root->left);
       f(root->right);
       TreeNode *t=root->right;
       TreeNode *x=root;
       if(root->left)
       {
         root->right=root->left;
         root->left=NULL;
         while(x->right)
         {
           x=x->right;
         }
         x->right=t;
       }
       

        
    }
    void flatten(TreeNode* &root) {
        f(root);
   }
};
