class Solution {
public:
    vector<int> validity={1,7,30};
    int func(int i,int val,int range,vector<int> &days,vector<int> &costs,vector<vector<vector<int>>> &dp)
    {
        if(i==days.size()) return 0;
        if(dp[i][val][range+1]!=-1) return dp[i][val][range+1]; 
        int take=INT_MAX;
        if(range==-1 || val+range-1<days[i])
        {
            for(int k=0;k<3;k++)
            {
               take=min(take,costs[k]+func(i+1,days[i],validity[k],days,costs,dp));
            }
        }
        else
        {
            take=func(i+1,val,range,days,costs,dp);
        }
        return dp[i][val][range+1]=take;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<vector<int>>> dp(days.size(),vector<vector<int>>(366,vector<int>(32,-1)));
        return func(0,0,-1,days,costs,dp);
    }
};
