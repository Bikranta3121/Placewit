typedef long long int ll;
class Solution {
public:
    int memo(int i,int j,int m,int n,vector<vector<int>> &obstacle,vector<vector<int>> &dp)
    {
        if(i>=m || j>=n) return 0;
        if(obstacle[i][j]) return 0;
        if(i==m-1 and j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int down=0,right=0;
        down+=memo(i+1,j,m,n,obstacle,dp);
        right+=memo(i,j+1,m,n,obstacle,dp);
        return down+right;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacle) {
        int m=obstacle.size();
        int n=obstacle[0].size();
        if(obstacle[m-1][n-1]) return 0;
        vector<vector<ll>> dp(m+1,vector<ll>(n+1,0));
         dp[m-1][n-1]=1;
         for(int i=m-1;i>=0;i--)
         {
             for(int j=n-1;j>=0;j--)
             {
                 if(obstacle[i][j]) 
                 {                  
                     continue;
                  }
                 ll down=dp[i+1][j];
                 ll up=dp[i][j+1];
                 dp[i][j]+=up+down;

             }
         }
        return dp[0][0];
    }
};
