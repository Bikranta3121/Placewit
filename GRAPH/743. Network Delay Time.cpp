typedef pair<int,int> pi;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> adj[n];
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        vector<int> vis(n,0);
        vector<int> path(n,-1);
        path[k-1]=0;
        priority_queue <pi,vector<pi>,greater<pi>> pq;
        pq.push({0,k-1});
        while(!pq.empty())
        {
            int node=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
            if(!vis[node])
            {
                vis[node]=1;
            }
            else continue;
            for(auto itr:adj[node])
            {
              
                   if(path[itr[0]]==-1) path[itr[0]]=dist+itr[1];
                   else path[itr[0]]=min(path[itr[0]],dist+itr[1]);
                   pq.push({path[itr[0]],itr[0]});
                                         
            }
        }
        int time=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(path[i]==-1) return -1;
            time=max(time,path[i]);
        }
        return time;
    }
};
