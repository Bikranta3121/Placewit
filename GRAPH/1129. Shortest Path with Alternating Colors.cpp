class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> adj[n];
        int red_size=redEdges.size();
        int blue_size=blueEdges.size();
        for(int i=0;i<red_size;i++)
        {
            adj[redEdges[i][0]].push_back({redEdges[i][1],0});
        }
        for(int i=0;i<blue_size;i++)
        {
            adj[blueEdges[i][0]].push_back({blueEdges[i][1],1});
        }
        queue<pair<int,int>> q;
        vector<int> path(n,-1);
        vector<int> vis_red(n,0);
        vector<int> vis_blue(n,0);
        path[0]=0;
        for(auto itr:adj[0])
        {
            q.push({itr[0],itr[1]});
            if(!itr[1]) vis_red[itr[0]]=1;
            else vis_blue[itr[0]]=1;
            if(path[itr[0]]==-1)  path[itr[0]]=1;
            else path[itr[0]]=min(path[itr[0]],1);
        }
        
      
        vis_red[0]=1;
        vis_blue[0]=1;
        int dist=1;
        while(!q.empty())
        {   
            dist++;
            int s=q.size();
            while(s--)
            {
                int node=q.front().first;
                int colour=q.front().second;
                q.pop();
                for(auto itr:adj[node])
                {
                    if(colour==1 and itr[1]==0 and !vis_red[itr[0]])
                    {
                         if(path[itr[0]]==-1)  path[itr[0]]=dist;
                         else path[itr[0]]=min(path[itr[0]],dist);
                         q.push({itr[0],itr[1]});
                         vis_red[itr[0]]=1;
                    }
                    if(colour==0 and itr[1]==1 and !vis_blue[itr[0]])
                    {
                         if(path[itr[0]]==-1)  path[itr[0]]=dist;
                         else path[itr[0]]=min(path[itr[0]],dist);
                         q.push({itr[0],itr[1]});
                         vis_blue[itr[0]]=1;
                    }
                }

            }
            //dist++;
        }
       return path;
    }
};
