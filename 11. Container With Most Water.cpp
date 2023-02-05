class Solution {
public:
    int maxArea(vector<int>& a) {
        int start=0;
        int end=a.size()-1;
        int ans=0;
        while(start<end)
        {
          if(a[start]<a[end])
          {
              ans=max(ans,a[start]*(end-start));
              start++;
          }
          else
          {
              ans=max(ans,a[end]*(end-start));
              end--;
          }
        }
        return ans;
    }
};
