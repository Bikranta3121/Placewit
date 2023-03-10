class Solution {
public:
   
    vector<int> findAnagrams(string s, string p) {
      if(s.size()<p.size()) return {};
      vector<int> ans;
      vector<int> freq_s(26,0);
      vector<int> freq_p(26,0);
      for(int i=0;i<p.size();i++)
      {
          freq_s[s[i]-'a']++;
          freq_p[p[i]-'a']++;
      }
      if(freq_s==freq_p) ans.push_back(0);
      for(int i=1;i<s.size()-p.size()+1;i++)
      {
          freq_s[s[i-1]-'a']--;
          freq_s[s[i+p.size()-1]-'a']++;
          if(freq_s==freq_p) ans.push_back(i);
      }
      return ans;
    }
};
