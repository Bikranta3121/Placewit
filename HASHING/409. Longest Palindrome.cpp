class Solution {
public:
    int longestPalindrome(string s)
    {
       map<char,int> mp;
       int flag=0;
       for(int i=0;i<s.size();i++)
       {
        
         mp[s[i]]++;
       } 
       int max_odd=0;
       int count=0;
       for(auto itr=mp.begin();itr!=mp.end();itr++)
       {
         if(itr->second%2!=0)
         {
            flag=1;
            count+=itr->second-1;
         }
         else 
             count+=itr->second;    
       }
       if(flag) count+=1;
       return count;
    }
};
