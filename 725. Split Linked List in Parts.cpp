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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp=head;
        vector<ListNode*> ans;
        int group=k;
        int size=0;
        while(temp)
        {
          size++;
          temp=temp->next;
        }
        temp=head;
        if(size>k)
        {
            ListNode* t1=NULL;
            ListNode* t2=NULL;
            int rem=size%k;
            while(group--)
            {

                for(int i=0;i<size/k;i++)
                {
                   ListNode* newt=new ListNode(head->val);
                   head=head->next; 
                   if(!t1)
                   {
                       t1=newt;
                       t2=newt;
                   }
                   else
                   {
                    t2->next=newt;
                    t2=t2->next;   
                   }
                }
                if(rem)
                {
                   ListNode* newt=new ListNode(head->val);
                    head=head->next;
                    t2->next=newt;
                    t2=t2->next; 
                    rem--;
                }
                ans.push_back(t1);
                t1=NULL;
                t2=NULL;
            }
        }
        else
        {
            while(group--)
            {
                ListNode *t=NULL;
                if(head)
                {
                    t=new ListNode(head->val);
                    head=head->next;
                }
                ans.push_back(t);
                
               
                
            }
        }
        return ans;


    }
};
