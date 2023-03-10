#include <bits/stdc++.h>
using namespace std;
static bool comp(pair<int,int> &a,pair<int,int> &b)
{
    if(a.second > b.second) return true;
    else if(a.second == b.second )
    { if(a.first < b.first) return true;
      else return false;
    }
    return false;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
     int n;
     cin>>n;
     int arr[n];
     map<int,int> m;
     for(int i=0;i<n;i++)
     {
          cin>>arr[i];
          m[arr[i]]++;
     }
     vector<pair<int,int>> ans;
     for(auto itr:m)
     {
         int x=itr.first;
         int y=itr.second;
         ans.push_back({x,y});
     }
     sort(ans.begin(),ans.end(),comp);
     for(int i=0;i<ans.size();i++)
     {
         for(int j=0;j<ans[i].second;j++)
         {
             cout<<ans[i].first<<" ";
         }
     }
     cout<<endl;
     
     
    }
	return 0;
}
