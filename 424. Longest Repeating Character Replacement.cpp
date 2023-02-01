class Solution {
public:
    int freq(vector<int> &A)
    {
        int max_i=0;
        for(int i=0;i<26;i++)
          max_i=max(max_i,A[i]);
        return max_i;        
    }
    bool check(string &s,int len,int k)
    {
        vector<int> A(26,0);
        for(int i=0;i<len;i++)
        {
         char ch=s[i];
         A[ch-'A']++;        
        }  
        int max_freq=freq(A);        
        if(len-max_freq<=k) return true;
        for(int i=1;i<s.size()-len+1;i++)
        {
               char ch=s[i-1];
               char ch1=s[i+len-1];
               A[ch-'A']--;
               A[ch1-'A']++;
               max_freq=freq(A);
               if(len-max_freq<=k) return true;
        }
        return false;
    }
    int characterReplacement(string s, int k) 
    {
        int low=1;
        int high=s.size();
        int ans;
        while(low<=high)
        {
            int mid=high-(high-low)/2;
            if(check(s,mid,k))
            {
              ans=mid;
              cout<<mid;
              low=mid+1;
            }
            else
             high=mid-1;
        }
        return ans;
    }
};
