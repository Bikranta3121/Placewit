class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        int max_left=0;
        int max_right=0;
        for(int i=0;i<n;i++)
        {
            max_left=max(max_left,height[i]);
            max_right=max(max_right,height[n-i-1]);
            left[i]=max_left;
            right[n-i-1]=max_right;
        }
        int vol=0;
        for(int i=0;i<n;i++)
        {
          vol+=min(left[i],right[i])-height[i];
        }
        return vol;
    }
};
