class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        Node *temp=head;
        vector<int> freq(3,0);
        while(temp!=NULL)
        {
            freq[temp->data]++;
            temp=temp->next;
        }
        
        temp=head;
        int flag=0;
        for(int i=0;i<3;i++)
        {
            int count=freq[i];
            
            while(count--)
            {
               temp->data=i;
               temp=temp->next;
            }
        }
        
        return head;
        
    }
};
