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
    int f(TreeNode* temp,unordered_map<int,int> &m)
    {
        if(!temp) return 0;
        int left=f(temp->left,m);
        int right=f(temp->right,m);
        m[temp->val+left+right]++;
        return temp->val+left+right;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> m;
        f(root,m);
        vector<int> ans;
        int max_freq=1;
        for(auto itr=m.begin();itr!=m.end();itr++)
        {
            if(itr->second>max_freq)
            {
                max_freq=itr->second;
            }
        }
        for(auto itr=m.begin();itr!=m.end();itr++)
        {
            if(itr->second==max_freq)
            {
                ans.push_back(itr->first);
            }
        }
        return ans;
        
    }
};
