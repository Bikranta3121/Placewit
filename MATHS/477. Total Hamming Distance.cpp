class Solution {
public:
    int totalHammingDistance(vector<int>& nums)
    {
        long long int count=0;
        vector<int> bit_32(32,0);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<32;j++)
            {
                if(nums[i]&(1<<j)) bit_32[j]++;
            }
        }
        for(int i=0;i<32;i++)
        {
            count+=bit_32[i]*(nums.size()-bit_32[i]);
        }        
       return count;
    }
};
