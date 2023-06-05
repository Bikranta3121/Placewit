class Solution {
  public:
    int mod=1e9+7;
    int dfs(int src,int dest,int k,vector<vector<vector<int>>> &dp,vector<vector<int>> &graph)
    {
        if(k==0 and src==dest) return 1;
        if(k==0) return 0;
        if(dp[src][dest][k]!=-1) return dp[src][dest][k]%mod;
        int ans=0;
       
        for(int j=0;j<graph.size();j++)
        {
            if(graph[src][j])
            {
               ans=(ans%mod+dfs(j,dest,k-1,dp,graph)%mod)%mod; 
            }
        }
        
        return dp[src][dest][k]=ans%mod;
    }
	int MinimumWalk(vector<vector<int>>&graph, int u, int v, int k){
	    vector<vector<vector<int>>> dp(graph.size(),vector<vector<int>> (graph[0].size(),vector<int> (k+1,-1)));
	    return dfs(u,v,k,dp,graph)%mod;
	   
	}

};
