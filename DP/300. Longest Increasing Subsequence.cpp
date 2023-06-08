class Solution {
public:
int func(int i,int prev_ind,vector<int> &nums,vector<vector<int>> &dp)
{
    if(i==nums.size()) return 0;
    if(dp[i][prev_ind+1]) return dp[i][prev_ind+1];
   // if(mp.find({i,prev})!=mp.end()) return mp[{i,prev}];
    int take=0;
    if(prev_ind==-1 || nums[i]>nums[prev_ind])
     take=1+func(i+1,i,nums,dp);
    int notake=func(i+1,prev_ind,nums,dp);
    return dp[i][prev_ind+1]=max(take,notake); 
    
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,1));

        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int take=0;
                if(nums[i]>nums[j])
                 take=1+dp[i+1][i];
                int notake=dp[i+1][j];
                dp[i][j]=max(take,notake);
                ans=max(dp[i][j],ans);
            }
        }
        return ans;
    }
};
