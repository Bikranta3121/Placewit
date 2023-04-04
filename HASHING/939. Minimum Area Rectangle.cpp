class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int,unordered_set<int>> m;
				for(int i=0;i<points.size();i++)
				{
					m[points[i][0]].insert(points[i][1]);
				}
				int ans=INT_MAX;
				for(int i=0;i<points.size();i++)
				{
					for(int j=i+1;j<points.size();j++)
					{
               
							 int x1=points[i][0];
							 int y1=points[i][1];
							 int x2=points[j][0];
               int y2=points[j][1];
							 if(x1!=x2 and y1!=y2)
							 {
								 if(m[x1].find(y2)!=m[x1].end() and m[x2].find(y1)!=m[x2].end())
								   ans=min(ans,abs(x1-x2)*abs(y1-y2));
							 }
					}
				}
				if(ans==INT_MAX) return 0;
				return ans;
    }
};
