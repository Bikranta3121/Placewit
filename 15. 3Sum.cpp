class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        map<pair<int,int>,int> s;
        vector<vector<int>> ans;
        while(i<=nums.size()-3 and nums[i]<0 )
        {
            int x=-nums[i];
            int start=i+1;
            int end=nums.size()-1;
            while(start<nums.size()-1 and start<end)
            {
                if(nums[start]+nums[end]>x) end--;
                else if(nums[start]+nums[end]<x) start++;
                else
                {
                    if(s.find({nums[start],nums[end]})==s.end())
                    {
                     ans.push_back({nums[i],nums[start],nums[end]});
                     s[{nums[start],nums[end]}]=nums[i];
                    }
                    start++;
                    end--;
                } 
            }  
            i++;          
        }
        if(i<=nums.size()-3 and nums[i]==0)
        {
            if(nums[i+1]==0 and nums[i+2]==0) ans.push_back({0,0,0});
        }
        return ans;
    }
};
