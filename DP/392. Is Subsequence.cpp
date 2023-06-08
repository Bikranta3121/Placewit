class Solution {
public:
    bool fun(int i,int j,string s,string t)
    {
        if(i<0) return true;
        if(i>=0 and j<0) return false;
        if(s[i]==t[j])
        {
            if(fun(i-1,j-1,s,t)==true) return true;
        }
        else
        {
            if(fun(i,j-1,s,t)==true) return true;
        }   
        return false; 
    }
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        while(i<s.size() and j<t.size())
        {
            if(s[i]==t[j])
            {
                i++;
            }
            j++;
        }
        if(i==s.size()) return true;
        return false;
        
    }
};
