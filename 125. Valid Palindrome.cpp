class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(isalpha(s[i])) ans+=tolower(s[i]);
            else if(isdigit(s[i])) ans+=s[i];
            
        }
        int first=0;
        int last=ans.size()-1;

        while(first<last)
        {
            if(ans[first]!=ans[last]) return false;
            first++;
            last--;
        }
        return true;
    }
};
