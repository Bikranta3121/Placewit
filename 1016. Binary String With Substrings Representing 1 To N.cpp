class Solution {
public:
    bool check(vector<int> slider,vector<int> ans)
    {
       for(int i=0;i<ans.size();i++)
       {
           if(ans[i]!=slider[i]) return false;
       }
       return true;
    }
    bool availability(vector<int> &ans,string s)
    {
        vector<int> slider(ans.size(),0);
        int x=ans.size();
        int y=s.size();
        for(int i=0;i<x;i++)
        {
            slider[i]=s[i]-'0';
        }
         if(check(slider,ans)) return true;
        for(int i=x;i<y;i++)
        {
           
            for(int j=0;j<x-1;j++)
            {
                slider[j]=slider[j+1];
            }
            slider[x-1]=s[i]-'0';
             if(check(slider,ans)) return true;
        }
        return false;
    }
    bool queryString(string s, int n) {
        for(int i=1;i<=n;i++)
        {
           vector<int> ans;
           int x=i;
           while(x)
           {
               ans.push_back(x%2);

              // cout<<x%2;
               x/=2;
           }
           //cout<<endl;
           reverse(ans.begin(),ans.end());
           for(int j=0;j<ans.size();j++)
           {
cout<<ans[j];
           }
           cout<<endl;
         if(!availability(ans,s)) return false;
           
        }
        return true;
    }
};
