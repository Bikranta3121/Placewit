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
    bool isCompleteTree(TreeNode* root) {
        if(!root) return false;
        queue<TreeNode*> q;
        q.push(root);
        int flag=0;
        while(!q.empty())
        {
            int n=q.size();
           
            while(n--)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(flag and temp->left) return false;
                if(!temp->left and temp->right) return false;
                if(!temp->right and !flag) flag=1;
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

        }
        return true;
        
    }
};
