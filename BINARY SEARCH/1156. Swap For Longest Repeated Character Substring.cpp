class Solution {
public:
    bool chk(vector<int> freq_text,vector<int> freq,int k)
    {
        for(int i=0;i<26;i++)
        {
            if(freq[i]==k-1 and freq_text[i]!=0) return true;
            if(freq[i]==k) return true;
        }
        return false;
    }
    bool check(int frame,string &text)
    {
        vector<int> freq_text(26,0);
        vector<int> freq(26,0);
        int k=frame;
        int n=text.size();
        for(int i=0;i<n;i++)
        {
          freq_text[text[i]-'a']++; 
        }
        for(int i=0;i<frame;i++)
        {
            freq[text[i]-'a']++;
            freq_text[text[i]-'a']--;
        }
        if(chk(freq_text,freq,k)) return true;
        for(int i=1;i<n-k+1;i++)
        {
            freq[text[i-1]-'a']--;
            freq_text[text[i-1]-'a']++;
            freq[text[i+k-1]-'a']++;
            freq_text[text[i+k-1]-'a']--;
            if(chk(freq_text,freq,k)) return true;
        }
        return false;
        
    }
    int maxRepOpt1(string text) {
        int low=1;
        int high=text.size();
        int ans=1;
        while(low<=high)
        {
            int mid=high-(high-low)/2;
           
            if(check(mid,text))
            {
                low=mid+1;
                ans=mid;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};
