class Solution {
public:
   void func(int i,int sum,int tsum,int mask,vector<int> &nums,vector<int> &v)
    {
        if(sum==tsum) {v.push_back(mask); return;}
        if(i>=nums.size() || sum+nums[i]>tsum) return;
        func(i+1,sum,tsum,mask,nums,v);
        mask=mask|(1<<i);
        sum+=nums[i];
        func(i+1,sum,tsum,mask,nums,v);
        return;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
       vector<int> v;
       int tsum=0;
       for(int i=0;i<nums.size();i++)
       {
         tsum+=nums[i];
       }
       if(tsum%k!=0) return false;
       sort(nums.begin(),nums.end());
       func(0,0,tsum/k,0,nums,v);
       int num=1<<nums.size();
       vector<vector<bool>> dp(k,vector<bool>(num,false));
       for(int a:v)
       {
           dp[0][a]=true;
       }
       for(int i=0;i<k-1;i++)
       {
           for(int j=0;j<num;j++)
           {
              if(dp[i][j])
              {
                  for(int a:v)
                  {
                      if((a&j)==0)
                      {
                          dp[i+1][(a|j)]=true;
                      }
                  }
              }
           }
       }
      
       return dp[k-1][num-1];
    }
};
