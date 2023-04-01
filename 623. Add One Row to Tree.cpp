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
    void f(TreeNode *&temp,int val,int i,int depth)
    {
        if(!temp) return;
        if(i==depth)
        {
            TreeNode *l=temp->left;
            TreeNode *r=temp->right;
            temp->right=new TreeNode(val);
            temp->left=new TreeNode(val);
            temp->right->right=r;
            temp->left->left=l;
            return ;
        }
        f(temp->left,val,i+1,depth);
        f(temp->right,val,i+1,depth);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* temp=new TreeNode(val);
            temp->left=root;
            root=temp;
            return root;
        }

        f(root,val,1,depth-1);
        return root;
    }
};
