class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
       unordered_set<int> s;
       int n=nums.size();
       for(int i=0;i<n;i++)
       {
           s.insert(nums[i]);
       } 
       int count=0;
       for(int i=0;i<n;i++)
       {
           if(s.find(nums[i]+diff)!=s.end() and s.find(nums[i]+diff+diff)!=s.end()) count++;
       }
       return count;
    }
};
