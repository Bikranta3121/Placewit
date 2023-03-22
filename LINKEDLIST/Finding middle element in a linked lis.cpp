class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        Node *temp=head;
        int size=0;
        while(temp!=NULL)
        {
            size++;
            temp=temp->next;
            
        }
        size=size/2;
        temp=head;
        while(size--)
        {
            temp=temp->next;
        }
        return temp->data;
    }
};
