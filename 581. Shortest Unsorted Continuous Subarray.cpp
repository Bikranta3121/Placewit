class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        int min_val=nums[n-1];
        int max_val=nums[0];
        suffix[n-1]=min_val;
        prefix[0]=max_val;
        for(int i=1;i<n;i++)
        {
          max_val=max(max_val,nums[i]);
          min_val=min(min_val,nums[n-1-i]);
          suffix[n-1-i]=min_val;
          prefix[i]=max_val;
        }
        int i=0;
        int j=n-1;
        while(i<=j)
        {
           if(nums[i]==suffix[i] and nums[j]==prefix[j])
           {
            i++;
            j--;
           }
           else if(nums[i]!=suffix[i] and nums[j]!=prefix[j])
            break;
           else if(nums[i]!=suffix[i])
            j--;
           else
            i++;  
        }
        if(j-i+1==-1) return 0;
        return j-i+1;
    }
};
