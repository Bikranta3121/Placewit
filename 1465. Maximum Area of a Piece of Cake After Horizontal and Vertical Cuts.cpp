class Solution {
    int mod=1000000007;
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        int max_l=hc[0]-0;
        int max_b=vc[0]-0;
        long long int ans=1;
        for(int i=1;i<hc.size();i++)
        {
           max_l=max(max_l,hc[i]-hc[i-1]);
        }
        max_l=max(max_l,h-hc[hc.size()-1]);
        for(int i=1;i<vc.size();i++)
        {
            max_b=max(max_b,vc[i]-vc[i-1]);
        } 
        max_b=max(max_b,w-vc[vc.size()-1]);
       ans=(ans*max_l*max_b)%mod;
        return ans;
    }
};
