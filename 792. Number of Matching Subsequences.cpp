class Solution {
public:
    bool check(string &s,string &a)
    {
        int i=0;
        int j=0;
        while(i<s.size() and j<a.size())
        {
            if(s[i]==a[j])
            {
                i++;
                j++;

            }
           
            else
             i++;
        }
        if(j==a.size()) return true;
        return false;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        long long int count=0;
        unordered_map<string,int> vis;
      for(auto &word : words)
      {
          if(word.size()>s.size()) continue;
          if(vis.find(word)!=vis.end()) count+=vis[word];
          else
          {
           count+=vis[word]=check(s,word);
        
          }
      }  
      return count;
    }
};
