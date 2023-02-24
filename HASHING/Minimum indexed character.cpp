class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        set<char> alpha;
        for(char ch:patt)
        {
            alpha.insert(ch);
        }
        for(int i=0;i<str.size();i++)
        {
           if(alpha.find(str[i])!=alpha.end())
             return i;
        }
        return -1;
         
    }
};
