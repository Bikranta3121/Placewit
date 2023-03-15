class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;
        for(int i=0;i<strs.size();i++)
        {
            string a=strs[i];
            sort(a.begin(),a.end());
            m[a].push_back(strs[i]);
        }
         vector<vector<string>> res;
         for(auto itr:m)
         {
             res.push_back(itr.second);
         }
         return res;
    }
};
