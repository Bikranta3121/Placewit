class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> m;
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]++;
        }
        unordered_set<int> s;
        for(auto itr=m.begin();itr!=m.end();itr++)
        {
             if(s.find(itr->second)==s.end()) s.insert(itr->second);
             else return false;
        }
        return true;
    }

};
