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
class CBTInserter {
    TreeNode* root=NULL;
public:
    CBTInserter(TreeNode* root) {
        this->root=root;
        
    }
    
    int insert(int val) {
        if(!root)
        {
            TreeNode* temp=new TreeNode(val);
            root->val=val;
            return val;
        } 

        queue<TreeNode*> q;
        q.push(root);
        TreeNode *parent;
        while(!q.empty())
        {
            int x=q.size();
            int flag=0;
            while(x--)
            {
                TreeNode *temp=q.front();
                q.pop();
                if(!temp->right)
                {
                    parent=temp;
                    flag=1;
                    break;
                }
                q.push(temp->left);
                q.push(temp->right);
            }
            if(flag)break;
        }
        TreeNode *t=new TreeNode(val);
        if(!parent->left)
        {
            parent->left=t;
        }
        else parent->right=t;
        return parent->val;

    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
