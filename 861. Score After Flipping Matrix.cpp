class Solution {
public:
    int matrixScore(vector<vector<int>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        int sum=0;
       
     for(int i=0;i<m;i++)
     {
        if(grid[i][0]==0)
        {
            for(int j=0;j<n;j++)
            {
                grid[i][j]^=1;
            }
        }
     }   
    
     for(int i=0;i<n;i++)
     {
         int zero=0;
       
             for(int j=0;j<m;j++)
             {
                 if(grid[j][i]==0)
                  zero++;
             }
             if(zero>=m-zero)
             {
                 for(int j=0;j<m;j++)
             {
                 grid[j][i]^=1;
             }
             
         }
     }
    int count=0;
    for(int i=0;i<m;i++)
    {
        int x=0;
        for(int j=n-1;j>=0;j--)
        {
           count+=grid[i][j]*pow(2,x);
           x++;
        }
    }   
     return count;
    }
};
