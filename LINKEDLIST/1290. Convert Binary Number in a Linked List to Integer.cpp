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
    int getDecimalValue(ListNode* head) {
       int size=-1;
       ListNode* temp=head;
       int ans=0;
       while(temp!=NULL)
       {
           size++;
           temp=temp->next;
       } 
       while(head!=NULL)
       {
          ans+=pow(2,size)*head->val;
          size--;
          head=head->next;
       }
       return ans;
       
    }
};
