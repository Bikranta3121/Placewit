class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        Node *prev_head=NULL;
        Node *next_head=NULL;
        while(head->next!=NULL)
        {
           next_head=head->next;
           head->next=prev_head;
           prev_head=head;
           head=next_head;
        }
        head->next=prev_head;
        return head;
    }
    
};
