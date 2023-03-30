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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int left_node;
        while(!q.empty())
        {
           int n=q.size();
           left_node=q.front()->val;
           while(n--)
           {
             TreeNode *temp=q.front();
             if(temp->left) q.push(temp->left);
             if(temp->right) q.push(temp->right);
             q.pop();
           }
        }
        return left_node;
    }
};/**
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int left_node;
        while(!q.empty())
        {
           int n=q.size();
           left_node=q.front()->val;
           while(n--)
           {
             TreeNode *temp=q.front();
             if(temp->left) q.push(temp->left);
             if(temp->right) q.push(temp->right);
             q.pop();
           }
        }
        return left_node;
    }
};
