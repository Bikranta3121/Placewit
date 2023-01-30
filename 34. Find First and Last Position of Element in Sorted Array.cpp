class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=high-(high-low)/2;
            if(nums[mid]==target)
            {
              ans=mid;
              high=mid-1; 
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            } 
        }
        int start_ind=ans;
       
        int count=0;
        while(ans>=0 and ans<nums.size() and nums[ans]==target)
        {
           count++;
           ans++;
        }
        if(start_ind==-1) return{-1,-1};
        return {start_ind,start_ind+count-1};
    }
};
