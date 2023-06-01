typedef pair<int,int> pi;
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       priority_queue<pi,vector<pi>,greater<pi>> pq;
       pq.push({0,0});
       int sum=0;
       vector<int> vis(V,0);
       while(!pq.empty())
       {
           int x=pq.top().first;
           int y=pq.top().second;
           pq.pop();
           if(vis[y])continue;
           vis[y]=1;
           sum+=x;
           for(auto itr:adj[y])
           {
               if(vis[itr[0]]) continue;
               pq.push({itr[1],itr[0]});
           }
       }
       return sum;
        
    }
};
