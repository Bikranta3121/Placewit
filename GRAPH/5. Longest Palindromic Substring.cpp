string longestPalindrome(string s) {
       if(s.size()<=1) return s;
       string ans;
       int len=1;

       for(int i=0;i<s.size()-2;i++)
       {
            if(s[i]==s[i+2]) 
            {
                int start=i;
                int end=i+2;
                int x=palindrome(start,end,s);
                if(x>len)
                {
                    ans=s.substr(start,end-start+1);
                    len=x;
                }
            }   
            if(s[i]==s[i+1])
            {
               int start=i;
                int end=i+1;
                int x=palindrome(start,end,s);
                if(x>len)
                {
                    ans=s.substr(start,end-start+1);
                    len=x;
                } 
            }
       }
       if(len<2 and s[s.size()-1]==s[s.size()-2]) return s.substr(s.size()-2,2);
       if(len==1) return s.substr(0,1);
       return ans;
    }
};
