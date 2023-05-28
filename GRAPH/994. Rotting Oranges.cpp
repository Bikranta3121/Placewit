class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> row{0,-1,0,1};
        vector<int> col{-1,0,1,0};
       vector<vector<int>> vis(n,vector<int> (m,0));
       queue<pair<int,int>> q;
       int time=-1,fresh=0;
       
       for(int i=0;i<n;i++) 
       {
           for(int j=0;j<m;j++)
           {
               if(grid[i][j]==1) fresh++;
               else if(grid[i][j]==2) 
               {vis[i][j]==1 ;q.push({i,j});}
           }
       }
       while(!q.empty())
       {
           int s=q.size();
           while(s--)
           {
               int r=q.front().first;
               int c=q.front().second;
               q.pop();
               for(int k=0;k<4;k++)
               {
                   int r_k=r+row[k];
                   int c_k=c+col[k];
                   if(r_k<0 || r_k>=n || c_k<0 || c_k>=m) continue;
                   if(!vis[r_k][c_k] and grid[r_k][c_k]==1)
                   {
                       vis[r_k][c_k]=1;
                       q.push({r_k,c_k});
                       fresh--;
                   }
               }
              
           }
            time++;
       }
       return (fresh>0) ? -1 : ((time==-1) ? 0:time);
    }
};
