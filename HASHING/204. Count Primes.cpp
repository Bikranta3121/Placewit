class Solution {
public:
    
    int countPrimes(int n) {
        int count=0;
        vector<bool> num(n-2,true);
        for(int i=2;i<n;i++)
        {
          if(num[i-2])
          {
              int j=2;
              while((i*j)<n)
              {
                  num[i*j-2]=false;
                  j++;
              }
              count++;

          }
        }
        return count;
    }
};
