/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode *temp=head;
        vector<int> ans;
        while(temp!=NULL)
        {
            int x=temp->val;
            ListNode *t=temp->next;
            while(t!=NULL)
            {
               if(x<t->val)
               {
                   x=t->val;
                   break;
               }
               t=t->next;
            }
            if(x==temp->val)
             ans.push_back(0);
            else
             ans.push_back(x);
            temp=temp->next;  
        }
        return ans;
    }
};
