Node *mergeList(Node *list1,Node *list2)
{
    Node *l1=NULL;
    Node *l2=NULL;
    Node *n1=NULL;
    Node *res=NULL;
    if(!list1) return list2;
    if(!list2) return list1;
    if(list1->data <= list2->data)
    {
        l1=list1;
        l2=list2;
    }
    else
    {
        l1=list2;
        l2=list1;
    }
    res=l1;
    n1=l1;
    while(l2!=NULL)
    {
        while(n1 and n1->data<=l2->data)
        {
            n1=n1->bottom;
        }
        while(l1->bottom!=n1)
        {
            l1=l1->bottom;
        }
        l1->bottom=l2;
        l1=l2;
        l2=n1;
        n1=l1;
    }
    return res;
}
    
Node *flatten(Node *root)
{
  if(!root) return NULL;
  root->next=flatten(root->next);
  return mergeList(root,root->next);
}
