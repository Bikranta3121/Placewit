class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> alpha(26,0);
        vector<int> alpha1(26,0);
        int unique1=0;
        int unique2=0;
      for(int i=0;i<word1.size();i++)
      {
          if(!alpha[word1[i]-'a']) unique1++;
          alpha[word1[i]-'a']++;
          
      }

      for(int i=0;i<word2.size();i++)
      {
          
          if(!alpha1[word2[i]-'a']) unique2++;
           alpha1[word2[i]-'a']++;          
      }
      for(int i=0;i<26;i++)
      {
          for(int j=0;j<26;j++)
          {
              if(!alpha[i] || !alpha1[j]) continue;
              
              int x=unique1;
              int y=unique2;
              if(i!=j){
              if(alpha[j]==0) x++;
              if(alpha[i]==1) x--;
              if(alpha1[i]==0) y++;
              if(alpha1[j]==1) y--;
              }
              cout<<x<<" "<<y<<endl;
              if(x==y) return true;
          }
      }
     
       return false;

    }
};
