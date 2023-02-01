class Solution {
public:
    int max_freq(vector<int> arr)
    {
        int max_i=0;
        max_i=max(max_i,max(arr[0],arr[1]));
        return max_i;
    }
    bool check(vector<int>& nums,int len,int k)
    {
        vector<int> arr(2,0);
        for(int i=0;i<len;i++)
        {
            arr[nums[i]]++;
        }
        
        if(len-arr[1]<=k) return true;
        for(int i=1;i<nums.size()-len+1;i++)
        {
            arr[nums[i-1]]--;
            arr[nums[i+len-1]]++;
           
            if(len-arr[1]<=k) return true;
        }
        return false;
    }
    int longestOnes(vector<int>& nums, int k) {
        int low=0;
        int high=nums.size();
        int ans;
        while(low<=high)
        {
            int mid=high-(high-low)/2;
            if(check(nums,mid,k))
             {
                 ans=mid;
              
                 low=mid+1;
             }
             else
              high=mid-1;
        }
        return ans;
    }
};
