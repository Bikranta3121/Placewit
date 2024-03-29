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
    ListNode *reverseList(ListNode *temp)
    {
        ListNode *prev=NULL;
        ListNode *curr=NULL;
        while(temp)
        {
            curr=temp->next;
            temp->next=prev;
            prev=temp;
            temp=curr;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        while(head)
        {
            head->next=reverseList(head->next);
            head=head->next;
        }
    }
};
