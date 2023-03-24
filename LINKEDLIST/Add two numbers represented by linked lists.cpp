class Solution
{
    public:
    struct Node* f(vector<int> &v,struct Node* first, Node* second)
    {
        for(int i=0;i<v.size();i++)
        {
            Node *temp=new Node(v[i]);
            if(first==NULL)
            {
                first=temp;
                second=first;
            }
            else
            {
                second->next=temp;
                second=second->next;
            }
        }
        return first;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        
        vector<int> v1;
        vector<int> v2;
        while(first!=NULL)
        {
            v1.push_back(first->data);
            first=first->next;
        }
        
       
        while(second!=NULL)
        {
            v2.push_back(second->data);
            second=second->next;
        }
       int carry=0;
       int i=v1.size()-1,j=v2.size()-1;
       while(i>=0 and j>=0)
       {
           int sum=v1[i]+v2[j]+carry;
           v1[i]=sum%10;
           v2[j]=sum%10;
           carry=sum/10;
           i--;
           j--;
       }
       while(j>=0)
       {
           int sum=v2[j]+carry;
           v2[j]=sum%10;
           carry=sum/10;
           j--;
       }
       while(i>=0)
       {
           int sum=v1[i]+carry;
           v1[i]=sum%10;
           carry=sum/10;
           i--;
       }
       
       if(carry==1)
       {
          Node *t=new Node(carry);
          first=t;
          second=t;
       }
       if(v1.size()>v2.size())
       {
            first=f(v1,first,second);
       }
       else
       {
           first=f(v2,first,second);
       }
       
       return first;
       
        
    }
};
