class Solution {
public:
   
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
       sort(intervals.begin(),intervals.end());
       int min_val=intervals[0][0];
       int max_val=intervals[0][1];
       vector<vector<int>> ans;
       for(int i=0;i<intervals.size();i++)
       {
            if(intervals[i][0]>max_val)
            {
                ans.push_back({min_val,max_val});
                min_val=intervals[i][0];
                max_val=intervals[i][1];
            }
            else
            {
                min_val=min(min_val,intervals[i][0]);
                max_val=max(max_val,intervals[i][1]);
            }
       }
        ans.push_back({min_val,max_val});
       return ans;
    }   
        
        
};
