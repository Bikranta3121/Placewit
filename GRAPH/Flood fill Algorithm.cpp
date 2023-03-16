  //{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    vector<int> rows{0,-1,0,1};
    vector<int> cols{-1,0,1,0};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int orgColor = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] = 1;
        image[sr][sc] = newColor;
        while(!q.empty()){
            int r = q.front().first;    
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                if(r+rows[i]<0 || r+rows[i]>=n || c+cols[i]<0 || c+cols[i]>=m) continue;
                if(!vis[r+rows[i]][c+cols[i]])
                {
                    if(image[r+rows[i]][c+cols[i]]==orgColor)
                    {
                      
                        image[r+rows[i]][c+cols[i]]=newColor;
                        q.push({r+rows[i],c+cols[i]});
                    }
                    vis[r+rows[i]][c+cols[i]]=1;
                }
            }

        }

        return image;

    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
