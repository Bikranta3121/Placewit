class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        int low=1;
        int high=x;
        int ans=1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(mid==sqrt(x)) return mid;
            else if(mid>sqrt(x))
            {
                high=mid-1;
            }
            else
            {
              ans=mid;
              low=mid+1;
            }
        }
        return ans;
    }
};
