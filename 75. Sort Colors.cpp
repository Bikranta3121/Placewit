class Solution {
public:
    void sortColors(vector<int>& nums) {
    int zero=0;
    int num=0;
    while(zero<nums.size())
    {
        if(nums[zero]==0) 
        {
            swap(nums[zero],nums[num]);
            num++;
        } 
        zero++;
    }
    int two=nums.size()-1;
    int one=two;
    while(two>=0)
    {
        if(nums[two]==2)
        {
            swap(nums[two],nums[one]);
            one--;
        }
        two--;
    }
    }
};
