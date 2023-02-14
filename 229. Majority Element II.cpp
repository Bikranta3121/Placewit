class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int count=0;
        int n=nums.size();
        int prev=nums[0];
        for(int i=0;i<nums.size()-1;i++)
        {
          if(nums[i]==nums[i+1])
          {
             
            count++;
          }
          else
          {
              if(count+1>n/3) ans.push_back(nums[i]);
              count=0;
          }
        }
        if(count+1>n/3) ans.push_back(nums[n-1]);

      
        return ans;
    }
};
