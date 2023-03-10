class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int> st;
        vector<int> prefix_sum;
        int pref_sum=0;
        for(int i=0;i<nums.size();i++)
        {
          pref_sum+=nums[i];
          prefix_sum.push_back(pref_sum);
         
        } 
        for(int i=0;i<nums.size();i++)
        {
            if(prefix_sum[i]==k) ans++;
            if(st.find(prefix_sum[i]-k)!=st.end())
             ans+=st[prefix_sum[i]-k];
            st[prefix_sum[i]]++; 
        }
        return ans;
    }
};
