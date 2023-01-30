class Solution {
public:
    void change(int &n)
    {
        int sum=0;
        while(n!=0)
        {
            int r=n%10;
            sum+=r*r;
            n/=10;
        }
        n=sum;
    }
    bool isHappy(int n) {
        unordered_set<int> s;
        while(n!=1)
        {
          if(s.find(n)==s.end())
           s.insert(n);
          else return false;
          change(n); 
        }
        return true;
    }
};
