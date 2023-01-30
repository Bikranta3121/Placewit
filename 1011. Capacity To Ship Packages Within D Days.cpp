class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=1;
        int high=0;
        for(int i=0;i<weights.size();i++)
         high+=weights[i];
        int count; 
        int ans;
        int mid;
        while(low<=high) 
        {
          count=1;
          int sum=0;
          mid=high-(high-low)/2;
          int flag=0;
          for(int i=0;i<weights.size();i++)
          {
            if(weights[i]>mid) 
            {
                count=INT_MAX;
                break;
            }  
            if(sum+weights[i]>mid)
             {
                 count++;
                 sum=weights[i];
             }
             else
              sum+=weights[i];
          }
          if(count<=days)
          {
               ans=mid;
              
            high=mid-1;
          }
          else low=mid+1;
        }
        return ans;
    }
};
