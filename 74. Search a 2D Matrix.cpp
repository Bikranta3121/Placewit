class Solution {
public:
    bool BS(vector<vector<int>>& matrix, int target,int R,int low,int high) 
    {
        while(low<=high)
        {
         int mid=high-(high-low)/2;
         if(matrix[R][mid]==target) return true;
         else if(matrix[R][mid]>target) high=mid-1;
         else low=mid+1; 
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        unordered_set<int> ans;
        int i=0;
        int r=matrix.size();
        int c=matrix[0].size();
        int low=0;
        int high=c-1;
        while(i<r)
        {
            if(target>matrix[i][high])
              i++;
            else if(target<matrix[i][low])
             return false;  
            else  return (BS(matrix,target,i,low,high)==true);
        }
        return false;

       
        
    }
};
