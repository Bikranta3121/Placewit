class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int> m;
        for(char ch:stones)
        {
            if(m.find(ch)==m.end())
            {
                m[ch]=1;
            }
            else m[ch]++;
        } 
        int count=0;
        for(char ch:jewels)
        {
            if(m.find(ch)!=m.end())
             count+=m[ch];
        }
        return count;
    }
};
