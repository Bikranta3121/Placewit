class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int count=0;
        int n=nums.size();
        int prev=nums[0];
        for(int i=0;i<nums.size()-1;i++)
        {
          if(nums[i]==nums[i+1])
          {
             
            count++;
          }
          else
          {
              if(count+1>n/3) ans.push_back(nums[i]);
              count=0;
          }
        }
        if(count+1>n/3) ans.push_back(nums[n-1]);

      
        return ans;
    }
};
/**************************************************************************************************************************************************/
/*OPTIMIZE BOREE ALGO*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int maj_ele1=INT_MIN;
        int maj_ele2=INT_MIN;
        int count1=0,count2=0;
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(count1==0 and maj_ele2!=nums[i])
            {
                maj_ele1=nums[i];
                count1=1;
            }
            else if(count2==0 and maj_ele1!=nums[i])
             {
                 maj_ele2=nums[i];
                 count2=1;
             }
             else if(maj_ele1==nums[i]) count1++;
             else if(maj_ele2==nums[i]) count2++;
             else
             {
                 count1--;
                 count2--;
             }
        }
        count1=0;
        count2=0;
         for(int i=0;i<n;i++)
         {
           if(nums[i]==maj_ele1) count1++;
           if(nums[i]==maj_ele2) count2++;
         }
         if(count1>n/3) ans.push_back(maj_ele1);
         if(count2>n/3) ans.push_back(maj_ele2);
         return ans;
    }

};
