class Solution {
public:
    bool dp(int i,vector<int> &nums,int sum,int target_sum,vector<vector<int>>& dpp)
    {
        if(2*sum==target_sum) return true;
        if(i==nums.size()) return false;
        if(dpp[i][sum]!=-1) return dpp[i][sum];
        bool pick=dp(i+1,nums,sum+nums[i],target_sum,dpp);
        bool notpick=dp(i+1,nums,sum,target_sum,dpp);
        return dpp[i][sum]=pick+notpick;
    }
    bool canPartition(vector<int>& nums) {
        int target_sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            target_sum+=nums[i];
        }
        if(target_sum & 1) return false;
        vector<vector<bool>> dpp(nums.size()+1,vector<bool>(target_sum+1,false));
        for(int i=0;i<=nums.size();i++)
         dpp[i][target_sum/2]=true;
         
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int j=target_sum;j>=0;j--)
            {
                bool pick=false;
                if(j+nums[i]<=target_sum)
                   pick=dpp[i+1][j+nums[i]];
                bool notpick=dpp[i+1][j];
                dpp[i][j]=pick|notpick;   
            }
        }
        return dpp[0][0];
        
        
    }
};
