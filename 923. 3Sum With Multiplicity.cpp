class Solution {
     int mod=1000000007;
public:
    int get_count(vector<int> freq,int a,int b,int c)
    {
        vector<int> p_freq(101,0);
        p_freq[a]++;
        p_freq[b]++;
        p_freq[c]++;
        int count=1;
        for(int i=0;i<101;i++)
        {
            if(p_freq[i])
            {
                long long int x=freq[i];
                long long int y=x-1;
                long long int z=x-2;
                if(p_freq[i]==1) count=(count*x)%mod;
                if(p_freq[i]==2) count=(count*((x*y)/2))%mod;
                if(p_freq[i]==3) count=(count*((x*y*z)/6))%mod;
            }
        } 
        return count;

    } 
    int threeSumMulti(vector<int>& arr, int target) {
        int x;
        sort(arr.begin(),arr.end());
        vector<int> freq(101,0);
        map<pair<int,int>,int> m;
        int n=arr.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
           freq[arr[i]]++; 
        }
        for(int i=0;i<n-2;i++)
        {
            int x=target-arr[i];
            int low=i+1;
            int high=n-1;
            while(low<high)
            {
                if(arr[low]+arr[high]==x)
                {
                    if(m.find({arr[low],arr[high]})==m.end())
                    {
                     count=(count+get_count(freq,arr[i],arr[low],arr[high]))%mod;
                      m[{arr[low],arr[high]}]=1;
                    }
                     low++;
                     high--;
                }
                else if(arr[low]+arr[high]>x)
                 high--;
                else
                  low++;
            }
        }
        return count;
    }
};
