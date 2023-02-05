class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int low=0;
        int high=0;
        vector<vector<int>> ans;
        while(low<firstList.size() and high<secondList.size())
        {
            if(firstList[low][1]<secondList[high][1] and firstList[low][1]>=secondList[high][0])
            {
                ans.push_back({max(firstList[low][0],secondList[high][0]),firstList[low][1]});
                low++;
            }
            else if(secondList[high][1]>=firstList[low][0] and firstList[low][1]>secondList[high][1])
            {
                ans.push_back({max(firstList[low][0],secondList[high][0]),secondList[high][1]});
                high++;
            }
            else if(firstList[low][1]<secondList[high][0]) low++;
            else if(firstList[low][0]>secondList[high][1]) high++;
            else if(firstList[low][1]==secondList[high][1])
            {
                ans.push_back({max(firstList[low][0],secondList[high][0]),firstList[low][1]});
                low++;
                high++;
            }
        }
        return ans;
    }
};
