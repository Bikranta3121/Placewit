class Solution {
public:
    int LCS(int i,int j,string text1,string text2,vector<vector<int>> &dp)
    {
        if(i==text1.size() || j==text2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0;
        if(text1[i]==text2[j]) take=1+LCS(i+1,j+1,text1,text2,dp);
        int notake=max(LCS(i+1,j,text1,text2,dp),LCS(i,j+1,text1,text2,dp));
        return dp[i][j]=max(take,notake);
    }
    int longestCommonSubsequence(string text1, string text2) {
      vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
      for(int i=text1.size()-1;i>=0;i--)
      {
        for(int j=text2.size()-1;j>=0;j--)
        {
          int take=0;
          if(text1[i]==text2[j])
          {
            take=1+dp[i+1][j+1];
          }
          int notake=max(dp[i+1][j],dp[i][j+1]);
          dp[i][j]=max({dp[i][j],take,notake});
        }
      }
      return dp[0][0];  
    }
};
