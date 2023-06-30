class Solution {
public:
    int t_fee=0;
    int func(int i,int buy,vector<int> &prices,vector<vector<int>> &dp)
    {
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int take=0;
        int notake=0;
        if(buy)
        {
           take+=max(func(i+1,1,prices,dp),func(i+1,0,prices,dp)-prices[i]-t_fee);
        }
        else
        {
            notake+=max(func(i+1,1,prices,dp)+prices[i],func(i+1,0,prices,dp));
        }
        return dp[i][buy]=max(take,notake);
    }
    int maxProfit(vector<int>& prices, int fee) {
      t_fee=fee;  
      vector<vector<int>> dp(prices.size()+1,vector<int> (2,0));
      for(int i=prices.size()-1;i>=0;i--)
      {
          for(int j=0;j<2;j++)
          {
              int take=0;
              int notake=0;
              if(j)
              {
                take+=max(dp[i+1][1],dp[i+1][0]-prices[i]-fee);
              }
              else
              {
                  notake+=max(dp[i+1][1]+prices[i],dp[i+1][0]);
              }
              dp[i][j]=max(take,notake);
          }
      }
      return dp[0][1];
    }
};
