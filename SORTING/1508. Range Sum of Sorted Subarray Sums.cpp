class Solution {
    long long mod=1000000007;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=i;j<n;j++)
            {
                count+=nums[j];
                ans.push_back(count);
            }
        }
        sort(ans.begin(),ans.end());
        long long sum=0;
        
        for(int i=left-1;i<right;i++)
        {
            sum=(sum+ans[i])%mod;
        }
        return sum;
    }
};
