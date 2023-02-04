class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size()-1;
        int k=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0) k=i;
           
        }
        int left=k;
        int right=k+1;
        vector<int> ans;
        while(left>=0 and right<=n)
        {
           if(-1*nums[left]>nums[right])
           {
               ans.push_back(nums[right]*nums[right]);
               right++;
           }
           else
           {
               ans.push_back(nums[left]*nums[left]);
               left--;
           }
        }
        while(right<=n)
         {
             ans.push_back(nums[right]*nums[right]);
             right++;
         }
         while(left>=0)
         {
             ans.push_back(nums[left]*nums[left]);
             left--;
         }

    
        return ans;
    }
};
