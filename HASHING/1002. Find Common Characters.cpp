class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        map<char,int> mp;
        for(int i=0;i<words[0].size();i++)
        {
            mp[words[0][i]]++;
        }
        
         for(int i=1;i<words.size();i++)
         {
             vector<int> freq_alpha(26,0);
             for(int j=0;j<words[i].size();j++)
             {
                freq_alpha[words[i][j]-'a']++;
             }
             for(auto itr:mp)
             {
                 char x=itr.first;
                 int y=itr.second;
                 mp[x]=min(y,freq_alpha[x-'a']);
             }

        }
        vector<string> ans;
        for(auto itr=mp.begin();itr!=mp.end();itr++)
        {
            char ch=itr->first;
            int x=itr->second;
            while(x--)
            {
                string res="";
                res+=ch;        
                ans.push_back(res);
            }
        }
        return ans;
    }
};
