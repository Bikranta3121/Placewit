class Solution {
public:
    bool check(string s,int i,int j,int k)
    {
        while( i<j)
        {
            if(s[i]!=s[j] and k>0)
            {
                k-=1;
            }
            else if(s[i]!=s[j] and k==0)
             return false;
             i++;
             j--;
        }
        return true;
    }
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<bool> ans(n,true);
        vector<vector<int>> prefix(s.size(),vector<int>(26,0));
        for(int i=0;i<s.size();i++)
        {
            if(i==0)
            {
                prefix[i][s[i]-'a']++;
            }
            else
            {
                for(int j=0;j<26;j++)
                {
                    prefix[i][j]=prefix[i-1][j];
                }
                prefix[i][s[i]-'a']++;
            }
        }
        for(int i=0;i<n;i++)
        {
            int x=queries[i][0];
            int j=queries[i][1];
            int k=queries[i][2];
            int op=0;
            for(int m=0;m<26;m++)
            {
                if(x==0)
                {
                    op+=prefix[j][m]%2;
                }
                else
                {
                    op+=(prefix[j][m]-prefix[x-1][m])%2;
                }
            }
            if(op/2>k) ans[i]=false;
            cout<<op<<" "<<ans[i]<<endl;
        }
        return ans;

    }
};
