//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int u,vector<int> &vis,vector<int> &fix,vector<int> adj[])
    {
        if(vis[u]) return true;
        vis[u]=true;
        for(int v:adj[u])
        {
            
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
       vector<int> v(V,0);
       vector<int> p(V,-1);
       for(int i=0;i<V;i++)
       {
           if(v[i]==0)
           {
              v[i]=1;
              queue<int> q;
              q.push(i);
              while(!q.empty())
              {
                 int u=q.front();
                 q.pop();
                 for(int x:adj[u])
                 {
                     if(v[x] and x!=p[u])
                     {
                         return true;
                     }
                     else if(!v[x])
                     {
                         q.push(x);
                         v[x]=1;
                         p[x]=u;
                     }
                 }
              }
              
           }
       }
       return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
