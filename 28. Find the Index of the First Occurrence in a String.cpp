class Solution {
public:
    int strStr(string haystack, string needle) {
      int i=0;
      int j=0;
      int n=haystack.size();
      int m=needle.size();
      while(j<=n-m)  
      {
        if(haystack[j]==needle[0])
        {            
          for(i=0;i<m;i++)
           {
              if(haystack[j+i]!=needle[i]) break;
           }
        }
        if(i==m) 
          break;
        j++;
      }
      if(i!=m) return -1;
      return j;

    }
};
