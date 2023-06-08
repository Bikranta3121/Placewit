class Solution {
public:
    int f(int i,vector<int> &dp)
    {
        if(i==0) return 1;
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=f(i-1,dp);
        int notake=0;
        if(i>0) notake=f(i-2,dp);
        return dp[i]=take+notake;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            int take=dp[i-1];
            int notake=0;
            if(i>1) notake=dp[i-2];
            dp[i]=take+notake;
        }
        return dp[n];
    }
};
