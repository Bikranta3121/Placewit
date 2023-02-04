class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
       vector<pair<int,int>> v;
       for(int i=0;i<nums.size();i++)
       {
           v.push_back({nums[i],i});

       }
       sort(v.begin(),v.end());
       int start=0;
       int end=nums.size()-1;
       while(start<end)
       {
           if(v[start].first+v[end].first>target)
            end--;
           else if(v[start].first+v[end].first<target) start++;
           else return {min(v[start].second,v[end].second),max(v[start].second,v[end].second)}; 
       }
       return {-1,-1};
      
    }
};
