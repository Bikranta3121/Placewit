class Solution {
public:
    void dfs(int src,int dest,vector<int> adj[],vector<int> &vis,int &count)
    {
        if(src==dest){count++;return;}
        vis[src]=1;
        for(int v:adj[src])
        {
            if(!vis[v]) dfs(v,dest,adj,vis,count);
        }
        vis[src]=0;
        
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    vector<int> adj[n];
	    vector<int> vis(n,0);
	    for(int i=0;i<edges.size();i++)
	    {
	        adj[edges[i][0]].push_back(edges[i][1]);
	    }
	    int count=0;
	    dfs(s,d,adj,vis,count);
	    return count;
	}
};
