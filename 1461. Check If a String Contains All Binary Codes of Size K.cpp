class Solution {
public:
    bool hasAllCodes(string s, int k) {
      if(k>s.size()) return false; 
      unordered_set<string> st;
      int n=s.size();
      for(int i=0;i<n-k+1;i++)
      {
          string ans="";
         for(int j=i;j<i+k;j++)
         {
           ans+=s[j];            
         }
         st.insert(ans);
      }  
      if(st.size()==pow(2,k)) return true;
      else return false;
    }
};
