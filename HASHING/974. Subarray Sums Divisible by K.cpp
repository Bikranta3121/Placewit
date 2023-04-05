class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n+1,0);
        prefix[0]=0;
        map<int,int> pref_sum;
        pref_sum[0]=1;
        int count=0;
      
        for(int i=1;i<n+1;i++)
        {
           prefix[i]=prefix[i-1]+nums[i-1];
           while(prefix[i]<0) prefix[i]+=k; 
       
           
           if(pref_sum.find(prefix[i]%k)!=pref_sum.end())
           {
              count+=pref_sum[prefix[i]%k];
             
           }
           
               pref_sum[prefix[i]%k]++;
           

        }
        
        return count;
    }
};
