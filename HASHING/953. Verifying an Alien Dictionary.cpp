class Solution {
public:
    bool check(string a,string b,vector<int> alpha)
    {
       int n_a=a.size();
       int n_b=b.size();
       int i=0,j=0;
       while(i<n_a and j<n_b)
       {
           if(alpha[a[i]-'a']<alpha[b[i]-'a']) return true;
           if(alpha[a[i]-'a'] > alpha[b[i]-'a'])
              return false;   
           i++;
           j++;           
       }
       if(n_a>n_b) return false;
       return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> alpha(26,0);
        for(int i=0;i<26;i++)
        {
            alpha[order[i]-'a']=i;
        }
        for(int i=1;i<words.size();i++)
        {
           if(!check(words[i-1],words[i],alpha)) return false;
        } 
        return true;
    }
};
