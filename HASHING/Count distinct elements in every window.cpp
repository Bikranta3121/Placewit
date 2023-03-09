class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
       map<int,int> mp;
       int unique=0;
       for(int i=0;i<k;i++)
       {
           if(mp.find(A[i])==mp.end())
           {
               mp[A[i]]=1;
               unique++;
           }
           else
            mp[A[i]]++;
       }
       vector<int> ans;
       ans.push_back(unique);
       for(int i=1;i+k<n+1;i++)
       {
           mp[A[i-1]]--;
           if(mp[A[i-1]]==0) unique--;
           if(mp.find(A[i+k-1])==mp.end() || mp[A[i+k-1]]==0)
           {
               mp[A[i+k-1]]=1;
               unique++;
           }
           else
            mp[A[i+k-1]]++;
           ans.push_back(unique);    
       }
       return ans;
    }
};
