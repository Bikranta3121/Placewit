class Solution {
public:
    bool check(vector<int> freq_words_i,vector<int> chars_freq)
    {
        for(int i=0;i<26;i++)
        {
            if(freq_words_i[i]>chars_freq[i])return false;
        }
        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
       vector<int>chars_freq(26,0);
       for(int i=0;i<chars.size();i++) 
       {
         chars_freq[chars[i]-'a']++;
       }
       int count=0;
       for(int i=0;i<words.size();i++)
       {
           vector<int> freq_word_i(26,0);
           for(char ch:words[i])
           {
             freq_word_i[ch-'a']++;
           }
           if(check(freq_word_i,chars_freq)) count+=words[i].size();
       }
       return count;
    }
};
