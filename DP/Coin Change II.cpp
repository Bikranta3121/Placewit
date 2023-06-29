class Solution {
public:
    int func(int amount,int prev,vector<int> &coins,vector<vector<int>> &dp)
    {
        if(amount==0) return 1;
        if(dp[prev+1][amount]!=-1) return dp[prev+1][amount];
        int take=0;
        for(int i=0;i<coins.size();i++)
        {
            if(prev<=coins[i] and amount>=coins[i])
            {
                take+=func(amount-coins[i],coins[i],coins,dp);
            }
        }
        return dp[prev+1][amount]=take;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(5002,vector<int>(amount+1,-1));
        return func(amount,-1,coins,dp);
    }
}; 
