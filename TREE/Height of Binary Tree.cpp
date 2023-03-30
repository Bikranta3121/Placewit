int max(int a,int b)
{
    return a>b? a:b;
}
int height(struct Node* node)
{
    if(node==NULL)
     return 0;
    int l=height(node->left);
    int r=height(node->right);
    int ans=1+max(l,r);
    return ans;
}
