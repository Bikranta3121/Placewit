typedef pair<int,int> pi;
typedef long long int ll;
class Solution {
public:
    static bool comp(pi &a,pi &b)
    {
        if(a.first<b.first) return true;
        if(a.first==b.first and a.second<b.second) return true;
        return false;
    }
    int memoization(int i,map<int,int> &dp)
    {
        if(i==1) return 0;
        if(dp.find(i)!=dp.end()) return dp[i];
        int ans=0;
        if(i&1) ans=1+memoization(3*i+1,dp);
        else ans=1+memoization(i/2,dp);
        return dp[i]=ans;
    }
    int getKth(int lo, int hi, int k) {
        vector<pi> pq;
        map<int,int> dp;
        for(int i=lo;i<=hi;i++)
        {
           pq.push_back({memoization(i,dp),i});
        }
        sort(pq.begin(),pq.end(),comp);        
        return pq[k-1].second;

    }
};
