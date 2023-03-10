class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(isalpha(s[i]))
            {
                ans.push_back(s[i]);
            }
            else
            {
                words.push_back(ans);
                ans.erase();
            }
        }
        words.push_back(ans);
        map<char,string> m;
        map<string,char>  m_1;
        if(pattern.size()!=words.size()) return false;
        for(int i=0;i<pattern.size();i++)
        {
            if(m.find(pattern[i])==m.end() and m_1.find(words[i])==m_1.end())
            {
                m[pattern[i]]=words[i];
                m_1[words[i]]=pattern[i];
            }
            else if(m.find(pattern[i])==m.end() and m_1.find(words[i])!=m_1.end()) return false;
            else if(m[pattern[i]]!=words[i]) return false;
           
        }
        return true;
    }
};
