class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
       vector<int> ans;
       int count=1;
       map<char,int> mp;
       for(int i=0;i<pattern.size();i++)
       {
         if(mp.find(pattern[i])==mp.end())
         {
             ans.push_back(count);
           
             mp[pattern[i]]=count;  count++;
         }
         else
          ans.push_back(mp[pattern[i]]);
       }
       vector<string> res;
       for(int i=0;i<words.size();i++)
       {
           map<char,int> m;
           vector<int> check;
           count=1;
           for(int j=0;j<words[i].size();j++)
           {
             if(m.find(words[i][j])==m.end())
             {
               check.push_back(count);
               
               m[words[i][j]]=count;
               count++;
             } 
             else
               check.push_back(m[words[i][j]]);
               
           }
           if(check==ans)
            res.push_back(words[i]);
       }
       return res;

    }
};
